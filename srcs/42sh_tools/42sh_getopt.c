/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh_getopt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heynard <heynard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 20:07:00 by heynard           #+#    #+#             */
/*   Updated: 2018/01/11 20:07:01 by heynard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int			add_opt(char **opt,
							const char *arg,
							const char *sample,
							int *error)
{
    size_t          position;
    size_t          j;

    position = 0;
    j = 1;
    while ((*opt)[position])
        position++;
	while (arg[j])
	{
		if (ft_strchr(sample, arg[j]))
		{
			if (!ft_strchr(*opt, arg[j]))
				(*opt)[position++] = arg[j];
		}
		else
		{
			ft_strdel(opt);
			*opt = NULL;
			*error = 2;
			return (1);
		}
		j++;
	}
	return (0);
}

/*
** parameters : const char **argv list of arguments passed to the builtin,
** can be NULL, return NULL in this case.
**				const char *sample list of all the possible values.
**				int *error, set to 1 for malloc error, 2 for value error.
** output : char * listing all the options found by ft_getopt ("abcDEF..."
** for example). If no option have been found, return  empty string instead.
** If an error occured, return NULL.
** If the argv tab isn't terminated by a NULL value, the behavior of this
** function is undifined.
*/

char              *ft_getopt(const char **argv,
							const char *sample,
							int *error)
{
    char           *opt;
	size_t			nb_max_opt;
    size_t          i;

    opt = NULL;
    if (argv && *argv)
    {
		nb_max_opt = ft_strlen(sample);
        if ((opt = (char *)malloc(sizeof(char) * nb_max_opt)) == NULL)
		{
			*error = 1;
            return (NULL);
		}
        ft_bzero((void *)opt, nb_max_opt);
        i = 1;
        while (argv[i] && ft_strcmp(argv[i], "--") &&
				ft_strcmp(argv[i], "-") && argv[i][0] == '-')
		{
            if (add_opt(&opt, argv[i], sample, error))
				break ;
			i++;
		}
    }
	*error = 0;
    return (opt);
}
