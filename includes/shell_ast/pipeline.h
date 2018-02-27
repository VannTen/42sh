/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 14:17:11 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/14 10:07:36 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_AST_PIPELINE_H
# define SHELL_AST_PIPELINE_H

# include "libft.h"

struct s_sh_pipeline
{
	void	*pipe_sequence;
	t_bool	bang;
};

#endif
