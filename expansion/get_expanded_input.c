#include "lexer.h"
#include "history.h"
#include "expansion.h"

static int	check_bang_is_expandable(const int state, const char *c)
{
	if (*c == '!'
			&& *(c + 1) != ' '
			&& *(c + 1) != '\n'
			&& *(c - 1) != '\\'
			&& state != QUOTE
			&& state != COMMENT)
		return (1);
	return (0);
}

char		*get_expanded_input(t_lexer *lexer, t_history *history, char *input,
								size_t input_size)
{
	t_string	exp_input = {ft_strnew(input_size), 0, input_size};

	if (!(exp_input.str))
		return (NULL);
	lexer->input = input;
	while (*(lexer->input))
	{
		get_event(lexer);
		lexer->state = g_lexer[lexer->state][lexer->event].new_state;
		if (exp_input.len == exp_input.size)
			if (ft_realloc_str(&exp_input) == MALLOC_FAIL)
				return (NULL);
		if (check_bang_is_expandable(lexer->state, lexer->input))
			handle_bang(history, &lexer->input, &exp_input);
		else
			exp_input.str[exp_input.len++] = *(lexer->input);
		lexer->input++;
	}
	/*if (exp_input.len == exp_input.size)
		if (ft_realloc_str(&exp_input) == MALLOC_FAIL)
			return (NULL);
	exp_input.str[exp_input.len++] = '\n';*/
	lexer->state = INIT;
	lexer->event = 0;
	return (exp_input.str);
}
