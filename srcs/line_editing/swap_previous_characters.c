
#include "shell.h"

int	swap_previous_characters(t_input *input)
{
	char	tmp;

	if (input->cursor_pos > 1)
	{
		tmp = input->buffer[input->cursor_pos - 1];
		input->buffer[input->cursor_pos - 1] =
					input->buffer[input->cursor_pos - 2];
		input->buffer[input->cursor_pos - 2] = tmp;
	}
	display_line(input, input->cursor_pos);
	return (0);
}
