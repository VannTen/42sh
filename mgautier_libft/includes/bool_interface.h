/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_interface.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 15:38:18 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/27 18:50:40 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOOL_INTERFACE_H
# define BOOL_INTERFACE_H
# include <stddef.h>

typedef enum		e_bool{
	FALSE = (1 == 0),
	TRUE = !FALSE
}					t_bool;

/*
** Fonctions for simplify complicated truthiness test
*/

/*
** string_test
** Implemented in boolean.c
** Use : user must provide a test (using the C test operator as const string)
** a char to be tested, and a set of char (compacted in a string)
** to test against
** Note : if '\0' is among the characters to be tested,
** it should be placed first in the string.
** Besides, to_test_against cannot be an empty C string (containing only '\0'
** as first element);
*/

t_bool	string_test(char to_test, const char *to_test_against,
		const char *str_test);

/*
** Init functions
** File : boolean.c
*/

void	init_bool_array(t_bool *array, size_t size, t_bool value);
t_bool	*create_bool_array(size_t size, t_bool init_value);
void	destroy_bool_array(t_bool **array, size_t size);

#endif
