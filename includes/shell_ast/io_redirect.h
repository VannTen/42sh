/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_redirect.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 09:24:49 by ble-berr          #+#    #+#             */
/*   Updated: 2018/01/29 09:36:03 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_AST_REDIRECTION_H
# define SHELL_AST_REDIRECTION_H

enum	e_sh_io_type
{
	e_sh_io_type_none = -1,
	e_sh_io_type_great,
	e_sh_io_type_dgreat,
	e_sh_io_type_lessgreat,
	e_sh_io_type_less,
	e_sh_io_type_dless,
	e_sh_io_type_dlessdash,
	e_sh_io_type_greatand,
	e_sh_io_type_lessand,
	e_sh_io_type_max,
};

union	u_sh_io_target
{
	int		fd;
	char	*name;
};

struct s_sh_io_redirect
{
	int						ionum;
	enum e_sh_io_type		type;
	union u_sh_io_target	target;
};

#endif
