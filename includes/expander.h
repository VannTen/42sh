/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 12:59:26 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/28 13:24:11 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H
# define INITIAL_SIZE 256
# include "libft.h"
# include "env.h"

# define NOT_HERE_END_EXP 0
# define HERE_END_EXP 1

enum
{
	INIT_EXP,
	STD_EXP,
	DQUOTE_EXP,
	QUOTE_EXP,
	MAX_STATE_EXP,
};

enum
{
	START_EXP,
	EV_DQUOTE_EXP,
	EV_QUOTE_EXP,
	EV_DOLLAR_EXP,
	EV_TILDE_EXP,
	EV_BACKSLASH_EXP,
	EV_REG_CHAR_EXP,
	MAX_EVENT_EXP,
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
char			*expanded_str(t_expander *exp, char *str, const size_t type);
t_expander		*init_expander(t_env *env);

const t_transit		g_exp[MAX_STATE_EXP][MAX_EVENT_EXP];
#endif
