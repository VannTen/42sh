/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_defs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 16:41:31 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/12 18:03:43 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTREE_DEFS_H
# define BTREE_DEFS_H
# include "btree_interface.h"
# include "btree_node_interface.h"
# include "custom_stddef.h"

struct	s_btree
{
	struct s_node	*root;
	int				count;
	t_compare		f_comp;
};

#endif
