#include "shell.h"

int	realloc_exp_buffer(t_expander *exp)
{
	char	*tmp;

	tmp = exp->buffer;
	if (!(exp->buffer = (char*)malloc((exp->buffer_size * 2) * sizeof(char))))
		return (MALLOC_FAIL);
	exp->buffer_size *= 2;
	ft_bzero(exp->buffer, exp->buffer_size);
	ft_strcpy(exp->buffer, tmp);
	free(tmp);
	return (0);
}

inline int	append(t_expander *exp)
{
	if (exp->buffer_len == exp->buffer_size)
		if (realloc_exp_buffer(exp) == MALLOC_FAIL)
			return (MALLOC_FAIL);
	exp->buffer[exp->buffer_len++] = *(exp->tmp);
	return (0);
}

inline int	skip(t_expander *exp)
{
	(void)exp;
	return (0);
}

inline int	handle_bckslsh(t_expander *exp)
{
	exp->tmp++;
	return (append(exp));
}

inline int	handle_bckslsh_dquote(t_expander *exp)
{
	char	*s;

	s = exp->tmp + 1;
	if (*s == '\\' || *s == '"' || *s == '\n')
		exp->tmp++;
	return (append(exp));
}
