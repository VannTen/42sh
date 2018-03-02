/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_defs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 13:28:57 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/31 13:30:12 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_DEFS_H
# define LST_DEFS_H
# include "lst_interface.h"

struct		s_lst
{
	void			*content;
	struct s_lst	*next;
};

#endif
