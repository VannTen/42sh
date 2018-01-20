/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:51:57 by bjanik            #+#    #+#             */
/*   Updated: 2017/12/04 14:16:51 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdarg.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <sys/wait.h>
# include <sys/types.h>

# define BLK "\x1B[30m"
# define RED "\x1B[31m"
# define GRN "\x1B[32m"
# define YEL "\x1B[33m"
# define BLU "\x1B[34m"
# define MAG "\x1B[35m"
# define CYN "\x1B[36m"
# define WHT "\x1B[37m"
# define BACK_GRN "\x1B[42m"
# define BACK_YEL "\x1B[43m"
# define BACK_CYN "\x1B[46m"
# define BOLD_CYAN "\x1B[1m\033[36m"
# define BOLD_GRN "\x1B[1m\033[32m"
# define RESET "\x1B[0m"

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define MALLOC_FAIL -1

typedef struct		s_dlst
{
	void			*data;
	size_t			data_size;
	struct s_dlst	*next;
	struct s_dlst	*prev;
}					t_dlst;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_string
{
	char			*str;
	size_t			len;
	size_t			size;
}					t_string;

int					ft_putchar(char c);
int					ft_putchar_termcaps(int c);
int					ft_putnchar(char c, int n);
int					ft_putwchar_t(wchar_t wc);
int					ft_wchar_len(wchar_t wc);
int					ft_putstr(char const *str);
int					ft_putnstr(char const *str, int n);
int					ft_putwstr(wchar_t *str);
int					ft_putnwstr(wchar_t *str, int n);
void				ft_putendl(char const *str);
void				ft_putnbr(int n);
void				ft_putnbr_base(int n, char *base);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, void const *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
int					ft_wstrlen(wchar_t *str);
int					ft_wchar_len(wchar_t c);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s1, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *s1, const char *s2, size_t size);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
int					ft_str_single_chr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little,
					size_t len);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_str_isdigit(char *str);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_ischar(char *str, char c, int i);
int					ft_toupper(int c);
char				*ft_str_toupper(char *str);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
char				*ft_strnew_set(int size, char c);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnjoin(char *s1, int n, ...);
char				*ft_strjoin_free(char *s1, char *s2, int choice);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				**ft_strtok(char const *str, const char *s);
char				*ft_itoa(long long n);
char				*ft_itoa_llu(unsigned long long n);
char				*ft_itoa_base(long long value, char *base);
char				*ft_itoa_base_llu(unsigned long long value, char *base);
char				*ft_itoa_base_umax(uintmax_t value, char *base);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void(*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_dlst				*ft_dlstnew(void const *data, size_t data_size);
void				ft_dlstdelone(t_dlst **alst, void(*del)(void *, size_t));
void				ft_dlstdel(t_dlst **alst, void(*del)(void *, size_t));
void				ft_dlstadd(t_dlst **alst, t_dlst *new);
void				ft_swap(void *a, void *b);
int					ft_nb_digit_base(long long n, int base);
int					ft_abs(int i);
void				ft_free_string_tab(char ***tab);
int					ft_valid_file(char *path);
int					ft_printf(const char *format, ...);
int					get_next_line(int fd, char **line);
void				ft_display_tab(char **tab);
void				ft_error_msg(char *error);
void				*ft_malloc(size_t size);
int					ft_realloc_str(t_string *str);
t_string			ft_init_str(const size_t size);

#endif
