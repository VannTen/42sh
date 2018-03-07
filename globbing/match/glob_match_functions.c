/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob_match_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heynard <heynard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:13:47 by heynard           #+#    #+#             */
/*   Updated: 2018/02/02 15:13:48 by heynard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ft_glob.h"

static void			glob_match_diff_back(t_match *m,
										char **pattern,
										char **str)
{
	*pattern = m->lastw;
	m->p = **pattern;
	*str = m->lasts;
	m->s = *(m->lasts);
	if (m->p == '\0')
		m->fake_continue = -1;
	else if (m->p == m->s || m->p == '?')
		(*pattern)++;
	if (m->fake_continue == 0)
	{
		m->lasts = ++(*str);
		m->sqbracket = 0;
		m->fake_continue = 1;
	}
}

void				glob_match_diff(t_match *m,
									char **pattern,
									char **str)
{
	if (m->s != m->p && (m->p != '?' || m->bslash))
	{
		if (m->p == '*' && m->bslash == 0)
		{
			m->lastw = ++(*pattern);
			m->lasts = (*str);
			if (*(m->lastw) == '\\')
			{
				m->lastw++;
				m->bslash = 1;
			}
			m->fake_continue = 1;
		}
		else if (m->lastw)
			glob_match_diff_back(m, pattern, str);
		else
		{
			m->match = 0;
			m->fake_continue = -1;
		}
	}
}

void				glob_match_quote(t_match *m,
										char **pattern,
										char **str,
										char q)
{
	while (1)
	{
		(*pattern)++;
		m->s = **str;
		m->p = **pattern;
		if (m->p == q && m->bslash == 0)
		{
			(*pattern)++;
			m->fake_continue = 1;
			break ;
		}
		else if (m->p == '\\' && m->bslash == 0)
		{
			m->bslash = 1;
			(*pattern)++;
			continue ;
		}
		else if (m->p != m->s)
		{
			m->match = 0;
			m->fake_continue = -1;
			break ;
		}
		(*str)++;
	}
}

void				glob_no_fake_continue(t_match *m,
										char **pattern,
										char **str)
{
	m->sqbracket = 0;
	m->bslash = 0;
	(*pattern)++;
	(*str)++;
}

void				init_glob_match(t_match *m)
{
	m->match = 1;
	m->bslash = 0;
	m->sqbracket = 0;
	m->lastw = NULL;
	m->lasts = NULL;
	m->fake_continue = 0;
}
