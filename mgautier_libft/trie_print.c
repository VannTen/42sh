/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 11:55:23 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/13 11:56:33 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trie_print_implem.h"
#include "trie_defs.h"
#include "string_interface.h"
#include "printf.h"

static void	print_intern(void const *trie, va_list args)
{
	int				fd;
	t_print	const	*print;
	int				depth;

	fd = va_arg(args, int);
	print = va_arg(args, t_print const*);
	depth = va_arg(args, int);
	print_node_intern(fd, trie, print, depth);
}

static void	print_node_intern(int const fd,
		t_trie const *trie,
		t_print const *print,
		int depth)
{
	char const	tab[] = "                                              ";

	ft_dprintf(fd, "%.*s", depth, tab);
	if (trie->children == NULL)
	{
		ft_putstr_fd("content:", fd);
		print[0](fd, trie->content.data);
	}
	else
	{
		print[1](fd, trie->content.ref);
		ft_dprintf(fd, "(%d\n", depth);
		f_lstiter_va(trie->children,
				print_intern, fd, print, depth + 1);
		ft_dprintf(fd, "%.*s )%d", depth, tab, depth);
	}
	ft_putstr_fd("\n", fd);
}

void		print_node(int const fd,
		t_trie const *trie,
		void (*print_content)(int, void const *),
		void (*print_ref)(int, void const *))
{
	t_print	print[2];

	print[0] = print_content;
	print[1] = print_ref;
	print_node_intern(fd, trie, print, 0);
}
