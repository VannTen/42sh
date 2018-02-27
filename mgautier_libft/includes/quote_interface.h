/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_interface.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 18:30:14 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/28 10:26:33 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUOTE_INTERFACE_H
# define QUOTE_INTERFACE_H
# include "bool_interface.h"
# include <stddef.h>

/*
** Implementation file : quote_correctness.c
**
** These functions return the state of a line string.
** The first take a string and the characters that can quote.
**
** The others are to be used by functions which have a string under another form
** that the classic C string (an array of char).
** Until the end of the "string", these functions should provide one character
** at a time, along with an pointer to a C-string containing the quoting
** characters, and a boolean array with every member of it initialized to FALSE.
**
** Once the last character has been provided to update_states, functions should
** call return_result with the boolean array as its argument, which will return
** the index of the incomplete pair or the size of the string if the string is
** correctly quoted.
** -1 is returned if an error occured.
*/

int		state_of_quote(char const *str, char const *quote_chars);
int		return_result(t_bool const *states, size_t size);
void	update_states(t_bool *states, char c,
		char const *quotes_char);

#endif
