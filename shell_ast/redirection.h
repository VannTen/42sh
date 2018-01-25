/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 09:30:06 by ble-berr          #+#    #+#             */
/*   Updated: 2018/01/25 09:31:01 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_AST_REDIRECTION_H
# define SHELL_AST_REDIRECTION_H

union	u_redir_target
{
	int		fd;
	char	*name;
};

struct s_redirection
{
	int						ionum;
	int						type;
	union u_redir_target	target;
};

#endif
