/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_print_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 12:26:17 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/08 11:56:10 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar_defs.h"
#include "sym_interface.h"
#include "libft.h"

static void	print_symbol_init(t_symbol const *symbol,
		int const file, const char *prefix)
{
	char	*name;

	name = ft_strmap(get_name(symbol), f_tolower);
	ft_dprintf(file, "%s%s, ", prefix, name);
}

static void	adapt_print(void const *symbol, va_list args)
{
	int			fd;
	const char	*prefix;

	fd = va_arg(args, int);
	prefix = va_arg(args, const char*);
	print_symbol_init(symbol, fd, prefix);
}

void		print_grammar_init(t_grammar const *grammar, int const file,
		__attribute__((unused))char const *header_proto_name)
{
	print_grammar_source(grammar, file, NULL);
	ft_dprintf(file,
			"\nt_symbol\t\t**create_%s_grammar(void)\n{\n"
			"\tt_symbol\t**grammar;\n"
			"\tsize_t\t\tindex;\n"
			"\tt_symbol\t*(*init_func[])(void) = {", grammar->name);
	f_fifoiter_va(grammar->sym_list, adapt_print, file, "create_");
	ft_dprintf(file, "NULL};\n\n"
			"\tindex = 0;\n"
			"\tgrammar = malloc(sizeof(t_symbol*) * NB_SYMBOLS);\n"
			"\twhile (index < NB_SYMBOLS)\n"
			"\t{\n"
			"\t\tgrammar[index] = init_func[index]();\n"
			"\t\tindex++;\n"
			"\t}\n"
			"\treturn (grammar);\n}\n");
}
