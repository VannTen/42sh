/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 12:43:17 by bjanik            #+#    #+#             */
/*   Updated: 2018/03/01 18:23:00 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	get_process_pid(t_expander *exp)
{
	char	*s;

	if (!(s = ft_itoa(getpid())))
		return (MALLOC_FAIL);
	exp->buffer_len += ft_strlen(s);
	if (exp->buffer_len >= exp->buffer_size)
		if (realloc_exp_buffer(exp) == MALLOC_FAIL)
		{
			ft_strdel(&s);
			return (MALLOC_FAIL);
		}
	ft_strcat(exp->buffer, s);
	ft_strdel(&s);
	exp->tmp++;
	return (0);
}

static int	get_exit_status(t_expander *exp)
{
	char	*s;

	if (!(s = ft_itoa(get_shell_data()->exit_status)))
		return (MALLOC_FAIL);
	exp->buffer_len += ft_strlen(s);
	while (exp->buffer_len >= exp->buffer_size)
		if (realloc_exp_buffer(exp) == MALLOC_FAIL)
		{
			ft_strdel(&s);
			return (MALLOC_FAIL);
		}
	ft_strcat(exp->buffer, s);
	ft_strdel(&s);
	exp->tmp++;
	return (0);
}

static int	get_shell_name(t_expander *exp)
{
	exp->buffer_len += 4;
	while (exp->buffer_len >= exp->buffer_size)
		if (realloc_exp_buffer(exp) == MALLOC_FAIL)
			return (MALLOC_FAIL);
	ft_strcat(exp->buffer, "42sh");
	exp->tmp++;
	return (0);
}

static int	get_env_variable(t_expander *exp, char *s)
{
	t_env_list	*env_var;
	int			len;

	len = 0;
	while (ft_isalnum(*(s + len)) || *(s + len) == '_')
		len++;
	if (!len)
		return (append(exp));
	if (!(s = ft_strndup(exp->tmp + 1, len)))
		return (MALLOC_FAIL);
	if ((env_var = ft_getenv(exp->env, s)))
	{
		exp->buffer_len += ft_strlen(env_var->value);
		while (exp->buffer_len >= exp->buffer_size)
			if (realloc_exp_buffer(exp) == MALLOC_FAIL)
			{
				ft_strdel(&s);
				return (MALLOC_FAIL);
			}
		ft_strcat(exp->buffer, env_var->value);
	}
	ft_strdel(&s);
	exp->tmp += len;
	return (0);
}

int			handle_dollar(t_expander *exp)
{
	char	*s;

	s = exp->tmp + 1;
	if (!*s)
		return (append(exp));
	else if (*s == '?')
		return (get_exit_status(exp));
	else if (*s == '$')
		return (get_process_pid(exp));
	else if (*s == '0')
		return (get_shell_name(exp));
	else
		return (get_env_variable(exp, s));
}
