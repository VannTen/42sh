/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiting_for_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 11:41:51 by bjanik            #+#    #+#             */
/*   Updated: 2018/03/02 18:57:12 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_keys		g_handle_keys[] = {
	{ARROW_UP, {handle_arrow_up, skip_key}},
	{ARROW_DOWN, {handle_arrow_down, skip_key}},
	{ARROW_LEFT, {handle_arrow_left, select_left}},
	{ARROW_RIGHT, {handle_arrow_right, select_right}},
	{CTRL_UP, {handle_ctrl_up, skip_key}},
	{CTRL_DOWN, {handle_ctrl_down, skip_key}},
	{CTRL_LEFT, {handle_ctrl_left, skip_key}},
	{CTRL_RIGHT, {handle_ctrl_right, skip_key}},
	{BACKSPACE, {handle_backspace, skip_key}},
	{DELETE, {handle_delete, skip_key}},
	{END, {handle_end, handle_end}},
	{HOME, {handle_home, handle_home}},
	{CTRL_A, {switch_input_state, switch_input_state}},
	{CTRL_D, {handle_eof, handle_eof}},
	{CTRL_E, {paste_selection_buffer, paste_selection_buffer}},
	{CTRL_F, {skip_key, copy_selection}},
	{CTRL_K, {handle_clear_line_af_cursor, skip_key}},
	{CTRL_R, {handle_history_search, skip_key}},
	{CTRL_U, {handle_clear_line_bf_cursor, skip_key}},
	{CTRL_X, {skip_key, cut_selection}},
	{ALT_GREAT, {handle_alt_great, skip_key}},
	{ALT_LESS, {handle_alt_less, skip_key}},
	{RETURN_C, {handle_return, skip_key}},
	{CLEAR_SCREEN, {handle_clear_screen, skip_key}},
	{NULL, {NULL, NULL}},
};

static int	apply_key(t_input *input)
{
	int		ret;
	int		i;

	input->read_buf_ind++;
	i = -1;
	while (g_handle_keys[++i].key)
		if (!ft_strncmp(input->read_buffer, g_handle_keys[i].key,
				input->read_buf_ind))
		{
			if (g_handle_keys[i].key[input->read_buf_ind] == 0)
			{
				ret = g_handle_keys[i].handle_keystroke[input->state](input);
				ft_bzero(input->read_buffer, MAX_KEY_LENGTH);
				input->read_buf_ind = 0;
			}
			else
				ret = 0;
			return (ret);
		}
	ft_bzero(input->read_buffer, MAX_KEY_LENGTH);
	input->read_buf_ind = 0;
	return (0);
}

static int	get_key(t_input *input)
{
	int	i;

	i = -1;
	if (input->read_buffer[0] == '\t' && input->state != SELECTION)
		input->state = COMPLETION;
	else if (input->state != SELECTION)
		input->state = STANDARD;
	if (input->state == COMPLETION && input->comp.prefix == NULL)
		if (init_completion_data(&input->comp, input->buffer,
								input->cursor_pos))
		{
			reset_completion_data(&input->comp);
			return (MALLOC_FAIL);
		}
	if (input->state == COMPLETION)
		return (completion(input));
	reset_completion_data(&input->comp);
	if (!ft_isprint(input->read_buffer[0]))
		return (apply_key(input));
	return (handle_reg_char(input, input->read_buffer[0]));
}

static int	buf_read_one(char *buffer, int offset)
{
	int	ret;

	ret = 0;
	while (!ret)
	{
		ret = read(STDIN_FILENO, buffer + offset, 1);
		if (g_sigint_detected)
			break ;
	}
	if (g_sigint_detected)
	{
		g_sigint_detected = 0;
		return (CATCH_SIGINT);
	}
	buffer[offset + 1] = 0;
	return (ret);
}

int			wait_for_input(t_input *input, int input_type)
{
	int		ret;
	int		r_ret;

	input->type = input_type;
	input->read_buf_ind = 0;
	ft_bzero(input->read_buffer, MAX_KEY_LENGTH + 1);
	while (42)
	{
		if ((r_ret = buf_read_one(input->read_buffer, input->read_buf_ind)) < 1)
			return (READ_FAIL);
		else if (r_ret == CATCH_SIGINT)
			return (CATCH_SIGINT);
		if ((ret = get_key(input)) == MALLOC_FAIL)
			return (MALLOC_FAIL);
		else if (ret)
			break ;
	}
	if (input->type != HISTORY_SEARCH)
		write(STDIN_FILENO, RETURN_C, 1);
	return (ret);
}
