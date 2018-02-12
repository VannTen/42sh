/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiting_for_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 11:41:51 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/12 15:24:19 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_keys	g_handle_keys[] = {
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

static int		get_key(t_input *input)
{
	int	i;

	i = -1;
	if (input->read_buffer[0] == '\t' && input->state != SELECTION)
		input->state = COMPLETION;
	else if (input->state != SELECTION)
		input->state = STANDARD;
	if (input->state == COMPLETION && input->comp.prefix == NULL)
		init_completion_data(&input->comp, input->buffer, input->cursor_pos);
	if (input->state == COMPLETION)
		return (completion(input));
	reset_completion_data(&input->comp);
	while (g_handle_keys[++i].key)
	{
		if (ft_isprint(input->read_buffer[0]))
			break ;
		if (!ft_strcmp(g_handle_keys[i].key, input->read_buffer))
			return (g_handle_keys[i].handle_keystroke[input->state](input));
	}
	return (ft_isprint(input->read_buffer[0]) && input->state == STANDARD) ?
	handle_reg_char(input, input->read_buffer[0]) : 0;
}

int		wait_for_input(t_input *input, int input_type)
{
	int		ret;
	//char	c;

	input->type = input_type;
	while (42)
	{
		ft_bzero(input->read_buffer, MAX_KEY_LENGTH + 1);
	//	read(STDIN_FILENO, &c, 1);
		if (read(STDIN_FILENO, input->read_buffer, MAX_KEY_LENGTH) < 1)
			return (READ_FAIL);
	//	input->read_buffer[ft_strlen(input->read_buffer)] = c;
	//	dprintf(input->fd, "%c\n", c);
		if ((ret = get_key(input)) == MALLOC_FAIL)
			return (MALLOC_FAIL);
		else if (ret)
			break ;
	}
	if (input->type != HISTORY_SEARCH)
		write(STDOUT, RETURN_C, 1);
	return (ret);
}
