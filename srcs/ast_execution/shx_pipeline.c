/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shx_pipeline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 09:24:45 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/05 10:41:06 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	shx_pipeline(struct s_sh_pipeline *const pipeline,
		struct s_sh_global *const global)
{
	if (pipeline != NULL)
	{
		(void)shx_pipe_sequence(pipeline->pipe_sequence);
		if (pipeline->logical_not)
			global->latest_ret = (0 < global->latest_ret) ? 0 : 1;
	}
	return (0);
}
