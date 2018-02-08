/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shx_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 09:15:01 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/05 09:17:00 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	shx_list(struct s_sh_list *const list, struct s_sh_global *const global)
{
	if (list != NULL)
		(void)shx_and_or(list->and_or);
	return (0);
}
