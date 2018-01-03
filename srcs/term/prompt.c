/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 15:17:41 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/02 15:53:26 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

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
		free(pwd);
		term->prompt_len = ft_strlen(term->prompt) + 3;
	}
	term->cursor_col = term->prompt_len + 1;
	term->first_line_len = term->width - term->prompt_len;
}

void		display_basic_prompt(t_term *term)
{
	t_input	*input;

	input = get_bsh()->input;
	term->prompt_len = 2;
	ft_bzero(input->buffer, input->buffer_len);
	ft_strcpy(term->prompt, "> ");
	write(STDERR, term->prompt, term->prompt_len);
	input->cursor_pos = 0;
	input->buffer_len = 0;
	term->cursor_col = 3;
}

void		print_prompt(t_term *term, char *color)
{
	t_bsh	*bsh;

	bsh = get_bsh();
	get_prompt(term);
	if (get_bsh()->input->type != HISTORY_SEARCH)
		ft_putchar_fd('\n', STDERR);
	(!bsh->exit_status) ? ft_putstr_fd(BOLD_GRN, STDERR) :
		ft_putstr_fd(BOLD_RED, STDERR);
	ft_printf("%C ", 0x21E8);
	ft_putstr_fd(RESET, STDERR);
	ft_putstr_fd(color, STDERR);
	ft_putstr_fd(term->prompt, STDERR);
	ft_putstr_fd(RESET, STDERR);
	ft_putchar_fd(' ', STDERR);
}
