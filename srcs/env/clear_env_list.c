/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 11:17:55 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/15 11:24:01 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	clear_env_list(t_env_list **env_list)
{
	t_env_list	*ptr;

	if (env_list)
	{
		ptr = *env_list;
		while (*env_list)
		{
			ptr = ptr->next;
			ft_strdel(&env_list->name);
			ft_strdel(&env_list->value);
			ft_memdel((void**)env_list);
			*env_list = ptr;
		}
	}
}
