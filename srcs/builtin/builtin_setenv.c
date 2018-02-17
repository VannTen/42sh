/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 08:35:53 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/16 09:23:41 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				builtin_setenv(char **argv, t_env *env)
{
	if (!argv || !argv[0] || !env)
	{
		ft_dprintf(STDERR_FILENO, "setenv: invalid parameters\n");
		return (42);
	}
	if (!argv[1])
		return (display_global_env(env->env_list));
	if (is_valid_env_variable_name(argv[1]))
		return (append_variable_to_env(argv[1], argv[2] ? argv[2] : ""));
	else
	{
		ft_dprintf(STDERR_FILENO, "%s: not a valid variable name\n", argv[1]);
		return (42);
	}
}
