/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_tilde.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 12:43:11 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/27 13:07:15 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	handle_tilde(t_expander *exp)
{
	t_env_list	*home;

	home = NULL;
	if (exp->buffer_len == 0 && (*(exp->tmp + 1) == '/' || !*(exp->tmp + 1)) &&
			(home = ft_getenv(exp->env, "HOME")))
	{
		ft_strcpy(exp->buffer, home->value);
		exp->buffer_len += ft_strlen(home->value);
	}
	else
		return (append(exp));
	return (0);
}
