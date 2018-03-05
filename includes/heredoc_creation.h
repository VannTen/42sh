/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_creation.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 22:25:06 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/05 22:29:13 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_CREATION_H
# define HEREDOC_CREATION_H

# include "shell_ast.h"

# define HEREDOC_PREFIX "/tmp/.42sh_heredoc_"
# define HEREDOC_MAX_ID_LEN 16

int		fill_heredoc(int doc_fd, char const *here_end, size_t here_end_len,
		t_bool is_dlessdash);
char	*create_heredoc(char *here_end, t_bool is_dlessdash);

void	unlink_redir_list_heredocs(t_lst *redir_lst, t_lst *endpoint);
void	unlink_simple_commands_heredocs(t_lst *simple_command_lst,
		t_lst *endpoint);
void	unlink_and_or_logic_heredocs(struct s_and_or_logic *logic,
		struct s_and_or_logic *endpoint);
void	unlink_and_or_sequence_heredocs(t_lst *and_or_sequence, t_lst *endpoint);

int		create_all_heredocs(struct s_sh_program *program);

#endif
