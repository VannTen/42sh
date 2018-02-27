/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_print_implem.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:07:44 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/12 17:08:52 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIE_PRINT_IMPLEM_H
# define TRIE_PRINT_IMPLEM_H
# include "trie_interface.h"
# include "useful_macros.h"

static void	print_node_intern(int const fd,
		t_trie const *trie,
		t_print const *print,
		int depth);

#endif
