#include "shell.h"

static int	get_process_pid(t_expander *exp)
{
	char	*s;

	if (!(s = ft_itoa(get_bsh()->pid)))
		return (MALLOC_FAIL);
	exp->buffer_len += ft_strlen(s);
	if (exp->buffer_len >= exp->buffer_size)
		realloc_exp_buffer(exp);
	ft_strcat(exp->buffer, s);
	free(s);
	exp->tmp++;
	return (0);
}

static int	get_exit_status(t_expander *exp)
{
	char	*s;

	if (!(s = ft_itoa(get_bsh()->exit_status)))
		return (MALLOC_FAIL);
	exp->buffer_len += ft_strlen(s);
	if (exp->buffer_len >= exp->buffer_size)
		realloc_exp_buffer(exp);
	ft_strcat(exp->buffer, s);
	free(s);
	exp->tmp++;
	return (0);
}

static int	get_shell_name(t_expander *exp)
{
	ft_strcat(exp->buffer, get_bsh()->shell_name);
	exp->buffer_len += 4;
	if (exp->buffer_len >= exp->buffer_size)
		realloc_exp_buffer(exp);
	exp->tmp++;
	return (0);
}

static int	get_env_variable(t_expander *exp, char *s)
{
	t_env	*env_var;
	int		len;

	len = 0;
	while (ft_isalnum(*(s + len)) || *(s + len) == '_')
		len++;
	if (!len)
	{
		exp->buffer[exp->buffer_len++] = *(s - 1);
		return (0);
	}
	if (!(s = ft_strndup(exp->tmp + 1, len)))
		return (MALLOC_FAIL);
	if ((env_var = ft_getenv(exp->env, s)))
	{
		exp->buffer_len += ft_strlen(env_var->var_value);
		while (exp->buffer_len >= exp->buffer_size)
			realloc_exp_buffer(exp);
		ft_strcat(exp->buffer, env_var->var_value);
	}
	ft_strdel(&s);
	exp->tmp += len;
	return (0);
}

int		handle_dollar(t_expander *exp)
{
	char	*s;

	s = exp->tmp + 1;
	if (!*s)
		return (append(exp);
	else if (*s == '?')
		return (get_exit_status(exp));
	else if (*s == '$')
		return (get_process_pid(exp));
	else if (*s == '0')
		return (get_shell_name(exp));
	else
		return (get_env_variable(exp, s));
}
