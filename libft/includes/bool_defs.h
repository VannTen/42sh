/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_defs.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 15:19:59 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/12 15:56:28 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOOL_DEFS_H
# define BOOL_DEFS_H
# include "bool_interface.h"

typedef t_bool	(*t_char_tester)(char, char);

/*
** Internal functions
*/

/*
** Char comparison
** Implementation file : boolean_on_char.c
*/

t_bool	equal_char(char to_test, char to_test_against);
t_bool	diff_char(char to_test, char to_test_against);
t_bool	lower_char(char to_test, char to_test_against);
t_bool	greater_char(char to_test, char to_test_against);
t_bool	lower_equal_char(char to_test, char to_test_against);

/*
** Char comparison 2
** Implementation file : boolean_on_char_follow.c
*/

t_bool	greater_equal_char(char to_test, char to_test_against);

#endif
