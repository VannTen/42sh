/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_interface.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:27:26 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/19 11:35:42 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISC_INTERFACE_H
# define MISC_INTERFACE_H

/*
** Dummy destroyers or iterators, for testing or when a content should not be
** destroyed upon destruction of its contenainer (when it is referenced
** somewhere else, for example.
** Implementation file : do_nothing.c
*/

void	do_nothing(void *precious_content);
void	no_destroy(void	**precious_content);

/*
** Dummy error functions, for testing.
** Only to be used temporary.
** Implementation file : misc_error.c
*/

void	fatal(void);

#endif
