/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_compute_first.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 17:17:36 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/10 22:01:17 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_interface.h"
#include "test_interface.h"
#include "libft.h"

static char const	*g_str_symbol[] = {
	"SYM: A B C"
		"| D E F"
		"| G H U",
	"A: Z X W"
		"| T U R"
		"| S L M"
		"|",
	"B: NN KY | KO WT",
	"Z: IF ELSE | OR PER |",
	"X: XXX ZZZ | FFF LLL",
	"NN: FR |",
	"KY: EN |",

};

static char const	*g_str_first_set[] = {
	"T S IF OR XXX FFF G FR EN KO C D",
		"IF OR XXX FFF EMPTY T S",
		"FR EN EMPTY KO",
		"IF OR EMPTY",
		"XXX FFF",
		"FR EMPTY",
		"EN EMPTY"
};

static void		compute_tokens_first(void *token)
{
	t_bool	dummy_check;

	compute_sym_first_set(token, &dummy_check);
}

static void		destroy_first_sets(t_lst ***first_sets, size_t size)
{
	size_t	index;
	t_lst	**lst;

	index = 0;
	lst = *first_sets;
	while (index < size)
	{
		f_lstdel(&lst[index], ft_gen_strdel);
		index++;
	}
	free(lst);
	*first_sets = NULL;
}

static t_lst	**str_to_first_set(char const **array, size_t nb_sym)
{
	t_lst	**first_sets;
	char	**first_set;
	size_t	index;

	index = 0;
	first_sets = malloc(sizeof(t_lst*) * nb_sym);
	if (first_sets != NULL)
	{
		while (index < nb_sym)
		{
			first_set = ft_strsplit(array[index], ' ');
			if (first_set == NULL)
				break ;
			first_sets[index] = array_to_lst(first_set);
			free(first_set);
			index++;
		}
		if (index < nb_sym)
			destroy_first_sets(&first_sets, nb_sym - index);
	}
	return (first_sets);
}

static t_bool	test_compute_first(__attribute__((unused))t_prod **prods,
		t_symbol **syms, ...)
{
	t_bool		result;
	t_fifo		*tokens;
	va_list		args;
	size_t		nb_symbol;
	t_lst		**first_sets_comparison;

	va_start(args, syms);
	(void)va_arg(args, t_fifo*);
	tokens = va_arg(args, t_fifo*);
	(void)va_arg(args, size_t);
	nb_symbol = va_arg(args, size_t);
	va_end(args);
	first_sets_comparison = str_to_first_set(g_str_first_set, nb_symbol);
	f_fifoiter(tokens, compute_tokens_first);
	result = compute_first_sets(syms, nb_symbol)
		&& check_first_sets(syms, first_sets_comparison, nb_symbol);
	destroy_first_sets(&first_sets_comparison, nb_symbol);
	return (result);
}

int	main(void)
{
	RET_TEST(test_sym_prod(g_str_symbol, 0, ARRAY_LENGTH(g_str_symbol),
				test_compute_first));
}
