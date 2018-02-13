/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_generation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:22:27 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/13 13:24:42 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_GENERATION_H
# define AST_GENERATION_H

void	*create_program(void const *lex_value);
t_bool	give_program(void *construct, void *sub_construct);
void	destroy_program(void **program_loc);

void	*create_complete_commands(void const *lex_value);
t_bool	give_complete_commands(void *construct, void *sub_construct);
void	destroy_complete_commands(void **complete_commands_loc);

void	*create_complete_command(void const *lex_value);
t_bool	give_complete_command(void *construct, void *sub_construct);
void	destroy_complete_command(void **complete_command_loc);

void	*create_list(void const *lex_value);
t_bool	give_list(void *construct, void *sub_construct);
void	destroy_list(void **list_loc);

void	*create_and_or(void const *lex_value);
t_bool	give_and_or(void *construct, void *sub_construct);
void	destroy_and_or(void **and_or_loc);

void	*create_pipeline_preop(void const *lex_value);
t_bool	give_pipeline_preop(void *construct, void *sub_construct);
void	destroy_pipeline_preop(void **pipeline_preop_loc);

void	*create_pipeline(void const *lex_value);
t_bool	give_pipeline(void *construct, void *sub_construct);
void	destroy_pipeline(void **pipeline_loc);

void	*create_pipe_sequence(void const *lex_value);
t_bool	give_pipe_sequence(void *construct, void *sub_construct);
void	destroy_pipe_sequence(void **pipe_sequence_loc);

void	*create_simple_command(void const *lex_value);
t_bool	give_simple_command(void *construct, void *sub_construct);
void	destroy_simple_command(void **simple_command_loc);

void	*create_io_redirect(void const *lex_value);
t_bool	give_io_redirect(void *construct, void *sub_construct);
void	destroy_io_redirect(void **io_redirect_loc);

void	*create_io_operator(void const *lex_value);
t_bool	give_io_operator(void *construct, void *sub_construct);
void	destroy_io_operator(void **io_operator_loc);

void	*create_word(void const *lex_value);
void	*create_and_if(void const *lex_value);
void	*create_or_if(void const *lex_value);
void	*create_io_number(void const *lex_value);
void	*create_less(void const *lex_value);
void	*create_dless(void const *lex_value);
void	*create_dlessdash(void const *lex_value);
void	*create_lessand(void const *lex_value);
void	*create_lessgreat(void const *lex_value);
void	*create_great(void const *lex_value);
void	*create_dgreat(void const *lex_value);
void	*create_greatand(void const *lex_value);
void	*create_clobber(void const *lex_value);
void	*create_bang(void const *lex_value);

#endif
