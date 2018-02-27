/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string_array.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:54:22 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/10 11:27:19 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_array_defs.h"
#include "string_interface.h"
#include "stdout_interface.h"
#include <unistd.h>
#include <stddef.h>

void	ft_print_string_array(char const *const *str_array, char const *sep)
{
	ft_print_string_array_fd(STDOUT_FILENO, str_array, sep);
}

void	ft_print_string_array_fd(int const fd,
		char const *const *str_array, char const *sep)
{
	size_t	index;

	index = 0;
	if (str_array != NULL && str_array[index] != NULL)
	{
		while (1)
		{
			ft_putstr_fd(str_array[index], fd);
			index++;
			if (str_array[index] != NULL)
				ft_putstr_fd(sep, fd);
			else
				break ;
		}
	}
}
