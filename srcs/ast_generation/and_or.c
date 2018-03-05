/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:08:25 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/05 22:37:26 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_ast/and_or.h"
#include "shell_ast/container_labels.h"
#include "s_container.h"
#include "libft.h"
#include "ast_generation.h"
#include <stdlib.h>

void		*create_and_or(void const *lex_value)
{
	struct s_container	*container;
	struct s_sh_and_or	and_or;

	(void)lex_value;
	and_or.sequence = NULL;
	container = new_container(&and_or, &destroy_and_or, sizeof(and_or),
			e_ast_container_label_and_or);
	return (container);
}

static void	destroy_and_or_sequence(void **sequence_loc)
{
	struct s_and_or_logic	*sequence;
	struct s_and_or_logic	*todel;

	if (sequence_loc != NULL)
	{
		sequence = *sequence_loc;
		while (sequence != NULL)
		{
			todel = sequence;
			sequence = sequence->next;
			if (todel->pipeline != NULL)
				destroy_pipeline((void**)&(todel->pipeline));
			free(todel);
		}
		*sequence_loc = NULL;
	}
}

void		destroy_and_or(void **const and_or_loc)
{
	struct s_sh_and_or		*todel;

	todel = (and_or_loc != NULL) ? (*and_or_loc) : (NULL);
	if (todel != NULL)
	{
		destroy_and_or_sequence((void**)&(todel->sequence));
		free(todel);
		*and_or_loc = NULL;
	}
}
