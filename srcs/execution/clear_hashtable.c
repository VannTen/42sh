/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_hashtable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 15:02:56 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/28 15:03:16 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	clear_hashtable(void)
{
	t_bsh	*const bsh = get_shell_data();

	if (bsh)
		free_hash_table(&bsh->hashtable);
}
