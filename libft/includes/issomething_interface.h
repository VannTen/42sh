/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issomething_interface.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:25:30 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/09 11:06:15 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISSOMETHING_INTERFACE_H
# define ISSOMETHING_INTERFACE_H
# include "bool_interface.h"

/*
** Char checks
** Implementation file : ft_isascii.c
*/

t_bool		ft_isalpha(int c);
t_bool		is_among(char const *ref, int c);
t_bool		ft_isspace(int c);
t_bool		is_unix_constants(int c);

/*
** Implementation file : function name.
*/

t_bool		ft_isdigit(int c);
t_bool		ft_isalnum(int c);
t_bool		ft_isascii(int c);
t_bool		ft_isprint(int c);

/*
** Strings checks
** Implementation file : ft_isstring.c
*/

t_bool		string_is_digit(const char *string);

#endif
