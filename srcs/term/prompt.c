/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 15:17:41 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/14 15:43:21 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		get_prompt(t_term *term)
{
	char	*pwd;

	if (!(pwd = getcwd(NULL, MAX_PROMPT_SIZE)))
	{
		ft_strcpy(term->prompt, "Where am I ??");
		term->prompt_len = 12;
	}
	else
	{
		ft_bzero(term->prompt, MAX_PROMPT_SIZE);
		if (pwd[0] == '/' && !pwd[1])
			term->prompt[0] = *pwd;
		else
			ft_strcpy(term->prompt, ft_strrchr(pwd, '/') + 1);
		ft_strdel(&pwd);
		term->prompt_len = ft_strlen(term->prompt) + 3;
	}
	term->cursor_col = term->prompt_len + 1;
	term->first_line_len = term->width - term->prompt_len;
}

void		display_basic_prompt(t_input *input)
{
	input->term->prompt_len = 2;
	ft_bzero(input->buffer, input->buffer_len);
	ft_strcpy(input->term->prompt, "> ");
	write(STDERR_FILENO, input->term->prompt, input->term->prompt_len);
	input->cursor_pos = 0;
	input->buffer_len = 0;
	input->term->cursor_col = 3;
}

void		print_prompt(t_input *input, char *color)
{
	get_prompt(input->term);
	if (input->type != HISTORY_SEARCH)
		ft_putchar_fd('\n', STDERR_FILENO);
	ft_putstr_fd(BOLD_GRN, STDERR_FILENO);
	ft_printf("%C ", 0x21E8);
	ft_putstr_fd(RESET, STDERR_FILENO);
	ft_putstr_fd(color, STDERR_FILENO);
	ft_putstr_fd(input->term->prompt, STDERR_FILENO);
	ft_putstr_fd(RESET, STDERR_FILENO);
	ft_putchar_fd(' ', STDERR_FILENO);
}
