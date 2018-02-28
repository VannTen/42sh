#include "shell.h"

void	resize_term(int sigid)
{
	t_input	*input;

	(void)sigid;
	input = &get_shell_data()->input;
	get_term_size(input->term);
	handle_clear_screen(input);
}
