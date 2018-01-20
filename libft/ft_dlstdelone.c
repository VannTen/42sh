/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 15:55:22 by bjanik            #+#    #+#             */
/*   Updated: 2017/10/16 16:19:14 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstdelone(t_dlst **alst, void (*del)(void *, size_t))
{
	if (alst != NULL && *alst != NULL && del != NULL)
	{
		del((*alst)->data, (*alst)->data_size);
		if ((*alst)->prev != NULL)
			(*alst)->prev->next = NULL;
		*alst = NULL;
	}
}
