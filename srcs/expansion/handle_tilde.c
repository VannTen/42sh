/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_tidle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 18:30:32 by bjanik            #+#    #+#             */
/*   Updated: 2017/11/03 16:50:35 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

void		handle_tilde(t_expander *exp)
{
	t_env	*home;

	home = NULL;
	if (exp->buffer_len == 0 && (*(exp->tmp + 1) == '/' || !*(exp->tmp + 1)) &&
			(home = ft_getenv(exp->env, "HOME")))
	{
		ft_strcpy(exp->buffer, home->var_value);
		exp->buffer_len += ft_strlen(home->var_value);
	}
	else
		append(exp);
}
