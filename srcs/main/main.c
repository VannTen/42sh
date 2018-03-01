/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:38:49 by bjanik            #+#    #+#             */
/*   Updated: 2018/03/01 16:58:29 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "g_builtin_array.h"
#include "execution.h"
#include "print_ast.h"
#include "parser_defs.h"

int			main(int argc, char **argv, char **environ)
{
	t_bsh	*bsh;

	set_shell_sigmode(e_shell_sigmode_shell);
	if (!(bsh = shell_init(environ, argc, argv)))
	{
		ft_dprintf(STDERR_FILENO, "42sh: Shell initialization failed\n");
		exit(EXIT_FAILURE);
	}
	(bsh->interactive) ? init_termcaps(bsh) : 0;
	sh_loop(bsh);
	return (0);
}
