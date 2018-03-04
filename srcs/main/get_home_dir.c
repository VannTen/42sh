
#include "shell.h"

char	*get_home_dir(void)
{
	struct passwd	*pw;

	if (!(pw = (struct passwd*)getpwuid(getuid())))
		return (NULL);
	return (pw->pw_dir);
}
