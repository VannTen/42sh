/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_redirect.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 09:24:49 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/22 11:32:33 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_AST_REDIRECTION_H
# define SHELL_AST_REDIRECTION_H

enum	e_sh_io_type
{
	e_sh_io_type_none = -1,
	e_sh_io_type_file,
	e_sh_io_type_here,
	e_sh_io_type_aggregate
};

struct s_sh_io_redirect
{
	char				*ionum;
	enum e_sh_io_type	type;
	char				*target;
	int					flags;
	int					mode;
	int					variant;
};

#endif
