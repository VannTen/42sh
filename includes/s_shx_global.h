/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_shx_global.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 13:26:21 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/08 13:58:37 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_SHX_GLOBAL_H
# define S_SHX_GLOBAL_H

struct s_shx_global
{
	void 			*env;
	void			*hash_table;
	unsigned char	latest_ret;
};

#endif
