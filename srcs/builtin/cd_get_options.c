/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_get_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:51:20 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/06 16:48:49 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "builtin_cd.h"

static int	cd_bad_opt(char c)
{
	ft_putstr_fd("42sh: cd: - ", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd(": invalid option\n", 2);
	return (1);
}

static int	cdopt_parse_str(char const *str, int *const options_loc)
{
	char const	cd_optstr[] = "LP";
	char const	*tmp;
	size_t		index;

	index = 1;
	while (str[index] != 0)
	{
		if (!(tmp = ft_strchr(cd_optstr, str[index])))
			return (cd_bad_opt(str[index]));
		else
			*options_loc = 1 << (cd_optstr - tmp);
		index += 1;
	}
	return (0);
}

size_t		cd_get_options(char **args, int *const options_loc)
{
	char const	*str;
	size_t		index;

	if (args == NULL || args[0] == NULL)
		return (1);
	index = 1;
	while ((str = args[index]) != NULL && str[0] == '-')
	{
		if (str[1] == 0)
		{
			*options_loc |= e_cdopt_oldpwd;
			return (index);
		}
		if (str[1] == '-' && str[2] == 0)
			return (index + 1);
		if (cdopt_parse_str(str, options_loc))
			return (0);
		index += 1;
	}
	return (index);
}
