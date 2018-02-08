/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 16:09:34 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/28 13:54:30 by bjanik           ###   ########.fr       */
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

static void	update_shlvl(t_env *env)
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

t_bsh		*get_shell_data(void)
{
	static t_bsh	*bsh = NULL;

	if (bsh == NULL)
		if (!(bsh = init_data()))
			return (NULL);
	return (bsh);
}

t_bsh		*shell_init(char **environ)
{
	t_bsh	*bsh;

	if (!(bsh = get_shell_data()))
		return (NULL);
	if (init_env(&bsh->env, environ) == MALLOC_FAIL)
		return (NULL);
	update_shlvl(&bsh->env);
	if (!ft_getenv(bsh->env.env_list, "TERM"))
		if (append_variable_to_env(&bsh->env, "TERM", "xterm", GLOBAL))
			return (NULL);
	return (bsh);
}
