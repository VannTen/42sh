/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_tokens_to_parser.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 15:27:43 by bjanik            #+#    #+#             */
/*   Updated: 2018/03/01 16:47:41 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

size_t	get_tok_id(void const *token)
{
	t_token const *tok;

	if (token == g_tokens_name)
		return (BANG + 1);
	tok = token;
	return (tok->type);
}

void	*take_token(void *token_list_address)
{
	t_token	**list_address;
	void	*token;

	list_address = token_list_address;
	if (*list_address != NULL)
	{
		token = *list_address;
		*list_address = (*list_address)->next;
		return (token);
	}
	else
		return ((void*)g_tokens_name);
}
