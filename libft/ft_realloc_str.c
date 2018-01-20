#include "libft.h"

int	ft_realloc_str(t_string *str)
{
	char	*tmp;

	tmp = str->str;
	if (!(str->str = ft_strnew(str->size * 2)))
		return (MALLOC_FAIL);
	str->size *= 2;
	ft_strcpy(str->str, tmp);
	free(tmp);
	return (0);
}
