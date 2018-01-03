/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 14:47:08 by bjanik            #+#    #+#             */
/*   Updated: 2017/11/23 19:19:37 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

const t_builtins	g_builtins[] = {
	{"cd", ft_cd},
	{"echo", ft_echo},
	{"env", ft_env},
	{"setenv", ft_setenv},
	{"unsetenv", ft_unsetenv},
	{"export", ft_export},
	{"history", ft_history},
	{"exit", ft_exit},
	{NULL, NULL},
};

int			cmd_is_builtin(char **cmd)
{
	int		i;

	i = -1;
	while (cmd && g_builtins[++i].b_name)
	{
		if (!ft_strcmp(g_builtins[i].b_name, cmd[0]))
			return (i);
	}
	return (-1);
}
