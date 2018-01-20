#include "libft.h"
#include "lexer.h"
#include "history.h"

int		handle_bang(t_history *history, char **input, t_string *exp_input);
char	*get_expanded_input(t_lexer *lexer, t_history *history, char *input,
							size_t input_size);
