/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 13:37:20 by bjanik            #+#    #+#             */
/*   Updated: 2016/11/09 10:32:06 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libbj.h"

void	ft_dlstadd(t_dlst **alst, t_dlst *new)
{
	if (alst != NULL && *alst == NULL)
		*alst = new;
	else if (alst != NULL && *alst != NULL && new != NULL)
	{
		new->next = *alst;
		new->prev = NULL;
		(*alst)->prev = new;
		*alst = new;
	}
}
