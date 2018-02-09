#include "shell.h"

t_expander	*init_expander(t_env *env)
{
	t_expander *exp;

	if ((exp = (t_expander*)malloc(sizeof(t_expander))) == NULL)
		return (NULL);
	exp->state = INIT1;
	exp->event = START1;
	exp->env = env;
	exp->buffer_size = INITIAL_SIZE;
	if (!(exp->buffer = ft_strnew(exp->buffer_size + 1)))
		return (NULL);
	exp->buffer_len = 0;
	exp->tmp = NULL;
	return (exp);
}
