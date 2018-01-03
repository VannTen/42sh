/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 18:43:22 by bjanik            #+#    #+#             */
/*   Updated: 2017/12/08 17:24:43 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

static void	get_process_pid(t_expander *exp)
{
	char	*s;

	if (!(s = ft_itoa(get_bsh()->pid)))
		ft_error_msg("Itoa failed\n");
	exp->buffer_len += ft_strlen(s);
	if (exp->buffer_len >= exp->buffer_size)
		realloc_exp_buffer(exp);
	ft_strcat(exp->buffer, s);
	free(s);
	exp->tmp++;
}

static void	get_exit_status(t_expander *exp)
{
	char	*s;

	if (!(s = ft_itoa(get_bsh()->exit_status)))
		ft_error_msg("Itoa failed\n");
	exp->buffer_len += ft_strlen(s);
	if (exp->buffer_len >= exp->buffer_size)
		realloc_exp_buffer(exp);
	ft_strcat(exp->buffer, s);
	free(s);
	exp->tmp++;
}

static void	get_shell_name(t_expander *exp)
{
	ft_strcat(exp->buffer, get_bsh()->shell_name);
	exp->buffer_len += 4;
	if (exp->buffer_len >= exp->buffer_size)
		realloc_exp_buffer(exp);
	exp->tmp++;
}

static void	get_env_variable(t_expander *exp, char *s)
{
	t_env	*env_var;
	int		len;

	len = 0;
	while (ft_isdigit(*(s + len)) || ft_isalpha(*(s + len)) ||
			*(s + len) == '_')
		len++;
	if (!len)
	{
		exp->buffer[exp->buffer_len++] = *(s - 1);
		return ;
	}
	if (!(s = ft_strndup(exp->tmp + 1, len)))
		ft_error_msg("Get_env_variable failed\n");
	if ((env_var = ft_getenv(exp->env, s)))
	{
		exp->buffer_len += ft_strlen(env_var->var_value);
		while (exp->buffer_len >= exp->buffer_size)
			realloc_exp_buffer(exp);
		ft_strcat(exp->buffer, env_var->var_value);
	}
	ft_strdel(&s);
	exp->tmp += len;
}

void		handle_dollar(t_expander *exp)
{
	char	*s;

	s = exp->tmp + 1;
	if (!*s)
		append(exp);
	else if (*s == '?')
		get_exit_status(exp);
	else if (*s == '$')
		get_process_pid(exp);
	else if (*s == '0')
		get_shell_name(exp);
	else
		get_env_variable(exp, s);
}
