/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_modifier_defs.h	                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 19:03:56 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/20 16:57:23 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LENGTH_MODIFIER_DEFS_H
# define LENGTH_MODIFIER_DEFS_H
# define CONST_LENGTH_MODIF_INTIALIZER "\0llhhjtzq"

typedef enum	e_length_modifier
{
	NONE,
	LONG,
	VERY_LONG,
	SHORT,
	VERY_SHORT,
	MAX_INT,
	PTR_DIFF,
	SIZE,
	QUAD,
	LENGTH_MODIFIER_NBR
}				t_length_modifier;

#endif
