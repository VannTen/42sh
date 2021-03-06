/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 16:35:51 by bjanik            #+#    #+#             */
/*   Updated: 2018/03/23 14:23:02 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	save_line_to_input_buffer(t_input *input, char **line)
{
	input->buffer_len = ft_strlen(*line);
	while (input->buffer_len + 1 >= input->buffer_size)
		if (realloc_buffer(input) == MALLOC_FAIL)
			return (MALLOC_FAIL);
	ft_strcpy(input->buffer, *line);
	input->buffer[input->buffer_len++] = '\n';
	ft_strdel(line);
	return (0);
}

static int	get_line_from_file(t_input *input, size_t *state)
{
	int		ret;
	char	*line;

	if ((ret = get_next_line(input->fd, &line)) > 0)
		return (save_line_to_input_buffer(input, &line));
	else if (ret < 0)
		sh_exit_message("42sh: get_next_line failed");
	else if ((*state == DQUOTE || *state == QUOTE))
	{
		ft_dprintf(STDERR_FILENO, "42sh: unexpected EOF while looking for"
				" matching `%c'\n", (*state == DQUOTE) ? '"' : '\'');
		exit(UNMATCHED_QUOTES);
	}
	else if (*state == STD)
	{
		*state = INIT;
		return (0);
	}
	return (END_OF_FILE);
}

int			getline(t_input *input, const int interactive, const int mode,
					size_t *state)
{
	t_term	*term;
	int		ret;

	term = &get_shell_data()->term;
	ret = 0;
	if (interactive == 1)
	{
		apply_termcaps("ks");
		set_shell_sigmode(e_shell_sigmode_line_editing);
		restore_custom_attr(term);
		if ((ret = wait_for_input(input, mode)) == MALLOC_FAIL)
			return (ret);
		apply_termcaps("ke");
		set_shell_sigmode(e_shell_sigmode_shell);
		restore_initial_attr(term);
	}
	else
	{
		if ((ret = get_line_from_file(input, state)) == MALLOC_FAIL)
			return (MALLOC_FAIL);
	}
	(ret == RETURN) ? ret = 0 : 0;
	return (ret);
}
