#include "libft.h"

t_string	ft_init_str(const size_t size)
{
	t_string	str;

	str.str = ft_strnew(size);
	str.len = 0;
	str.size = size;
	return (str);
}
