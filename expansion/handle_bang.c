#include "history.h"


static int get_cmd_num(t_history *history, t_string *exp_input, const int num)
{
	char	*s;
	
	if (num < 0)
		if (!(s = search_in_history_by_num(history, num)))
			return (1);
	if (num > 0)
		if (!(s = search_in_history_by_num(history, num - 1)))
			return (1);
	if (num == 0)
		return (1);
	ft_strcat(exp_input->str, s);
	exp_input->len += ft_strlen(s);
	return (0);
}

static int	expand_hashtag(t_string *exp_input, char **input)
{
	if (exp_input->len * 2 >= exp_input->size)
		if (ft_realloc_str(exp_input) == MALLOC_FAIL)
			return (MALLOC_FAIL);
	ft_strncat(exp_input->str + exp_input->len, exp_input->str, exp_input->len);
	(*input)++;
	exp_input->len *= 2;
	return (0);
}

static int	get_cmd_str(t_history *history, t_string *exp_input, char **input,
						char *s)
{
	char	*tmp;
	char	*tmp2;
	size_t	len;

	if (!(tmp = ft_strchr(s, ' ')))
	{
		if (!(tmp = search_in_history_by_str(history, s)))
			return (0);
		tmp2 = s;
	}
	else
	{
		tmp2 = ft_strndup(s, tmp - s);
		if (!(tmp = search_in_history_by_str(history, tmp2)))
			return (0);
	}
	len = ft_strlen(tmp);
	if (exp_input->len + len >= exp_input->size)
		if (ft_realloc_str(exp_input) == MALLOC_FAIL)
			return (MALLOC_FAIL);
	ft_strcat(exp_input->str, tmp);
	exp_input->len += len;
	(*input) += ft_strlen(tmp2);
	return (0);
}

int			handle_bang(t_history *history, char **input, t_string *exp_input)
{
	char	*s;
	int		num;

	s = *input + 1;
	if (*s == '0')
		return (-1);
	else if (*s == '!')
	{
		get_cmd_num(history, exp_input, history->len);
		(*input)++;
	}
	else if (ft_isdigit(*s) || (*s == '-' && ft_isdigit(*(s + 1))))
	{
		num = ft_atoi(s);
		get_cmd_num(history, exp_input, num);
		(*input) += ft_nb_digit_base((long long)num, 10);
	}
	else if (*s == '#')
		expand_hashtag(exp_input, input);
	else if (*(s + 1) != '?')
		get_cmd_str(history, exp_input, input, s);
	return (0);
}
