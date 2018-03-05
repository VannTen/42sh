/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 14:17:11 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/05 22:33:40 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_AST_PIPELINE_H
# define SHELL_AST_PIPELINE_H

# include "libft.h"
# include "shell_ast/pipe_sequence.h"

struct	s_sh_pipeline
{
	struct s_sh_pipe_sequence	*pipe_sequence;
	t_bool						bang;
};

#endif
