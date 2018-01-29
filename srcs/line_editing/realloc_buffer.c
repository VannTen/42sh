/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:43:48 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/21 15:55:15 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		realloc_buffer(t_input *input)
{
	char	*tmp;

	tmp = input->buffer;
	if (!(input->buffer = (char*)malloc((input->buffer_size * 2 + 1)
			* sizeof(char))))
		return (MALLOC_FAIL);
	input->buffer_size *= 2;
	ft_bzero(input->buffer, input->buffer_size + 1);
	ft_strcpy(input->buffer, tmp);
	free(tmp);
	return (0);
}
