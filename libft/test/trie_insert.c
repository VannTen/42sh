/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 11:45:17 by mgautier          #+#    #+#             */
/*   Updated: 2018/03/04 12:28:02 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trie_interface.h"
#include "bool_interface.h"
#include "useful_macros.h"
#include "misc_interface.h"
#include "string_interface.h"
#include "printf.h"
#include "trie_testing.h"
#include <stddef.h>
#include <unistd.h>

static char		*g_string_set[] = {
	"ABC",
	"AB",
	"DEF",
	"DEFR",
	"XWERGH",
	"XWERVG",
	"A"
};

static t_bool	test_search(t_trie const *trie)
{
	t_bool	result;

	result = 4 == max_common_prefix(trie)
			&& ARRAY_LENGTH(g_string_set) == trie_count_members(trie);
	if (!result)
		ft_dprintf(STDERR_FILENO, "max : %zu ; count : %zu\n",
				max_common_prefix(trie), trie_count_members(trie));
	return (result);
}

int				main(void)
{
	t_trie		*trie;
	size_t		index;
	t_bool		result;

	trie = create_trie();
	index = 0;
	while (index < ARRAY_LENGTH(g_string_set))
	{
		trie_insert(trie, g_string_set[index],
				test_trie_cmp, test_trie_get_elem);
		index++;
	}
	result = test_search(trie);
	destroy_trie(&trie, no_destroy);
	RET_TEST(result);
}
