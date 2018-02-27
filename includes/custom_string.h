/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_string.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 14:39:20 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/29 14:39:20 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUSTOM_STRING_H
# define CUSTOM_STRING_H

typedef struct		s_string
{
	char			*str;
	int				len;
	int				size;
}					t_string;

#endif
