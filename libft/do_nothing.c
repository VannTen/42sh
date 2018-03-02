/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_nothing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 12:18:08 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/11 15:44:32 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	do_nothing(void *precious_content)
{
	(void)precious_content;
}

void	no_destroy(void **precious_content)
{
	*precious_content = NULL;
}
