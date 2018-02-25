/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_options.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 09:00:12 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/25 22:30:44 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_CD_H
# define BUILTIN_CD_H

enum	e_cdopt
{
	e_cdopt_logical = 1 << 0,
	e_cdopt_physical = 1 << 1,
	e_cdopt_oldpwd = 1 << 2,
	e_cdopt_default = e_cdopt_logical
};

size_t	cd_get_options(char **args, int *const options_loc);
int		get_physical_path(char const *directory, char **const curpath_loc,
		t_env *env);
int		make_logical(char **const curpath_loc, char **const new_pwd_loc,
		t_env *env);
int		dotdot(char *curpath, size_t *const index_loc);
int		canonicalize(char *curpath);

#endif
