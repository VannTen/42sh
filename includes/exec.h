/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 17:57:29 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/06 14:48:37 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H
# include "libft.h"
# include "parser.h"
# include "builtins.h"

# define COMMAND_NOT_FOUND 127
# define PERMISSION_DENIED 126
# define IS_DIRECTORY 125
# define READ 0
# define WRITE 1

typedef struct		s_redir
{
	char			*filename;
	char			*here_end;
	t_list			*heredoc_input[2];
	int				heredoc_pipe[2];
	int				fd;
	int				type;
	struct s_redir	*next;
}					t_redir;

typedef struct		s_exec
{
	t_list			*word_list;
	t_list			*last_word;
	int				word_count;
	char			**cmd;
	t_redir			*redir_list;
	t_redir			*last_redir;
	int				is_builtin;
	int				cmd_separator;
	struct s_exec	*next;
	struct s_exec	*prev;
}					t_exec;

typedef struct		s_pipes
{
	int				**pipes_fd;
	int				nb_pipes;
}					t_pipes;

int					redir_great(t_redir *redir);
int					redir_dgreat(t_redir *redir);
int					redir_less(t_redir *redir);
int					redir_greatand(t_redir *redir);
int					redir_lessand(t_redir *redir);
int					redir_heredoc(t_redir *redir);
int					handle_heredocs(t_exec *exec);
int					handle_redirection(t_exec *exec);
int					ambigous_redirect(char *filename);
char				**lst_to_tab(t_list *word_list, int word_count);
void				run_binary(t_exec *exec, t_env *env, int offset);
int					run_builtin(t_exec *exec, int offset);
t_pipes				*init_pipes(void);
int					get_pipes_fd(t_exec *exec, t_pipes *pipes);
void				create_pipes(t_pipes *pipes);
void				connect_processes_pipes(t_pipes *pipes, int i);
void				pipe_sequence(t_exec **exec, t_pipes *pipes);
void				save_fds(int *saved_fds);
void				restore_fds(int *saved_fds);
void				clear_exec(t_exec **exec);
#endif
