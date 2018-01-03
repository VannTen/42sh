/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 18:27:24 by bjanik            #+#    #+#             */
/*   Updated: 2017/11/27 16:47:11 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

int	ft_echo(t_env **env, char **cmd)
{
	int	new_line;
	int	i;

	(void)env;
	new_line = 1;
	i = 1;
	if (cmd[1] && !ft_strcmp("-n", cmd[1]))
	{
		new_line = 0;
		i++;
	}
	while (cmd[i])
	{
		ft_putstr(cmd[i++]);
		if (cmd[i])
			ft_putchar(' ');
	}
	(new_line) ? ft_putchar('\n') : 0;
	return (0);
}
