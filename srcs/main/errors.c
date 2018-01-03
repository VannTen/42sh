/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 17:27:28 by bjanik            #+#    #+#             */
/*   Updated: 2017/10/24 21:10:08 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

int		ft_perm_denied_msg(char *file)
{
	ft_putstr_fd("bsh: ", STDERR);
	ft_putstr_fd(file, STDERR);
	ft_putendl_fd(": Permission denied", STDERR);
	return (1);
}

int		ft_no_file_msg(char *file)
{
	ft_putstr_fd("bsh: ", STDERR);
	ft_putstr_fd(file, STDERR);
	ft_putendl_fd(": No such file or directory", STDERR);
	return (1);
}

int		ft_cmd_not_found(char *cmd)
{
	ft_putstr_fd("bsh: ", STDERR);
	ft_putstr_fd(cmd, STDERR);
	ft_putendl_fd(": command not found...", STDERR);
	return (1);
}

int		ft_is_directory(char *file)
{
	ft_putstr_fd("bsh: ", STDERR);
	ft_putstr_fd(file, STDERR);
	ft_putendl_fd(": Is a directory", STDERR);
	return (1);
}
