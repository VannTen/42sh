/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:08:25 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/01 16:02:22 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast_generation.h"
#include "shell_ast/io_redirect.h"
#include "shell_ast/container_labels.h"
#include "s_container.h"
#include "libft.h"
#include "io_redirect_settings.h"
#include "bleberr_macros.h"
#include <stdlib.h>

void	*create_io_redirect(void const *lex_value)
{
	struct s_container		*container;
	struct s_sh_io_redirect	io_redirect;

	(void)lex_value;
	io_redirect.ionum = NULL;
	io_redirect.type = e_sh_io_type_none;
	io_redirect.target = NULL;
	io_redirect.flags = 0;
	io_redirect.mode = 0;
	io_redirect.variant = 0;
	container = new_container(&io_redirect, &destroy_io_redirect,
			sizeof(io_redirect), e_ast_container_label_io_redirect);
	return (container);
}

void	destroy_io_redirect(void **const io_redirect_loc)
{
	struct s_sh_io_redirect	*todel;

	todel = (io_redirect_loc != NULL) ? (*io_redirect_loc) : (NULL);
	if (todel != NULL)
	{
		ft_strdel(&(todel->ionum));
		ft_strdel(&(todel->target));
		free(todel);
		*io_redirect_loc = NULL;
	}
}
