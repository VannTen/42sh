/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 17:07:22 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/09 18:11:27 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	clear_tokens(t_token *tokens[])
{
	t_token	*tmp;

	if (!tokens)
		return ;
	tmp = tokens[0];
	//dprintf(get_shell_data()->input.fd, "%p\n", tokens[0]);
	//if (tokens[0] && tokens[0]->value);
	//	ft_printf("%p\n", tokens[0]->value);
		//dprintf(get_shell_data()->input.fd, "%p\n", tokens[0]->value);
	while (tokens[0])
	{
		tmp = tokens[0]->next;
		ft_strdel(&tokens[0]->value);
		tokens[0]->next = NULL;
		tokens[0]->prev = NULL;
		ft_memdel((void**)&tokens[0]);
		tokens[0] = tmp;
	}
	tokens[0] = NULL;
	tokens[1] = NULL;
}
