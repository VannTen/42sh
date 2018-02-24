/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exit_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 12:33:01 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/24 15:02:34 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	sh_no_such_file_or_directory(const char *file)
{
	dprintf(STDERR_FILENO, "42sh: %s: No such file or directory\n", file);
	exit(NO_SUCH_FILE_DIRECTORY);
}

void	sh_permission_denied(const char *file)
{
	dprintf(STDERR_FILENO, "42sh: %s: Permission denied\n", file);
	exit(PERMISSION_DENIED);
}

void	sh_is_a_directory(const char *file)
{
	dprintf(STDERR_FILENO, "42sh: %s: Is a directory\n", file);
	exit(IS_DIRECTORY);
}

void	sh_opening_failed(const char *file)
{
	dprintf(STDERR_FILENO, "42sh: Opening of %s failed...\n", file);
	exit(EXIT_FAILURE);
}

void	sh_exit_message(const char *error_message)
{
	dprintf(STDERR_FILENO, error_message);
	exit(EXIT_FAILURE);
}
