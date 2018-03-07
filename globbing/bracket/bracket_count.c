/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bracket_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heynard <heynard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 12:55:59 by heynard           #+#    #+#             */
/*   Updated: 2018/01/31 12:56:00 by heynard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ft_glob.h"

static void				inner_count_blist(t_biglist *b, int *up)
{
	t_blist				*tmp;

	tmp = b->blist;
	while (tmp->tmp)
		tmp = tmp->next;
	if (b->next)
		inner_count_blist(b->next, up);
	if (*up || b->next == NULL)
	{
		tmp->tmp = 1;
		*up = 0;
	}
	if (tmp->next == NULL && tmp->tmp)
	{
		tmp = b->blist;
		while (tmp)
		{
			tmp->tmp = 0;
			tmp = tmp->next;
		}
		*up = 1;
	}
}

int						count_biglist(t_biglist *b)
{
	t_blist				*tmp;
	int					up;
	size_t				nbhit;

	up = 0;
	nbhit = 0;
	tmp = b->blist;
	while (tmp)
	{
		nbhit++;
		if (b->next)
			inner_count_blist(b->next, &up);
		else
			up = 1;
		if (up)
		{
			tmp = tmp->next;
			up = 0;
		}
	}
	return (nbhit);
}
