/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_term.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 16:53:12 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/01 16:53:13 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	resize_term(int sigid)
{
	t_input	*input;

	(void)sigid;
	input = &get_shell_data()->input;
	get_term_size(input->term);
	input->term->first_line_len = input->term->width - input->term->prompt_len;
	handle_clear_screen(input);
}
