/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 16:09:34 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/23 18:58:26 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static t_bsh	*init_data(void)
{
	t_bsh	*bsh;

	if (!(bsh = (t_bsh*)malloc(sizeof(t_bsh))))
		return (NULL);
	if (init_lexer(&bsh->lexer) == MALLOC_FAIL
			|| init_history(&bsh->history, DEFAULT_HISTSIZE) == MALLOC_FAIL
			|| init_term(&bsh->term) == MALLOC_FAIL
			|| init_input(&bsh->input, &bsh->term,
				&bsh->history) == MALLOC_FAIL)
		return (NULL);
	return (bsh);
}

static void		update_shlvl(t_env *env)
{
	t_env_list	*shlvl;
	char		*tmp;

	if (!(shlvl = ft_getenv(env->env_list, "SHLVL")))
		append_variable_to_env(env, "SHLVL", "1", GLOBAL);
	else
	{
		tmp = shlvl->value;
		shlvl->value = ft_itoa(ft_atoi(tmp) + 1);
		free(tmp);
	}
}

t_bsh			*get_shell_data(void)
{
	static t_bsh	*bsh = NULL;

	if (bsh == NULL)
		if (!(bsh = init_data()))
			return (NULL);
	return (bsh);
}

static int	is_argument_valid(t_input *input, char *arg)
{
	struct stat	info;

	if (access(arg, F_OK))
	{
		dprintf(STDERR_FILENO, "42sh: %s: No such file or directory\n", arg);
		exit(EXIT_FAILURE);
	}
	else if (access(arg, R_OK))
	{
		dprintf(STDERR_FILENO, "42sh: %s: Permission denied\n", arg);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (stat(arg, &info) < 0)
		{
			dprintf(STDERR_FILENO, "42sh: stat failed\n", arg);
			exit(EXIT_FAILURE);
		}
		if (S_ISDIR(info.st_mode))
		{
			dprintf(STDERR_FILENO, "42sh: %s: is a directory\n", arg);
			exit(EXIT_FAILURE);
		}
		input->fd = open(arg, O_RDONLY, 0644);
		if (input->fd < 0)
		{
			dprintf(STDERR_FILENO, "42sh: Opening of %s failed...\n", arg);
			exit(EXIT_FAILURE);
		}
		return (1);
	}
	return (0);
}

t_bsh			*shell_init(char **environ, int argc, char **argv)
{
	t_bsh		*bsh;
	struct stat	info;

	if (!(bsh = get_shell_data()))
		return (NULL);
	if (init_env(&bsh->env, environ) == MALLOC_FAIL)
		return (NULL);
	update_shlvl(&bsh->env);
	if (!ft_getenv(bsh->env.env_list, "TERM"))
		if (append_variable_to_env(&bsh->env, "TERM", "xterm", GLOBAL))
			return (NULL);
	bsh->interactive = (argc > 1 || !isatty(STDIN_FILENO)) ? 0 : 1;
	if (!bsh->interactive && argc == 1)
	{
		if (fstat(STDIN_FILENO, &info) < 0)
		{
			dprintf(STDERR_FILENO, "42sh: fstat failed\n");
			exit(EXIT_FAILURE);
		}
		if (S_ISDIR(info.st_mode))
		{
			dprintf(STDERR_FILENO, "42sh: stdin: Is a directory\n");
			exit(EXIT_FAILURE);
		}
	}
	if (argc > 1)
		is_argument_valid(&bsh->input, argv[1]);
	return (bsh);
}
