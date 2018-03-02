/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_hash_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 11:36:52 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/02 12:30:52 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"
#include "libft.h"

t_hash_data	*new_hash_data(const char *bin_name, const char *bin_path)
{
	t_hash_data	*new_data;

	if ((new_data = malloc(sizeof(t_hash_data))) == NULL)
		return (NULL);
	new_data->name = ft_strdup(bin_name);
	new_data->path = ft_strdup(bin_path);
	new_data->hits = 1;
	if (!new_data->name || !new_data->path)
	{
		ft_strdel(&new_data->name);
		ft_strdel(&new_data->path);
		ft_memdel((void**)&new_data);
		return (NULL);
	}
	return (new_data);
}
