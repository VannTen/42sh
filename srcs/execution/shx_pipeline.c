/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shx_pipeline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 09:24:45 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/01 09:32:54 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "shell.h"

int	shx_pipeline(struct s_sh_pipeline *const pipeline)
{
	t_bsh	*const bsh = get_shell_data();

	if (bsh && pipeline != NULL)
	{
		(void)shx_pipe_sequence(pipeline->pipe_sequence);
		if (pipeline->bang)
			bsh->exit_status = !bsh->exit_status;
	}
	return (0);
}
