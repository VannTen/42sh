/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_left_factor_compute_implem.h                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:22:03 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/14 17:25:18 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYM_LEFT_FACTOR_COMPUTE_IMPLEM_H
# define SYM_LEFT_FACTOR_COMPUTE_IMPLEM_H
# include "libft.h"
# include <stdarg.h>

/*
** Implementation header for sym_left_factor_compute.c
** Provides a function suitable as list iterators to insert contents in a trie.
*/

t_bool	insert_in_trie(void *prod, va_list args);

#endif
