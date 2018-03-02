/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_interface.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:22:23 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/12 17:38:43 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_INTERFACE_H
# define CONVERT_INTERFACE_H

/*
** Conversion functions
** Implementation files : name of the function
*/

char	*ft_itoa(int n);
int		ft_atoi(const char *str);
int		ft_strict_atoi(const char *str);

/*
** Convert to upper case
** Implementation file : ft_toupper.c
*/

int		ft_toupper(int c);
char	f_toupper(char c);
char	f_to_unix_const(char c);

/*
** Convert to lower case
** Implementation file : ft_tolower.c
*/

int		ft_tolower(int c);
char	f_tolower(char c);

#endif
