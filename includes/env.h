/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:50:58 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/15 11:37:33 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

# define LOCAL 0
# define GLOBAL 1
# define GLOBAL_AND_LOCAL 2
# define TRUE 1
# define FALSE 0

typedef struct s_env_list
{
	char				*name;
	char				*value;
	unsigned short		exportable;
	struct s_env_list	*next;
}						t_env_list;

typedef struct s_env
{
	struct s_env_list	*env_list;
	char				**env_array;
	size_t				env_len;
	unsigned short		has_changed;
}						t_env;

t_env_list				*ft_getenv(t_env_list *env_list,
						char const *const name);

char					**convert_env_to_array(t_env_list *env_list,
						const size_t len);

t_env_list				*convert_environ_to_list(char **const environ);

int						display_env(t_env_list const *env_list, const int flag);

int						append_variable_to_env(t_env *env, char *const name,
						char *const value, unsigned short exportable);

int						remove_variable_from_env(t_env *env, char *const name);
