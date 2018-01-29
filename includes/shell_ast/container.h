/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_container.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:45:56 by ble-berr          #+#    #+#             */
/*   Updated: 2018/01/29 09:24:31 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_AST_AST_CONTAINER_H
# define SHELL_AST_AST_CONTAINER_H

enum	e_sh_ast_label
{

/*
** Token labels
*/

	e_sh_ast_label_word,
	e_sh_ast_label_io_number,
	e_sh_ast_label_and_if,
	e_sh_ast_label_or_if,
	e_sh_ast_label_less,
	e_sh_ast_label_lessand,
	e_sh_ast_label_great,
	e_sh_ast_label_dgreat,
	e_sh_ast_label_greatand,
	e_sh_ast_label_lessgreat,
	e_sh_ast_label_dless,
	e_sh_ast_label_dlessdash,
	e_sh_ast_label_newline,
	e_sh_ast_label_semicolon,

/*
** Construct labels
*/

	e_sh_ast_label_program,
	e_sh_ast_label_complete_commands,
	e_sh_ast_label_complete_command,
	e_sh_ast_label_list,
	e_sh_ast_label_and_or,
	e_sh_ast_label_pipe_sequence,
	e_sh_ast_label_simple_command,
	e_sh_ast_label_io_redirect,
	e_sh_ast_label_io_operator,
	e_sh_ast_label_newline_list,
	e_sh_ast_label_separator_op
};

struct	s_sh_ast_container
{
	void				*content;
	enum e_sh_ast_label	label;
};

#endif
