/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_ast.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 10:00:26 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/01 08:55:16 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_AST_H
# define SHELL_AST_H

# include "shell_ast/program.h"
# include "shell_ast/complete_command.h"
# include "shell_ast/list.h"
# include "shell_ast/and_or.h"
# include "shell_ast/pipeline.h"
# include "shell_ast/pipe_sequence.h"
# include "shell_ast/simple_command.h"
# include "shell_ast/io_redirect.h"
# include "shell_ast/io_operator.h"

int	shx_program(struct s_sh_program *const program);
int	shx_complete_command(struct s_sh_complete_command *const complete_command);
int	shx_list(struct s_sh_list *const list);
int	shx_and_or(struct s_sh_and_or *const and_or);
int	shx_pipeline(struct s_sh_pipeline *const pipeline);
int	shx_pipe_sequence(struct s_sh_pipe_sequence *const pipe_sequence);
int	shx_simple_command(struct s_sh_simple_command *const simple_command);
int	shx_io_redirect(struct s_sh_io_redirect *io_redirect, t_lst **fd_backups);

#endif
