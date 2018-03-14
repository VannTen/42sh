/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchar_termcaps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:11:15 by bjanik            #+#    #+#             */
/*   Updated: 2018/03/14 11:30:58 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	apply_termcaps(char *str)
{
	char	*s;

	s = tgetstr(str, NULL);
	if (s)
		tputs(s, 1, putchar_termcaps);
}

int		putchar_termcaps(int c)
{
	return (write(STDIN_FILENO, &c, 1));
}
