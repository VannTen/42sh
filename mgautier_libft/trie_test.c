/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 11:10:54 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/18 11:49:50 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trie_testing.h"
#include "lst_interface.h"
#include "string_interface.h"
#include <stddef.h>

t_bool		test_trie_cmp(void const *s_1, void const *s_2)
{
	if (s_1 == NULL)
		return (*(char const*)s_2 == '\0');
	else
		return (*(char const*)s_1 == *(char const*)s_2);
}

void const	*test_trie_get_elem(void const *s1, size_t index)
{
	char const *str;

	str = s1;
	return (str + index);
}

void		*test_trie_summarize(t_lst *lst, size_t length,
		__attribute__((unused))void *ext_ref)
{
	char	*new_content;

	new_content = ft_strnew(ft_strlen(get_lst_elem(lst, 0)) + 1);
	ft_strncpy(new_content, get_lst_elem(lst, 0), length);
	new_content[length] = '~';
	return (new_content);
}
