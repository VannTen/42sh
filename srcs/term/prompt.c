/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 15:17:41 by bjanik            #+#    #+#             */
/*   Updated: 2018/03/23 15:59:47 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	prompt_to_buf(t_term *term, char *prompt)
{
	int		truncated;
	size_t	prompt_len;

	prompt_len = ft_strlen(prompt);
	if ((size_t)((term->width / 2) + 3) < prompt_len)
	{
		truncated = 1;
		prompt_len = (term->width / 2) + 3;
	}
	else
		truncated = 0;
	ft_strncpy(term->prompt, prompt, prompt_len);
	if (truncated)
		ft_strncpy(term->prompt + prompt_len - 3, "...", 4);
}

void		get_prompt(t_term *term)
{
	char	*pwd;

	get_term_size(term);
	if (!(pwd = getcwd(NULL, MAX_PROMPT_SIZE)))
	{
		ft_strcpy(term->prompt, "Where am I ??");
		term->prompt_len = 13;
	}
	else
	{
		ft_bzero(term->prompt, MAX_PROMPT_SIZE);
		if (pwd[0] == '/' && !pwd[1])
			term->prompt[0] = *pwd;
		else
			prompt_to_buf(term, ft_strrchr(pwd, '/') + 1);
		ft_strdel(&pwd);
		term->prompt_len = ft_strlen(term->prompt) + 1;
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
	input->term->first_line_len = input->term->width - 2;
}

void		print_prompt(t_input *input)
{
	t_bsh *const	bsh = get_shell_data();

	get_prompt(input->term);
	if (input->type != HISTORY_SEARCH)
		ft_putchar_fd('\n', STDERR_FILENO);
	if (bsh->exit_status)
		ft_putstr_fd(BOLD_RED, STDERR_FILENO);
	else
		ft_putstr_fd(BOLD_GRN, STDERR_FILENO);
	ft_putstr_fd(input->term->prompt, STDERR_FILENO);
	ft_putstr_fd(RESET, STDERR_FILENO);
	ft_putchar_fd(' ', STDERR_FILENO);
}
