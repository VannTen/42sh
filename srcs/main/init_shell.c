/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 16:09:34 by bjanik            #+#    #+#             */
/*   Updated: 2018/03/14 16:38:33 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static t_bsh	*init_data(void)
{
	t_bsh	*bsh;

	if (!(bsh = (t_bsh*)malloc(sizeof(t_bsh))))
		return (NULL);
	init_hash_table(&bsh->hashtable);
	if (init_lexer(&bsh->lexer) == MALLOC_FAIL
			|| init_history(&bsh->history, DEFAULT_HISTSIZE) == MALLOC_FAIL
			|| init_term(&bsh->term) == MALLOC_FAIL
			|| init_input(&bsh->input, &bsh->term,
				&bsh->history) == MALLOC_FAIL)
		return (NULL);
	if (!(bsh->parser = generate_parser(g_shell_grammar, g_tokens_name,
					g_exec_rules, get_tok_id)))
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

static int		is_file_valid(t_input *input, const char *file)
{
	struct stat	info;

	if (access(file, F_OK))
		sh_no_such_file_or_directory(file);
	else if (access(file, R_OK))
		sh_permission_denied(file);
	else
	{
		if (stat(file, &info) < 0)
			sh_exit_message("42sh: stat failed\n");
		if (S_ISDIR(info.st_mode))
			sh_is_a_directory(file);
		if ((input->fd = open(file, O_RDONLY, 0644)) < 0)
			sh_opening_failed(file);
		return (1);
	}
	return (0);
}

t_bsh			*get_shell_data(void)
{
	static t_bsh	*bsh = NULL;

	if (bsh == NULL)
		if (!(bsh = init_data()))
			return (NULL);
	return (bsh);
}

t_bsh			*shell_init(char **envir, int argc, char **argv)
{
	t_bsh		*bsh;
	struct stat	info;

	if (!(bsh = get_shell_data()) || init_env(&bsh->env, envir) == MALLOC_FAIL)
		return (NULL);
	update_shlvl(&bsh->env);
	if (!ft_getenv(bsh->env.env_list, "PATH"))
		if (append_variable_to_env(&bsh->env, "PATH", "/bin:/usr/bin", LOCAL))
			return (NULL);
	if (!ft_getenv(bsh->env.env_list, "TERM"))
		if (append_variable_to_env(&bsh->env, "TERM", "xterm", LOCAL))
			return (NULL);
	if (init_expander(&bsh->exp) == MALLOC_FAIL)
		return (NULL);
	bsh->interactive = (argc > 1 || !isatty(STDIN_FILENO)) ? 0 : 1;
	if (!bsh->interactive && argc == 1)
	{
		if (fstat(STDIN_FILENO, &info) < 0)
			sh_exit_message("42sh: failed to retrieve STDIN status");
		if (S_ISDIR(info.st_mode))
			sh_exit_message("42sh: stdin: Is a directory");
	}
	if (argc > 1)
		is_file_valid(&bsh->input, argv[1]);
	return (bsh);
}
