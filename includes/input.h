/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 17:57:42 by bjanik            #+#    #+#             */
/*   Updated: 2017/12/04 16:46:43 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H
# include "libft.h"
# include "term.h"
# include "termcap.h"
# include "termios.h"
# include "history.h"
# include "fcntl.h"

# define MAX_KEY_LENGTH 6
# define MAX_PROMPT_SIZE 256
# define INITIAL_BUFFER_SIZE 4096
# define STANDARD 0
# define SELECTION 1

# define ARROW_RIGHT "\x1B[C"
# define ARROW_LEFT "\x1B[D"
# define ARROW_UP "\x1B[A"
# define ARROW_DOWN "\x1B[B"

# define CTRL_RIGHT "\x1B[1;2C"
# define CTRL_LEFT "\x1B[1;2D"
# define CTRL_UP "\x1B[1;2A"
# define CTRL_DOWN "\x1B[1;2B"
# define CTRL_A "\x1"
# define CTRL_B "\x2"
# define CTRL_D "\x4"
# define CTRL_E "\x5"
# define CTRL_F "\x6"
# define CTRL_O "\xF"
# define CTRL_P "\x10"
# define CTRL_R "\x12"
# define CTRL_T "\x14"
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

typedef struct	s_input
{
	char		*buffer;
	char		*buf_tmp;
	char		*buf_copy;
	int			buffer_len;
	int			buffer_size;
	int			cursor_pos;
	char		read_buffer[MAX_KEY_LENGTH + 1];
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

t_input			*init_input(t_term *term, t_history *history);
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
void			exit_ctrl_d(void);
int				handle_history_search(t_input *input);
int				switch_input_state(t_input *input);
int				select_right(t_input *input);
int				select_left(t_input *input);
int				skip_key(t_input *input);
void			cp_history_to_buffer(t_input *input);
int				cursor_on_last_line(t_input *input);
int				get_key(t_input *input);
int				get_displayed_lines(t_input *input);
void			display_buffer(t_input *input, int cursor);
void			display_line(t_input *input, int cursor);
void			realloc_buffer(t_input *input);
void			reset_buffer(t_input *input);
int				copy_selection(t_input *input);
int				cut_selection(t_input *input);
int				paste_selection(t_input *input);
#endif
