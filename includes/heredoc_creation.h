/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_creation.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 22:25:06 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/06 11:35:31 by ble-berr         ###   ########.fr       */
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

#endif
