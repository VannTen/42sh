/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_env_variable_name.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 08:57:00 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/16 09:23:29 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static t_bool	is_valid_env_variable_name_char(char const c)
{
	return (('A' <= c && c <= 'Z')
			|| ('a' <= c && c <= 'z')
			|| ('0' <= c && c <= '9')
			|| (c == '_'));
}

t_bool			is_valid_env_variable_name(char const *name)
{
	if (name && !ft_isdigit(name[0]))
	{
		i = 0;
		while (*name)
			if (!is_valid_variable_name_char(*name))
				return (FALSE);
			else
				name += 1;
		return (TRUE);
	}
	else
		return (FALSE);
}
