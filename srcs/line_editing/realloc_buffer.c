/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:43:48 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/13 18:03:24 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		realloc_buffer(t_input *input)
{
	char	*tmp;

	tmp = input->buffer;
	if (!(input->buffer = ft_strnew(input->buffer_size * 2)))
		return (MALLOC_FAIL);
	input->buffer_size *= 2;
	ft_strcpy(input->buffer, tmp);
	free(tmp);
	return (0);
}
