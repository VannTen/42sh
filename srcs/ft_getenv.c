/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:54:53 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/15 12:39:39 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

/*
** Function searches in the environment if a variable equals to NAME exists.
** If it does, then the function returns a pointer to the structure containing
** its name and value. Otherwise , returns NULL.
*/
t_env_list	*ft_getenv(t_env_list *env_list, char const *const name)
{
	while (env_list)
	{
		if (!ft_strcmp(env_list->name, name))
			return (env_list);
		env_list = env_list->next;
	}
	return (NULL);
}
