/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bracket_list_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heynard <heynard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 16:38:48 by heynard           #+#    #+#             */
/*   Updated: 2018/02/11 16:38:49 by heynard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ft_glob.h"

t_blist					*add_blist(t_biglist *b, t_blist *n)
{
	t_blist				*tmp;

	tmp = b->blist;
	n->tmp = 0;
	if (tmp == NULL)
		return (n);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = n;
	return (b->blist);
}

t_biglist				*add_biglist(t_bracket *bracket, t_biglist *n)
{
	t_biglist			*tmp;

	tmp = bracket->biglist;
	if (tmp == NULL)
		return (n);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = n;
	return (bracket->biglist);
}
