/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiting_for_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 11:41:51 by bjanik            #+#    #+#             */
/*   Updated: 2017/12/22 17:29:32 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

int		wait_for_input(t_input *input, int input_type)
{
	int	ret;

	input->type = input_type;
	while (42)
	{
		ft_bzero(input->read_buffer, MAX_KEY_LENGTH);
		if (read(STDIN, input->read_buffer, MAX_KEY_LENGTH) < 1)
			exit(EXIT_FAILURE);
		if ((ret = get_key(input)))
			break ;
	}
	if (input->type != HISTORY_SEARCH)
		write(STDOUT, RETURN_C, 1);
	return (ret);
}
