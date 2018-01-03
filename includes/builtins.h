/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 18:33:13 by bjanik            #+#    #+#             */
/*   Updated: 2017/12/09 15:03:08 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H
# include "libft.h"
# include "errno.h"

# define IS_OPTION(x, y) ft_strchr(x, y)
# define EXPORT_OPTIONS "n"
# define HISTORY_OPTIONS "c"
# define LOCAL_VAR 0
# define EXPORT_VAR 1

typedef struct		s_env
{
	char			*var_name;
	char			*var_value;
	short int		exportable;
	struct s_env	*next;
}					t_env;

typedef struct		s_builtins
{
	char			*b_name;
	int				(*builtin)(t_env **, char **);
}					t_builtins;

int					cmd_is_builtin(char **cmd);
t_env				*env_to_lst(char **environ);
t_env				*create_node(char *env_var, int exportable);
void				push_back_env(t_env **env, char *env_var, int exportable);
int					env_size(t_env *env);
int					display_env(t_env *env);
t_env				*mod_env(t_env *env);
char				**env_to_tab(t_env *env);
void				clear_env(t_env **env);
t_env				*ft_getenv(t_env *env, char *name);
void				set_var(t_env **env, char *var, int export);
int					ft_export(t_env **env, char **cmd);
int					ft_cd(t_env **env, char **cmd);
int					ft_setenv(t_env **env, char **cmd);
int					ft_unsetenv(t_env **env, char **cmd);
int					ft_env(t_env **env, char **cmd);
int					ft_echo(t_env **env, char **cmd);
int					ft_exit(t_env **env, char **cmd);
int					ft_history(t_env **env, char **cmd);

char				check_arg_opt(char *arg_opt, char *avail_opt, char *opts);

#endif
