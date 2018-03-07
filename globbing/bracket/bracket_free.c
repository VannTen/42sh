/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bracket_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heynard <heynard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 12:51:04 by heynard           #+#    #+#             */
/*   Updated: 2018/01/31 12:51:06 by heynard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ft_glob.h"

void						free_biglist(t_biglist *b)
{
	t_blist					*tofree;
	t_biglist				*bigtofree;
	t_biglist				*tmpbig;
	t_blist					*tmp;

	tmpbig = b;
	while (tmpbig)
	{
		tmp = tmpbig->blist;
		while (tmp)
		{
			ft_free2dstr(tmp->r_bracket);
			tofree = tmp;
			tmp = tmp->next;
			free(tofree);
		}
		bigtofree = tmpbig;
		tmpbig = tmpbig->next;
		free(bigtofree);
	}
}
