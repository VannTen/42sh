#ifndef EXPANSION_H
# define EXPANSION_H
# define INITIAL_SIZE 256
# include "libft.h"
# include "env.h"

# define NOT_HERE_END_EXP 0
# define HERE_END_EXP 1

enum			exp_state
{
	INIT1,
	STD1,
	DQUOTE1,
	QUOTE1,
	MAX_STATE1,
};

enum			exp_event
{
	START,
	EV_DQUOTE1,
	EV_QUOTE1,
	EV_DOLLAR,
	EV_TILDE,
	EV_BACKSLASH1,
	EV_REG_CHAR1,
	MAX_EVENT1,
};

typedef struct	s_expander
{
	int			state;
	int			event;
	t_env_list	*env;
	char		*buffer;
	int			buffer_len;
	int			buffer_size;
	char		*tmp;
}				t_expander;

typedef struct	s_transit
{
	int			new_state;
	int			(*p_transit[2])(t_expander *exp);
}				t_transit;

int				append(t_expander *exp);
int				skip(t_expander *exp);
int				handle_tilde(t_expander *exp);
int				handle_dollar(t_expander *exp);
int				handle_bckslsh(t_expander *exp);
int				handle_bckslsh_dquote(t_expander *exp);
int				get_event_exp(char c);
int				realloc_exp_buffer(t_expander *exp);

const t_transit		g_expander[MAX_STATE1][MAX_EVENT1];
#endif
