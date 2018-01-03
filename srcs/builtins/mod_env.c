/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:55:53 by bjanik            #+#    #+#             */
/*   Updated: 2017/11/23 18:40:33 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

static t_env	*copy_content(t_env *env)
{
	t_env	*mod_env;

	if (!(mod_env = (t_env*)malloc(sizeof(t_env))))
		ft_error_msg("Malloc failed\n");
	if (!(mod_env->var_name = ft_strdup(env->var_name)))
		ft_error_msg("Malloc failed\n");
	if (!(mod_env->var_value = ft_strdup(env->var_value)))
		ft_error_msg("Malloc failed\n");
	mod_env->exportable = env->exportable;
	mod_env->next = NULL;
	return (mod_env);
}

t_env			*mod_env(t_env *env)
{
	t_env	*modif_env[2];

	modif_env[0] = NULL;
	modif_env[1] = NULL;
	while (env)
	{
		if (!modif_env[0])
		{
			modif_env[0] = copy_content(env);
			modif_env[1] = modif_env[0];
		}
		else
		{
			modif_env[1]->next = copy_content(env);
			modif_env[1] = modif_env[1]->next;
		}
		env = env->next;
	}
	return (modif_env[0]);
}
