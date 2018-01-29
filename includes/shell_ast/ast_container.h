/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_container.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:45:56 by ble-berr          #+#    #+#             */
/*   Updated: 2018/01/29 08:42:14 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_AST_AST_CONTAINER_H
# define SHELL_AST_AST_CONTAINER_H

enum	e_ast_label
{

/*
** Token labels
*/

	e_ast_label_word,
	e_ast_label_io_number,
	e_ast_label_and_if,
	e_ast_label_or_if,
	e_ast_label_less,
	e_ast_label_lessand,
	e_ast_label_great,
	e_ast_label_dgreat,
	e_ast_label_greatand,
	e_ast_label_lessgreat,
	e_ast_label_dless,
	e_ast_label_dlessdash,
	e_ast_label_newline,
	e_ast_label_semicolon,

/*
** Cosntruct labels
*/

	e_ast_label_program,
	e_ast_label_complete_commands,
	e_ast_label_complete_command,
	e_ast_label_list,
	e_ast_label_and_or,
	e_ast_label_pipe_sequence,
	e_ast_label_simple_command,
	e_ast_label_io_redirect,
	e_ast_label_io_operator,
	e_ast_label_newline_list,
	e_ast_label_separator_op
};

struct	s_ast_container
{
	void				*content;
	enum e_ast_label	label;
};

#endif
