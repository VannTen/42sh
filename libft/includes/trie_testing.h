/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_testing.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 11:07:19 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/18 11:50:28 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIE_TESTING_H
# define TRIE_TESTING_H
# include "lst_interface.h"
# include <stddef.h>

/*
** Test function pointers for trie testing
** Implementation file : trie_test.c
*/

t_bool		test_trie_cmp(void const *s1, void const *s_2);
void const	*test_trie_get_elem(void const *s1, size_t index);
void		*test_trie_summarize(t_lst *lst, size_t length,
		void *ext_ref);

#endif
