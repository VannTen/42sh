/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_here.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 22:38:48 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/02 18:11:27 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_HERE_H
# define IO_HERE_H

# define HEREDOC_PREFIX "/tmp/.42sh_heredoc_"
# define HEREDOC_MAX_ID_LEN 16

int		fill_heredoc(int doc_fd, char const *here_end, size_t here_end_len,
		t_bool is_dlessdash);
char	*create_heredoc(char *here_end, t_bool is_dlessdash);

#endif
