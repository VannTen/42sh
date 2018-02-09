#include "shell.h"

const t_transit	g_expander[MAX_STATE1][MAX_EVENT1] = {
	{{STD1, {skip, skip}},
		{DQUOTE1, {skip, skip}},
		{QUOTE1, {skip, skip}},
		{STD1, {handle_dollar, append}},
		{STD1, {handle_tilde, append}},
		{STD1, {handle_bckslsh, handle_bckslsh}},
		{STD1, {append, append}}},

	{{STD1, {NULL, NULL}},
		{DQUOTE1, {skip, skip}},
		{QUOTE1, {skip, skip}},
		{STD1, {handle_dollar, append}},
		{STD1, {handle_tilde, append}},
		{STD1, {handle_bckslsh, handle_bckslsh}},
		{STD1, {append, append}}},

	{{STD1, {NULL, NULL}},
		{STD1, {skip, skip}},
		{DQUOTE1, {append, append}},
		{DQUOTE1, {handle_dollar, append}},
		{DQUOTE1, {append, append}},
		{DQUOTE1, {handle_bckslsh_dquote, append}},
		{DQUOTE1, {append, append}}},

	{{QUOTE1, {NULL, NULL}},
		{QUOTE1, {append, append}},
		{STD1, {skip, skip}},
		{QUOTE1, {append, append}},
		{QUOTE1, {append, append}},
		{QUOTE1, {append, append}},
		{QUOTE1, {append, append}}},
};


char	*expanded_str(t_expander *exp, char *string, const size_t type)
{
	char	*str;

	exp->state = INIT1;
	exp->event = START1;
	exp->tmp = string;
	while (*(exp->tmp))
	{
		if (g_expander[exp->state][exp->event].p_transit[type](exp) ==
				MALLOC_FAIL)
			return (NULL);
		(exp->state != INIT1) ? exp->tmp++ : 0;
		exp->state = g_expander[exp->state][exp->event].new_state;
		exp->event = get_event_exp(*(exp->tmp));
	}
	if (!(str = ft_strdup(exp->buffer)))
		return (NULL);
	exp->tmp = NULL;
	exp->buffer_len = 0;
	ft_bzero(exp->buffer, exp->buffer_size);
	return (str);
}
