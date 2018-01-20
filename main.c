#include "lexer.h"
#include "history.h"
#include "expansion.h"
#include "libft.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

void	display_tokens(t_token *tokens)
{
	while (tokens)
	{
		if (tokens->next)
			ft_printf("[%s] ->", tokens->value);
		else
			ft_printf("[%s]\n", tokens->value);
		tokens = tokens->next;
	}
}

int	main(int argc, char **argv)
{
	char	*input = readline("42sh > ");

	t_lexer *lex = init_lexer();
	lexer(lex, input);
	display_tokens(lex->tokens[0]);
	t_history history;
	char	*expanded_input;

	history.history = (char**)malloc(sizeof(char*) * (3 + 1));
	history.len = 0;
	history.size = 3;


	add_cmd_to_history(&history, "ls -l |cat -e");
	add_cmd_to_history(&history, "wc -l");
	add_cmd_to_history(&history, "touch toto");
	add_cmd_to_history(&history, "cd /Applications");
	add_cmd_to_history(&history, "cd /tmp");
	ft_printf("%p\n", history.history[history.len]);
	display_history(history);
	expanded_input = get_expanded_input(lex, &history, input,
								ft_strlen(input));
	ft_printf("\nEXP_INPUT = [%s]\n", expanded_input);
	return (0);
}
