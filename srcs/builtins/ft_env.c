/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:31:28 by bjanik            #+#    #+#             */
/*   Updated: 2017/12/04 18:07:19 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

static int	env_usage(char invalid_opt)
{
	ft_putstr_fd("bsh: env: -", STDERR);
	ft_putchar_fd(invalid_opt, STDERR);
	ft_putendl_fd(": invalid option", STDERR);
	ft_putendl_fd("env: usage: env [-ui] [name[=value] ...]",
		STDERR);
	return (1);
}

static void	env_u_option(t_env *env, char **cmd, int *index)
{
	t_bsh	*bsh;
	t_env	*envvar;

	bsh = get_bsh();
	if (!bsh->mod_env)
		bsh->mod_env = mod_env(env);
	while (cmd[*index])
	{
		if ((envvar = ft_getenv(bsh->mod_env, cmd[*index])))
			envvar->exportable = 0;
		else
			break ;
		(*index)++;
	}
}

static void	env_i_option(t_env **mod_env, char **cmd, int *i)
{
	if (*mod_env)
		clear_env(mod_env);
	while (cmd[*i] && ft_strchr(cmd[*i], '='))
		set_var(mod_env, cmd[(*i)++], EXPORT_VAR);
}

static void	env_process(t_bsh *bsh, char **cmd, int *i)
{
	if (IS_OPTION(bsh->env_options, 'i'))
		env_i_option(&bsh->mod_env, cmd, i);
	else if (IS_OPTION(bsh->env_options, 'u'))
		env_u_option(bsh->env, cmd, i);
	else
	{
		(!bsh->mod_env) ? bsh->mod_env = mod_env(bsh->env) : 0;
		while (cmd[*i] && ft_strchr(cmd[*i], '='))
			set_var(&bsh->mod_env, cmd[(*i)++], EXPORT_VAR);
	}
}

int			ft_env(t_env **env, char **cmd)
{
	char	wrong_opt;
	char	options[3];
	int		i;
	t_bsh	*bsh;

	i = 0;
	bsh = get_bsh();
	ft_bzero(options, 3);
	if (cmd && (!cmd[0] || !cmd[1]))
	{
		bsh->env_index = (bsh->env_index == -1) ? 1 : bsh->env_index + 1;
		return (display_env((IS_OPTION(bsh->env_options, 'i')) ? bsh->mod_env :
						*env));
	}
	while (cmd[++i] && cmd[i][0] == '-' && ft_strcmp("--", cmd[i]))
	{
		(!cmd[i][1]) ? options[0] = 'i' : 0;
		if ((wrong_opt = check_arg_opt(cmd[i] + 1, "iu", options)))
			return (env_usage(wrong_opt));
	}
	(options[0]) ? bsh->env_options[0] = options[0] : 0;
	(options[1]) ? bsh->env_options[1] = options[1] : 0;
	env_process(bsh, cmd, &i);
	bsh->env_index = (bsh->env_index > -1) ? bsh->env_index += i : i;
	return ((!cmd[i]) ? display_env(bsh->mod_env) : 0);
}
