/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:43:48 by bjanik            #+#    #+#             */
/*   Updated: 2017/11/23 11:50:57 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

void		realloc_buffer(t_input *input)
{
	char	*tmp;

	tmp = input->buffer;
	if (!(input->buffer = (char*)malloc((input->buffer_size * 2 + 1)
			* sizeof(char))))
		ft_error_msg("Malloc failed\n");
	input->buffer_size *= 2;
	ft_bzero(input->buffer, input->buffer_size + 1);
	ft_strcpy(input->buffer, tmp);
	free(tmp);
}
