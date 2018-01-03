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

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (alst != NULL && *alst == NULL)
		*alst = new;
	else if (alst != NULL && *alst != NULL && new != NULL)
	{
		new->next = *alst;
		*alst = new;
	}
}
