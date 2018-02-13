/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   container_labels.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 12:27:42 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/13 20:23:56 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_AST_CONTAINER_LABELS_H
# define SHELL_AST_CONTAINER_LABELS_H

enum	e_ast_container_label
{

	e_ast_container_label_empty,

/*
** Token labels
*/

	e_ast_container_label_word,
	e_ast_container_label_io_number,
	e_ast_container_label_and_if,
	e_ast_container_label_or_if,
	e_ast_container_label_clobber,
	e_ast_container_label_less,
	e_ast_container_label_lessand,
	e_ast_container_label_great,
	e_ast_container_label_dgreat,
	e_ast_container_label_greatand,
	e_ast_container_label_lessgreat,
	e_ast_container_label_dless,
	e_ast_container_label_dlessdash,
	e_ast_container_label_newline,
	e_ast_container_label_semicolon,
	e_ast_container_label_bang,
	e_ast_container_label_pipe,

/*
** Construct labels
*/

	e_ast_container_label_program,
	e_ast_container_label_complete_commands,
	e_ast_container_label_complete_command,
	e_ast_container_label_list,
	e_ast_container_label_and_or,
	e_ast_container_label_pipeline,
	e_ast_container_label_pipeline_preop,
	e_ast_container_label_pipe_sequence,
	e_ast_container_label_simple_command,
	e_ast_container_label_io_redirect,
	e_ast_container_label_io_operator,
	e_ast_container_label_newline_list,
	e_ast_container_label_separator_op
};

#endif
