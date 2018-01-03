/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 17:37:17 by bjanik            #+#    #+#             */
/*   Updated: 2017/11/25 15:50:28 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

void	save_history_to_hist_file(void)
{
	t_history	*history;
	int			fd;

	history = get_bsh()->history;
	fd = open(history->hist_file, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	while (history->end)
	{
		write(fd, history->end->data, ft_strlen(history->end->data));
		write(fd, "\n", 1);
		history->end = history->end->prev;
	}
	close(fd);
}

int		ft_exit(t_env **env, char **cmd)
{
	int	exit_val;

	(void)env;
	exit_val = 0;
	if (cmd[1] && cmd[2])
		ft_putendl_fd("bsh: exit: too many arguments", STDERR);
	else if (cmd[1] && !ft_str_isdigit(cmd[1]))
	{
		ft_putendl_fd("bsh: exit: numeric argument required", STDERR);
		return (1);
	}
	if (cmd[1])
		exit_val = ft_atoi(cmd[1]);
	ft_putendl_fd("exit", STDERR);
	save_history_to_hist_file();
	restore_initial_attr(get_bsh()->term);
	exit(exit_val % 0x100);
	return (0);
}
