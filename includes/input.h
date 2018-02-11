/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 17:57:42 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/09 15:47:33 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H
# include "libft.h"
# include "history.h"
# include "term.h"
# include "termcap.h"
# include "termios.h"
# include "history.h"
# include "fcntl.h"

# define MAX_KEY_LENGTH 6
# define MAX_PROMPT_SIZE 256
# define INITIAL_BUFFER_SIZE 8192
# define STANDARD 0
# define SELECTION 1
# define COMPLETION 2

# define ARROW_RIGHT "\x1B[C"
# define ARROW_LEFT "\x1B[D"
# define ARROW_UP "\x1B[A"
# define ARROW_DOWN "\x1B[B"
# define CTRL_RIGHT "\x1B[1;2C"
# define CTRL_LEFT "\x1B[1;2D"
# define CTRL_UP "\x1B[1;2A"
# define CTRL_DOWN "\x1B[1;2B"
# define CTRL_A "\x1"
# define CTRL_D "\x4"
# define CTRL_E "\x5"
# define CTRL_F "\x6"
# define CTRL_R "\x12"
# define CTRL_U "\x15"
# define CTRL_X "\x18"
# define CLEAR_SCREEN "\xC"
# define ALT_GREAT "\x1B>"
# define ALT_LESS "\x1B<"
# define DELETE "\x1B[3~"
# define BACKSPACE "\x7F"
# define HOME "\x1B[H"
# define END "\x1B[F"
# define RETURN_C "\n"

# define REGULAR_INPUT 0
# define HEREDOC_INPUT 1
# define UNCLOSED_QUOTES 2
# define HISTORY_SEARCH 3

# define STOP_HEREDOC 1
# define UNEXPECTED_EOF 3
# define RETURN 4
# define CATCH_SIGINT 5

# define READ_FAIL -1

# define DIRECTORY 1
# define PATH 2

typedef struct		s_comp
{
	char			*prefix;
	char			*dirname;
	char			*basename;
	char			*comp_str;
	size_t			count;
	size_t			basename_len;
	t_list			*matches;
	t_list			*current;
	size_t			nb_matches;
	size_t			search_location;
	int				init_c_pos;
}					t_comp;

typedef struct	s_input
{
	char		*buffer;
	char		*buf_tmp;
	char		*buf_copy;
	int			buffer_len;
	int			buffer_size;
	int			cursor_pos;
	char		read_buffer[MAX_KEY_LENGTH + 1];
	t_comp		comp;
	t_term		*term;
	t_history	*history;
	int			fd;
	int			type;
	int			state;
	int			pivot;
}				t_input;

typedef struct	s_keys
{
	char		*key;
	int			(*handle_keystroke[2])(t_input *input);
}				t_keys;

int				putchar_termcaps(int c);
int				wait_for_input(t_input *input, int type);
int				init_input(t_input *input, t_term *term, t_history *history);
int				init_buffers(t_input *input);
int				get_key(t_input *input);
int				handle_arrow_left(t_input *input);
int				handle_arrow_right(t_input *input);
int				handle_arrow_up(t_input *input);
int				handle_arrow_down(t_input *input);
int				handle_ctrl_left(t_input *input);
int				handle_ctrl_right(t_input *input);
int				handle_ctrl_up(t_input *input);
int				handle_ctrl_down(t_input *input);
int				handle_backspace(t_input *input);
int				handle_delete(t_input *input);
int				handle_home(t_input *input);
int				handle_end(t_input *input);
int				handle_return(t_input *input);
int				handle_reg_char(t_input *input, char c);
int				handle_alt_less(t_input *input);
int				handle_alt_great(t_input *input);
int				handle_clear_screen(t_input *input);
int				handle_clear_line(t_input *input);
int				handle_eof(t_input *input);
void			exit_ctrl_d(t_input *input);
int				handle_history_search(t_input *input);
int				switch_input_state(t_input *input);
int				select_right(t_input *input);
int				select_left(t_input *input);
int				skip_key(t_input *input);
int				clear_lines(t_input *input, const char *str);
void			cp_history_to_buffer(t_input *input);
int				cursor_on_last_line(t_input *input);
int				get_displayed_lines(t_input *input);
void			display_buffer(t_input *input, int cursor);
void			display_line(t_input *input, int cursor);
int				realloc_buffer(t_input *input);
void			reset_buffer(t_input *input);
int				copy_selection(t_input *input);
void			cut_from_buffer(t_input *input, const int cursor,
								const int pivot, const size_t len);
int				cut_selection(t_input *input);
int				paste_selection_buffer(t_input *input);
int				paste_str_in_buffer(const char * copy, t_input *input);


void			get_prompt(t_term *term);
void			print_prompt(t_input *input, char *color);
void			display_basic_prompt(t_input *input);


/*
** Completion part
*/

int					completion(t_input *input);
int					init_completion_data(t_comp *comp, char *buffer,
					const int cursor_pos);
t_list				*open_and_read_directory(t_comp *comp,
					const char *directory);
int					completion_search_path(t_comp *comp);
t_list				*completion_search_in_env(t_comp *comp);
int					completion_display(t_comp *comp, t_input *input);
int					reset_completion_data(t_comp *comp);
char				*ft_basename(const char *path);
char				*ft_dirname(const char *path);
t_list				*merge_sort_matches(t_list *matches);
#endif
