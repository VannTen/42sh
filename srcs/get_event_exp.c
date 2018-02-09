#include "shell.h"

int	get_event_exp(char c)
{
	if (c == '"')
		return (EV_DQUOTE1);
	else if (c == '\'')
		return (EV_QUOTE1);
	else if (c == '$')
		return (EV_DOLLAR);
	else if (c == '~')
		return (EV_TILDE);
	else if (c == '\\')
		return (EV_BACKSLASH1);
	else if (c != '\0')
		return (EV_REG_CHAR1);
}
