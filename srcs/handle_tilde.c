#include "shell.h"

int	handle_tilde(t_expander *exp)
{
	t_env_list	*home;

	home = NULL;
	if (exp->buffer_len == 0 && (*(exp->tmp + 1) == '/' || !*(exp->tmp + 1)) &&
			(home = ft_getenv(exp->env.env_list, "HOME")))
	{
		ft_strcpy(exp->buffer, home->var_value);
		exp->buffer_len += ft_strlen(home->var_value);
	}
	else
		return (append(exp));
	return (0);
}
