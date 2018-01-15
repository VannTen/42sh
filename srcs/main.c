/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:38:49 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/15 12:51:52 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int main(int argc, char **argv, char **environ)
{
	t_env	env;

	env.env_list = convert_environ_to_list(environ);
	env.env_len = ft_tab_len(environ);
	env.env_array = convert_env_to_array(env.env_list, env.env_len);
	ft_printf("--------------------------------\n");
	ft_printf("--------------------------------\n");
	display_env(env.env_list, GLOBAL);
	append_variable_to_env(&env, "TOTO", "456", 1);
	append_variable_to_env(&env, "TATA", "666", 1);
	append_variable_to_env(&env, "TATA", "444", 1);
	append_variable_to_env(&env, "TOTO", "888", 1);
	append_variable_to_env(&env, "TOTO", "777", 1);
	append_variable_to_env(&env, "TOTO", "666", 1);
	append_variable_to_env(&env, "TOTO", "666", 1);
	append_variable_to_env(&env, "TOTO", "111", 1);
	ft_printf("--------------------------------\n");
	ft_printf("--------------------------------\n");
	display_env(env.env_list, GLOBAL);
	ft_printf("--------------------------------\n");
	ft_printf("--------------------------------\n");
	remove_variable_from_env(&env, "TERM_SESSION_ID");
	remove_variable_from_env(&env, "OLDPWD");
	remove_variable_from_env(&env, "TATA");
	/*remove_variable_from_env(&env, "Apple_PubSub_Socket_Render");
	remove_variable_from_env(&env, "TOTO");
	remove_variable_from_env(&env, "OLDPWD");
	remove_variable_from_env(&env, "TATA");
	remove_variable_from_env(&env, "TOTO");*/
	display_env(env.env_list, GLOBAL);
	ft_printf("--------------------------------\n");
	ft_printf("--------------------------------\n");
	append_variable_to_env(&env, "TATA", "666", 1);
	append_variable_to_env(&env, "TUTU", "222", 1);
	append_variable_to_env(&env, "TITI", "444", 1);
	display_env(env.env_list, GLOBAL);
	remove_variable_from_env(&env, "TATA");
	ft_printf("--------------------------------\n");
	ft_printf("--------------------------------\n");
	display_env(env.env_list, GLOBAL);
	while (42);

	return (0);
}


