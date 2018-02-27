/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 19:47:56 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/21 16:21:45 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_defs.h"
#include "prods_interface.h"
#include "libft.h"

static void	print_prods(void const *prod, size_t index, va_list args)
{
	int	fd;

	fd = va_arg(args, int);
		ft_dprintf(fd, "\t\t\tnew->productions[%zu]"
				" = generate_one_production(%zu, ",
				index, get_prod_len(prod));
		print_prod(prod, fd);
		ft_putstr_fd(");\n", fd);
}

static void	print_prod_list(t_symbol const *sym, int const fd, size_t nb_prod)
{
	ft_dprintf(fd,
			"\t\tnew->productions = malloc(sizeof(t_symbol_type*)"
			" * (%1$zu + 1));\n"
			"\t\tif (new->productions != NULL)\n\t\t{\n"
			, nb_prod);
	f_lstiteri_va(sym->prods, print_prods, fd);
	ft_dprintf(fd, "\t\t\tnew->productions[%zu] = NULL;\n\t\t}\n"
			"\t\telse\n\t\t\tdestroy_symbol(&new);\n", nb_prod);
}

void		print_sym_initializer(t_symbol const *sym, int const fd)
{
	const char	type_name[]	= "t_symbol";
	char		*lower_case;
	size_t		nb_prod;

	nb_prod = sym->prods == NULL ?
		0 : f_lst_len(sym->prods);
	lower_case = ft_strmap(sym->name, f_tolower);
	ft_dprintf(fd, "\nstatic %1$s\t*create_%2$s(void)\n{\n"
			"\t%1$s\t*new;\n"
			"\n"
			"\tnew = malloc(sizeof(t_symbol));\n"
			"\tif (new != NULL)\n\t{\n"
			"\t\tnew->type = %3$s;\n", type_name, lower_case, sym->name);
	if (nb_prod == 0)
		ft_dprintf(fd, "\t\tnew->productions = NULL;\n");
	else
		print_prod_list(sym, fd, nb_prod);
	ft_strdel(&lower_case);
	ft_dprintf(fd, "\t}\n\treturn (new);\n}\n");
}
