/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_node_interface.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 10:12:46 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/09 15:21:27 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTREE_NODE_INTERFACE_H
# define BTREE_NODE_INTERFACE_H
# include "custom_stddef.h"

struct s_node;

/*
** Ressourcs management
** Implementation file : ft_tree_node_ressources.c
*/

void			node_destroy(struct s_node **to_destroy, t_destroy destructor);
struct s_node	*node_create(void);

/*
** Tree insertion
** Implementation file : ft_tree_node_insert.c
*/

const void		*insert_node(struct s_node *node, const void *content,
		t_compare comp);
struct s_node	*insert_root(const void *content);
/*
** Tree traversal
** Implementation file : ft_tree_node_traversal.c
*/

void			node_in_order_traversal(struct s_node *node, t_iter f);
void			node_in_rev_order_traversal(struct s_node *node, t_iter f);
void			node_in_order_two_param_traversal(struct s_node *node,
		t_iter_two f, void *param_supp);
void			node_in_rev_order_two_param_traversal(struct s_node *node,
		t_iter_two f, void *param_supp);

/*
** Tree count : arithmetic operations on each node of the tree.
** Implementation file : ft_tree_node_count.c
*/

int				node_sum(struct s_node *node, t_sum add);
#endif
