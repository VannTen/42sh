/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 11:45:03 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/04 15:02:46 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar_defs.h"
#include "sym_interface.h"
#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <assert.h>

static t_bool	is_empty(char const *sym_def)
{
	size_t	index;

	index = 0;
	while (sym_def[index] == '\n' || sym_def[index] == ' ')
		index++;
	return (sym_def[index] == '\0');
}

static t_bool	sym_parse(void *str, va_list args)
{
	t_grammar	*gram;

	gram = va_arg(args, t_grammar*);
	return (NULL !=
			parse_symbol(str, gram->sym_list, gram->tokens_list));
}

t_grammar		*parse_grammar_file(const char *grammar_file)
{
	int			fd;
	t_grammar	*new_gram;

	assert(grammar_file != NULL);
	fd = open(grammar_file, O_RDONLY);
	new_gram = parse_grammar_fd(fd);
	close(fd);
	return (new_gram);
}

t_grammar		*parse_grammar_fd(int const gram_fd)
{
	t_grammar	*new_gram;
	t_lst		*sym_defs;

	assert(gram_fd >= 0 && -1 != read(gram_fd, NULL, 0));
	new_gram = create_grammar();
	sym_defs = get_no_empty_elem_list(gram_fd, ';', is_empty);
	if (new_gram == NULL
			|| sym_defs == NULL
			|| !f_lstiterr_va(sym_defs, sym_parse, new_gram))
		destroy_grammar(&new_gram);
	f_lstdel(&sym_defs, ft_gen_strdel);
	close(gram_fd);
	new_gram->start_symbol = (void*)get_fifo_elem(new_gram->sym_list, 0);
	return (new_gram);
}

t_grammar		*parse_grammar_string(char const *string)
{
	t_grammar	*new_gram;
	t_lst		*list;

	assert(string != NULL);
	list = f_strsplit_lst_mod(string, ";", TRUE);
	if (list != NULL)
	{
		new_gram = create_grammar();
		if (!f_lstiterr_va(list, sym_parse, new_gram))
			destroy_grammar(&new_gram);
	}
	else
		new_gram = NULL;
	f_lstdel(&list, ft_gen_strdel);
	new_gram->start_symbol = (void*)get_fifo_elem(new_gram->sym_list, 0);
	return (new_gram);
}
