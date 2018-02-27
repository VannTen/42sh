/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_grammar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 10:34:57 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/08 11:36:48 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar_generator.h"
#include "grammar_interface.h"
#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/*
** This small programm has for purpose to generate C files which will initialize
** a grammar (that is, a numerical representation of it) corresponding to the
** parameter given to the programm, such as :
** The first paramater is the grammar file : it shall contained one grammar
** symbol per lines. Symbols names regex : [A-Z_]+.
** Non terminals symbol shall have any number of blank characters (tab and
** spaces following, then a colon, followed by the list of their
** productions.
** Those consists of symbols name separated by spaces or tabs.
** The body of two distincts productions shall be separated by a '|'.
** Finally, every symbols definition (name + productions) shall be followed by
** a semi-colon.
**
** The second paramater shall be a header name, which will hold an enum with all
** the symbols name, and C prototypes for the initialisation functions for each
** symbols.
** The third parameter shall be the C file containing the body of each of these
** functions.
**
** (The fourth paramater might serve in the future for the generated makefile)
*/


static	int	print_each_file(t_grammar const *grammar, char **final_names)
{
	size_t	index;
	void (*const	print[])(t_grammar const*, int, char const*) = {
		print_grammar_init, print_grammar_names, print_grammar_header};
	size_t const	t_index[] = {0, 2, 2};
	int				fd;

	index = 0;
	while (index < ARRAY_LENGTH(print))
	{
		fd = open(final_names[index], O_WRONLY | O_TRUNC | O_CREAT,
				CODE_FILE_PERMISSION);
		if (fd == -1)
			return (FAIL_TO_WRITE_FILE);
		print[index](grammar, fd , final_names[t_index[index]]);
		close(fd);
		index++;
	}
	return (SUCCESS);
}

int			print_grammar(t_grammar const *grammar, char const *gram_name,
		char const *header_dir, char const *src_dir)
{
	char const		*names[] = {
		"init.c", "names.c", "sym_list.h"};
	char			*total_names[ARRAY_LENGTH(names)];
	size_t			index;
	int				ret;

	index = 0;
	while (index < ARRAY_LENGTH(names))
	{
		total_names[index] = ft_strvajoin(4,
				last_char_of(names[index]) == 'h' ? header_dir : src_dir,
				gram_name, "_", names[index]);
		index++;
	}
	ret = print_each_file(grammar, total_names);
	index = 0;
	while (index < ARRAY_LENGTH(names))
	{
		ft_strdel(&total_names[index]);
		index++;
	}
	return (ret);
}

int		main(int argc, const char **argv)
{
	t_grammar	*grammar;
	char		*stem;

	if (argc < 2 || argc > 4)
		return (EXIT_FAILURE);
	grammar = parse_grammar(argv[1]);
	stem = basename(argv[1]);
	if (grammar != NULL && stem != NULL)
	{
		print_grammar(grammar, stem,
				argc > 2 ? argv[2] : "",
				argc > 3 ? argv[3] : "");
	}
	else
		return (EXIT_FAILURE);
	ft_strdel(&stem);
	destroy_grammar(&grammar);
	return (EXIT_SUCCESS);
}
