/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_list_prefix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 13:01:50 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/18 11:21:52 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trie_interface.h"
#include "bool_interface.h"
#include "useful_macros.h"
#include "string_interface.h"
#include "lst_interface.h"
#include "misc_interface.h"
#include "printf.h"
#include "trie_testing.h"
#include <stddef.h>
#include <unistd.h>

static t_bool	is_that_prefix(void const *content, va_list args)
{
	char const *prefix;

	prefix = va_arg(args, char const *);
	return (ft_strncmp(
				get_lst_elem(content, 0), prefix, ft_strlen(prefix)) == 0);
}

static t_bool	test_list_prefix_group(t_trie const *trie)
{
	t_lst				*prefix_groups;
	size_t const		nb[] = {2, 2, 2, 2, 4};
	char const			*prefix[] = {"AB", "A", "DEF", "XWER", ""};
	size_t				index;
	t_trie_ope const	ope =
	{test_trie_summarize, ft_gen_strdup, ft_gen_strdel, NULL};
	prefix_groups = list_prefix_groups(trie, &ope);
	if (!(f_lst_len(prefix_groups) == 5))
	{
		ft_dprintf(STDERR_FILENO, "\nnb groups : %u\n",
				f_lst_len(prefix_groups));
		return (FALSE);
	}
	index = 0;
	while (index < ARRAY_LENGTH(prefix)
			&& f_lst_len(f_lst_every_valid_va(prefix_groups,
					FALSE, is_that_prefix, prefix[index])) == nb[index])
		index++;
	if (index < ARRAY_LENGTH(prefix))
	{
		ft_dprintf(STDERR_FILENO, "\n%s\n", prefix[index]);
		f_lstiter_va(f_lst_every_valid_va(prefix_groups, FALSE, is_that_prefix,
					prefix[index]), ft_putstr_fd_sep_gen, STDERR_FILENO, ";");
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	return (!(index < ARRAY_LENGTH(prefix)));
}

int				main(void)
{
	t_trie		*trie;
	size_t		index;
	t_bool		result;
	static char	*string_set[] = {
		"ABC",
		"AB",
		"DEF",
		"DEFR",
		"XWERGH",
		"XWERVG",
		"A",
		""
	};

	trie = create_trie();
	index = 0;
	while (index < ARRAY_LENGTH(string_set))
	{
		trie_insert(trie, string_set[index], test_trie_cmp, test_trie_get_elem);
		index++;
	}
	result = test_list_prefix_group(trie);
	destroy_trie(&trie, no_destroy);
	RET_TEST(result);
}
