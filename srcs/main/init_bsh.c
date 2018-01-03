/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bsh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 14:35:23 by bjanik            #+#    #+#             */
/*   Updated: 2017/12/21 14:56:21 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

static t_bsh		*init_bsh(void)
{
	t_bsh			*bsh;

	if (!(bsh = (t_bsh*)malloc(sizeof(t_bsh))))
		ft_error_msg("Malloc failed");
	bsh->term = init_term();
	bsh->history = init_history();
	bsh->input = init_input(bsh->term, bsh->history);
	bsh->lexer = init_lexer(NULL, INIT);
	bsh->parser = NULL;
	bsh->exec = NULL;
	bsh->tokens[0] = NULL;
	bsh->tokens[1] = NULL;
	bsh->pipes = init_pipes();
	bsh->pid = getpid();
	bsh->exit_status = 0;
	bsh->shell_name = "-bsh";
	bsh->env_index = -1;
	return (bsh);
}

static void			update_shlvl(t_env **env)
{
	t_env	*shlvl;
	char	*tmp;

	if (!(shlvl = ft_getenv(*env, "SHLVL")))
		set_var(env, "SHLVL=1", EXPORT_VAR);
	else
	{
		tmp = shlvl->var_value;
		shlvl->var_value = ft_itoa(ft_atoi(tmp) + 1);
		free(tmp);
	}
}

static void			update_shell_name(t_env **env)
{
	t_env	*shell_name;
	char	*tmp;

	if (!(shell_name = ft_getenv(*env, "SHELL")))
		set_var(env, "SHELL=-bsh", EXPORT_VAR);
	else
	{
		tmp = shell_name->var_value;
		shell_name->var_value = ft_strdup("-bsh");
		free(tmp);
	}
}

t_bsh				*get_bsh(void)
{
	static t_bsh	*bsh = NULL;

	if (!bsh)
		bsh = init_bsh();
	return (bsh);
}

t_bsh				*shell_init(char **environ)
{
	t_bsh	*bsh;

	bsh = get_bsh();
	bsh->env = env_to_lst(environ);
	bsh->mod_env = NULL;
	bsh->exp = init_expander(bsh->env);
	update_shlvl(&bsh->env);
	update_shell_name(&bsh->env);
	if (!ft_getenv(bsh->env, "TERM"))
		set_var(&bsh->env, "TERM=xterm", LOCAL_VAR);
	set_signals();
	return (bsh);
}
