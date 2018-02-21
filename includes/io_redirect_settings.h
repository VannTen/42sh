/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_redirect_settings.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 09:33:00 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/21 22:41:06 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_REDIRECT_SETTINGS_H
# define IO_REDIRECT_SETTINGS_H

# include <fcntl.h>
# include "shell_ast/io_redirect.h"

struct s_io_param
{
	char const			*ionum;
	enum e_sh_io_type	type;
	int					flags;
	int					mode;
	int					variant;
};

struct	s_io_reference
{
	int					label;
	struct s_io_param	param;
};

# define CLOBBER_OFLAGS O_WRONLY | O_CREAT | O_TRUNC
# define CLOBBER_PARAM { "1", e_sh_io_type_file, CLOBBER_OFLAGS, 0644, 0 }

# define GREAT_OFLAGS O_WRONLY | O_CREAT | O_TRUNC
# define GREAT_PARAM { "1", e_sh_io_type_file, GREAT_OFLAGS, 0644, 1 }

# define DGREAT_OFLAGS O_WRONLY | O_APPEND | O_CREAT
# define DGREAT_PARAM { "1", e_sh_io_type_file, DGREAT_OFLAGS, 0644, 0 }

# define LESSGREAT_OFLAGS O_RDWR | O_CREAT
# define LESSGREAT_PARAM { "0", e_sh_io_type_file, LESSGREAT_OFLAGS, 0644, 0 }

# define LESS_OFLAGS O_RDONLY
# define LESS_PARAM { "0", e_sh_io_type_file, LESS_OFLAGS, 0, 0 }

# define DLESS_OFLAGS O_RDONLY | O_CREAT | O_EXCL
# define DLESS_PARAM { "0", e_sh_io_type_here, DLESS_OFLAGS, 0644, 0 }

# define DLESSDASH_OFLAGS O_RDONLY | O_CREAT | O_EXCL
# define DLESSDASH_PARAM { "0", e_sh_io_type_here, DLESSDASH_OFLAGS, 0644, 1 }

# define GREATAND_PARAM { "1", e_sh_io_type_aggregate, 0, 0, 0 }

# define LESSAND_PARAM { "0", e_sh_io_type_aggregate, 0, 0, 0 }

char	*create_heredoc(char const *const here_end);

#endif
