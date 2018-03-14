/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob_candidat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heynard <heynard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 16:04:24 by heynard           #+#    #+#             */
/*   Updated: 2018/03/07 16:35:58 by heynard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ft_glob.h"

static char		*glob_match_sqbracket(t_match *m, char *pattern, char **str)
{
	m->sqbracket = ft_glob_match_sqbracket(m->s, &pattern);
	if (m->sqbracket == 1)
		m->fake_continue = 1;
	else if (m->sqbracket == 2 && !m->lastw)
	{
		m->match = 0;
		m->fake_continue = -1;
	}
	else if (m->sqbracket == 2 && m->lastw)
	{
		pattern = m->lastw;
		m->p = *pattern;
		*str = m->lasts;
		m->s = *(m->lasts);
		if (m->p == '\0')
			m->fake_continue = -1;
		else if (m->p == m->s || m->p == '?')
			pattern++;
		m->lasts = ++(*str);
		m->fake_continue = 1;
	}
	return (pattern);
}

static char		*glob_match_end_string(t_match *m, char *pattern)
{
	if (m->p == '\0')
		m->fake_continue = -1;
	else if (m->p == '*')
	{
		pattern++;
		m->fake_continue = 1;
	}
	else
	{
		m->match = 0;
		m->fake_continue = -1;
	}
	return (pattern);
}

static char		*glob_match_back_slash(t_match *m, char *pattern)
{
	m->bslash = 1;
	pattern++;
	m->fake_continue = 1;
	return (pattern);
}

int				ft_glob_match(char *str, char *pattern)
{
	t_match		m;

	init_glob_match(&m);
	while (1)
	{
		m.s = *str;
		m.p = *pattern;
		if (m.s == '\0')
			pattern = glob_match_end_string(&m, pattern);
		else if (m.p == '\\' && m.bslash == 0)
			pattern = glob_match_back_slash(&m, pattern);
		else if ((m.p == '"' || m.p == '\'') && m.bslash == 0)
			glob_match_quote(&m, &pattern, &str, m.p);
		else if (m.p == '[' && m.bslash == 0 && m.sqbracket != 1)
			pattern = glob_match_sqbracket(&m, pattern, &str);
		else
			glob_match_diff(&m, &pattern, &str);
		if (m.fake_continue == 0)
			glob_no_fake_continue(&m, &pattern, &str);
		else if (m.fake_continue == -1)
			break ;
		else
			m.fake_continue = 0;
	}
	return (m.match);
}
