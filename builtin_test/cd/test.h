/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 14:58:54 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/19 17:58:06 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

#include "env.h"

# define TEST_MAX_ENV_LEN 8;

struct	s_test_dir
{
	char const	*name;
	int			mode;
};

struct	s_test_setup
{
	struct s_test_dir	*dirs;
	size_t				dir_count;
	char const			*starting_dir;
	struct s_env			env;
};

struct	s_test_result
{
	int				ret;
	struct s_env	env;
	char const		*cwd;
};

struct	s_test_data
{
	struct s_test_setup		setup;
	char					**argv;
	struct s_test_result	expected_result;
};

# define TEST_COUNT (sizeof(g_tests) / sizeof(*g_tests))
# define TEST_DIR "/tmp/cd_tests"

static struct s_test_data const	g_tests[] = {
	{
		.setup = {
			.dirs = (struct s_test_dir[]){
				{
					.name = "dir",
					.mode = 0755
				}
			},
			.dir_count = 1,
			.starting_dir = ".",
			.env = {
				.env_list = NULL,
				.env_array = NULL,
				.env_len = 0,
				.has_changed = 1
			}
		},
		.argv = (char *[]){
			"cd", "dir", NULL
		},
		.expected_result = {
			.ret = 0,
			.env = {
				.env_list = (struct s_env_list[]){
					{
						.name = "PWD",
						.value = "/tmp/cd_tests/dir",
					},
				},
				.env_array = NULL,
				.env_len = 1,
				.has_changed = 1
			},
			.cwd = "/private/tmp/cd_tests/dir"
		}
	}
};

#endif
