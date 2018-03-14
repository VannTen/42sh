/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_tilde.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 12:43:11 by bjanik            #+#    #+#             */
/*   Updated: 2018/03/14 16:37:19 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	handle_tilde(t_expander *exp)
{
	t_env_list		*home;
	t_bsh *const	bsh = get_shell_data();

	home = NULL;
	if (exp->buffer_len == 0 && (*(exp->tmp + 1) == '/' || !*(exp->tmp + 1)) &&
			(home = ft_getenv(bsh->env.env_list, "HOME")))
	{
		ft_strcpy(exp->buffer, home->value);
		exp->buffer_len += ft_strlen(home->value);
	}
	else
		return (append(exp));
	return (0);
}
