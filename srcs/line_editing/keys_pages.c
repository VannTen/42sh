/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_alt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 16:10:25 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/21 15:54:39 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	handle_page_up(t_input *input)
{
	input->history->current = 0;
	cp_history_to_buffer(input);
	return (0);
}

int	handle_page_down(t_input *input)
{
	if (input->history->len)
	{
		input->history->current = input->history->len - 1;
		cp_history_to_buffer(input);
	}
	return (0);
}
