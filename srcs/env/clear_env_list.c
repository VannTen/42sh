/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 11:17:55 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/15 13:18:11 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"
#include <stdlib.h>

void	clear_env_list(t_env_list **env_list_loc)
{
	t_env_list	*todel;
	t_env_list	*env_list;

	if (env_list_loc)
	{
		env_list = *env_list_loc;
		while (env_list)
		{
			todel = env_list;
			env_list = env_list->next;
			ft_strdel(&todel->name);
			ft_strdel(&todel->value);
			free(todel);
		}
		*env_list_loc = NULL;
	}
}
