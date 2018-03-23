/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 09:17:31 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/19 17:59:35 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_env.h"
#include "builtins.h"
#include "test.h"
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

static int	reset_test_conditions(struct s_test_setup setup, struct s_env *env)
{
	size_t	i;

	clear_env_list(&env->env_list);
	env->env_len = 0;
	chdir(TEST_DIR);
	i = setup.dir_count;
	while (0 < i)
	{
		i -= 1;
		if (rmdir(setup.dirs[i].name))
			return (0);
	}
	return (0);
}

static int	test_setup(struct s_test_setup setup, struct s_env *env)
{
	size_t	i;

	i = 0;
	while (i < setup.dir_count)
	{
		if (0 == mkdir(setup.dirs[i].name, setup.dirs[i].mode))
			i += 1;
		else
			return (1);
	}
	if (setup.starting_dir && chdir(setup.starting_dir))
		return (1);
	env->env_array = NULL;
	env->has_changed = 1;
	env->env_len = setup.env.env_len;
	env->env_list = dup_env_list(setup.env.env_list);
	if (setup.env.env_list && !env->env_list)
		return (1);
	return (0);
}

#include <limits.h>
#include <stdio.h>
static void	verify_result(int const ret, t_env const env,
		struct s_test_result const expected_result)
{
	char					cwd_buf[PATH_MAX + 1];
	struct s_env_list const	*env_list;
	struct s_env_list const	*ref_env_list;

	if (ret != expected_result.ret)
		printf("bad return value!\n");
	env_list = env.env_list;
	ref_env_list = expected_result.env.env_list;
	while (env_list && ref_env_list)
	{
		if (env_list->name == NULL || env_list->value == NULL
				|| strcmp(env_list->name, ref_env_list->name)
				|| strcmp(env_list->value, ref_env_list->value))
			printf("bad environment!\nyou: %s=%s\nref: %s=%s\n", env_list->name,
					env_list->value, ref_env_list->name, ref_env_list->value);
		env_list = env_list->next;
		ref_env_list = ref_env_list->next;
	}
	memset(cwd_buf, 0, sizeof(cwd_buf));
	if (getcwd(cwd_buf, PATH_MAX + 1))
	{
		if (strcmp(cwd_buf, expected_result.cwd))
			printf("bad cwd!\n");
	}
}

int			main(void)
{
	struct s_env		env;
	size_t				i;
	int					cd_ret;

	mkdir(TEST_DIR, 0755);
	if (!chdir(TEST_DIR))
	{
		i = 0;
		while (i < TEST_COUNT)
		{
			if (0 == test_setup(g_tests[i].setup, &env))
			{
				cd_ret = builtin_cd(g_tests[i].argv, &env);
				verify_result(cd_ret, env, g_tests[i].expected_result);
			}
			if (reset_test_conditions(g_tests[i].setup, &env))
			{
				rmdir(TEST_DIR);
				return (1);
			}
			i += 1;
		}
		rmdir(TEST_DIR);
		return (0);
	}
	else
	{
		rmdir(TEST_DIR);
		return (1);
	}
}
