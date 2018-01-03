/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_funcs2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 18:02:29 by bjanik            #+#    #+#             */
/*   Updated: 2017/12/04 18:03:22 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

int			size_env(t_env *env)
{
	int	size;

	size = 0;
	while (env)
	{
		size++;
		env = env->next;
	}
	return (size);
}

char		**env_to_tab(t_env *env)
{
	char	**tab;
	int		i;

	i = 0;
	tab = NULL;
	if (!(tab = (char**)malloc((size_env(env) + 1) * sizeof(char*))))
		ft_error_msg("Malloc failed\n");
	while (env)
	{
		if (env->exportable)
		{
			if (!(tab[i] = (char*)malloc(sizeof(char) *
				(ft_strlen(env->var_value) + ft_strlen(env->var_name) + 2))))
				ft_error_msg("Malloc failed\n");
			ft_strcpy(tab[i], env->var_name);
			ft_strcat(tab[i], "=");
			ft_strcat(tab[i++], env->var_value);
		}
		env = env->next;
	}
	tab[i] = NULL;
	return (tab);
}
