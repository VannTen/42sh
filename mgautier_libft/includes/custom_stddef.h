/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_stddef.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 10:31:49 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/12 17:02:49 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUSTOM_STDDEF_H
# define CUSTOM_STDDEF_H

/*
** Function pointers typedef for functions that operate on a set and require a
** specific type of actions to be performed on its elements
** These typedefs are mostly of use for the internal functions of the lib
** itself, providing a less verbose way of writing function pointers parameters
*/

typedef int		(*t_compare)(const void *ref, const void *to_comp);
typedef int		(*t_sum)(void *content);
typedef	void	(*t_destroy)(void **where_is_content);
typedef void	(*t_iter)(void *content);
typedef void	(*t_iter_two)(void *content, void *param_supp);
typedef void	(*t_print)(int fd, void const *content);

/*
** Define some useful macros
*/

# define NULL_EXPR (void)0

/*
** Pipe semantics
*/

enum {
	READ_END,
	WRITE_END
};

#endif
