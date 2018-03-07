/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heynard <heynard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:54:52 by heynard           #+#    #+#             */
/*   Updated: 2018/03/07 15:47:59 by heynard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GLOB_H
# define FT_GLOB_H

#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

/*
** matching algorithm structures
*/

typedef struct			s_square_bracket
{
	int			bslash;
	int			no;
	int			n;
	int			i;
	char		tabl[4096];
}						t_square_bracket;

typedef struct			s_match
{
	int			match;
	int			bslash;
	int			sqbracket;
	char		s;
	char		p;
	int			fake_continue;
	char		*lastw;
	char		*lasts;
}						t_match;

/*
** structure to store the files and directories names in a directory
*/

typedef struct			s_dir_content
{
	char					*name;
	struct s_dir_content	*next;
}						t_dir_content;

/*
** brackets structures
*/

typedef struct			s_bracket
{
	struct s_biglist	*biglist;
	char				**result;
	short int			bs;
	unsigned int		current;
	unsigned int		pos;
}						t_bracket;

typedef struct			s_biglist
{
	struct s_blist		*blist;
	struct s_biglist	*next;
}						t_biglist;

typedef struct			s_blist
{
	char				**r_bracket;
	short int			tmp;
	struct s_blist		*next;
}						t_blist;

typedef struct			s_bracket_functions
{
	char				*tofree;
	int					up;
	int					i;
	size_t				pos;
	char				**result;
}						t_bracket_functions;

/*
** globbing
*/

char					**ft_glob(char *str);
char					**glob_extend(char *pattern, t_dir_content *list);

/*
** tools functions could be add in libft
*/

void					ft_free2dstr(char **split);
char					**ft_2dstrjoin(char **t1, char **t2);
char					*ft_strchr_spec(char *s, int c, char spec);
char					*glob_strcpy_spec(char *str, char spec);

/*
** directory content functions
*/

t_dir_content			*get_dir_content(char *name, int slash, int hidden);
void					free_dir_content(t_dir_content *content);
t_dir_content			*add_dir_content(const char *name, t_dir_content *cont,
										const char *path);
t_dir_content			*extend_candidat_slash(t_dir_content *list,
										char *pattern);

/*
** bracket
*/

char					**glob_bracket(char *str);
t_blist					*add_blist(t_biglist *b, t_blist *n);
t_biglist				*add_biglist(t_bracket *bracket, t_biglist *n);
void					free_biglist(t_biglist *b);
int						count_biglist(t_biglist *b);
char					**fill_final(char **final, size_t pos,
										char **result, t_biglist *b);
char					**glob_bracket_bonding(t_bracket *b);
int						bracket_verify(char *str, size_t i);
t_biglist				*create_blist_recursive(char *str,
												int i,
												t_biglist *newbig,
												char limit);
void					glob_move_to_next_char(char *str, size_t *i, char t);
int						glob_parse_bracket(char *str, size_t *i, t_bracket *b);
void					bracket_result_alloc(t_bracket *b, size_t len);

/*
** matcher functions
*/

int						ft_glob_match(char *str, char *pattern);
int						ft_glob_match_sqbracket(char s, char **pattern);
void					glob_match_diff(t_match *m, char **pattern,
										char **str);
void					glob_no_fake_continue(t_match *m, char **pattern,
										char **str);
void					glob_match_quote(t_match *m,
										char **pattern,
										char **str,
										char q);
void					init_glob_match(t_match *m);

#endif
