/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:08:25 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/15 15:32:21 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "s_container.h"
#include "shell_ast/container_labels.h"

void	*create_word(void const *lex_value)
{
	struct s_container	*container;

	if (lex_value != NULL)
	{
		container = new_container(lex_value, &ft_memdel, ft_strlen(lex_value) + 1,
					e_ast_container_label_word);
		ft_dprintf(2, "new word container->%p string:%s\n", container, lex_value);
		return (container);
	}
	else
		return (NULL);
}
