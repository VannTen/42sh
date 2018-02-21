/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:08:25 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/21 18:15:30 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast_generation.h"
#include "shell_ast/program.h"
#include "shell_ast/container_labels.h"
#include "s_container.h"
#include "libft.h"
#include <stdlib.h>

void	*create_program(void const *lex_value)
{
	struct s_container	*container;
	struct s_sh_program	program;

	(void)lex_value;
	program.complete_commands = NULL;
	container = new_container(&program, &destroy_program, sizeof(program), e_ast_container_label_program);
	return (container);
}

t_bool	give_program(void *construct, void *sub_construct)
{
	struct s_container	*sub;
	struct s_sh_program	*program;
	t_bool				ret;

	ret = FALSE;
	if (construct != NULL && sub_construct != NULL)
	{
		program = ((struct s_container*)construct)->content;
		sub = sub_construct;
		if (sub->label == e_ast_container_label_complete_command)
		{
			program->complete_command = sub->content;
			sub->content = 0;
			ret = TRUE;
		}
		if (ret == TRUE)
			destroy_container((void**)&sub);
	}
	return (ret);
}

void	destroy_program(void **const program_loc)
{
	struct s_sh_program	*todel;

	todel = (program_loc != NULL) ? (*program_loc) : (NULL);
	if (todel != NULL)
	{
		destroy_complete_commands(&(todel->complete_commands));
		free(todel);
		*program_loc = NULL;
	}
}
