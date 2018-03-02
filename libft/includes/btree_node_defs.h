/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_node_defs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 10:11:33 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/29 10:16:33 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTREE_NODE_DEFS_H
# define BTREE_NODE_DEFS_H
# include "btree_node_interface.h"

struct	s_node
{
	void			*content;
	struct s_node	*left;
	struct s_node	*right;
};

#endif
