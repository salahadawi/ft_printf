
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:26:55 by sadawi            #+#    #+#             */
/*   Updated: 2019/12/12 19:05:30 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	handle_hashtag(char **output, char *flag)
{
	char *tmp;

	tmp = *output;
	if (!(*output)[0] || (*output)[0] != '0')
		if (ft_strchr(flag, 'o'))
			*output = ft_strjoin("0", *output);
	if (ft_atoi(*output))
	{
		if (ft_strchr(flag, 'x'))
			*output = ft_strjoin("0x", *output);
		else if (ft_strchr(flag, 'X'))
			*output = ft_strjoin("0X", *output);
	}
	if (ft_strchr(flag, 'f'))
		if (!ft_strchr(*output, '.'))
			*output = ft_strjoin(*output, ".");
	if (!ft_strequ(*output, tmp))
		free(tmp);
}

void	handle_plus(char **output, char *flag)
{
	char *tmp;

	tmp = *output;
	if (ft_strchr(flag, 'd') || ft_strchr(flag, 'i')
		|| ft_strchr(flag, 'u'))
	{
			if (ft_atoi(*output) >= 0)
				*output = ft_strjoin("+", *output);
	}
	if (!ft_strequ(*output, tmp))
		free(tmp);
}

void	handle_space(char **output, char *flag)
{
	char *tmp;

	tmp = *output;
	if (ft_strchr(flag, 'd') || ft_strchr(flag, 'i')
		|| ft_strchr(flag, 'u'))
	{
		if (ft_atoi(*output) >= 0)
			*output = ft_strjoin(" ", *output);
	}
	if (!ft_strequ(*output, tmp))
		free(tmp);
}

void	handle_width(char **output, char *flag)
{
	int		i;
	int		width;
	char	*padding;
	char	*tmp;

	i = 0;
	width = 0;
	while (ft_strchr("#0-+ ", flag[i]))
		i++;
	if (ft_isdigit(flag[i]))
		width = ft_atoi(flag + i);
	width = handle_char_width(output, flag, width);
	if ((int)ft_strlen(*output) < width)
	{
		padding = ft_strnew(width - ft_strlen(*output));
		ft_memset(padding, ' ', width - ft_strlen(*output));
		tmp = *output;
		if (ft_strchr(flag, '-'))
			*output = ft_strjoin(*output, padding);
		else
			*output = ft_strjoin(padding, *output);
		free(tmp);
		free(padding);
	}
}

void	handle_zero(char **output, char *flag)
{
	int		i;
	int		width;
	char	*padding;
	char	*tmp;

	i = 0;
	width = 0;
	while (ft_strchr("#0-+ ", flag[i]))
		i++;
	if (ft_isdigit(flag[i]))
		width = ft_atoi(flag + i);
	width = handle_char_width(output, flag, width);
	if ((int)ft_strlen(*output) < width)
	{
		padding = ft_strnew(width - ft_strlen(*output));
		ft_memset(padding, '0', width - ft_strlen(*output));
		tmp = *output;
		add_width(output, flag, padding);
		free(tmp);
		free(padding);
	}
}

void	handle_precision(char **output, char *flag)
{
	char	*padding;
	char	*tmp;
	int		precision;
	int		len;

	len = ft_strlen(*output);
	if (ft_atoi(*output) < 0)
		len--;
	if (ft_strchr(flag, 's') || ft_strchr(flag, 'p'))
		if (len > ft_atoi(ft_strchr(flag, '.') + 1))
			(*output)[ft_atoi(ft_strchr(flag, '.') + 1)] = '\0';
	if (!flag_integer(flag))
		return ;
	precision = ft_atoi(ft_strchr(flag, '.') + 1);
	if (!precision && !ft_atoi(*output))
		ft_strclr(*output);
	if (len < precision)
	{
		padding = ft_strnew(precision - len);
		ft_memset(padding, '0', precision - len);
		tmp = *output;
		add_width(output, flag, padding);
		free(tmp);
		free(padding);
	}
}

void	add_width(char **output, char *flag, char *padding)
{
	int i;
	char *tmp;
	char *tmp2;

	i = 0;
	if (!flag_integer(flag))
		*output = ft_strjoin(padding, *output);
	if ((*output)[i] == '+' || (*output)[i] == '-' || (*output)[i] == '0')
		i++;
	if ((*output)[i] == 'x' || (*output)[i] == 'X')
		i++;
	tmp = ft_strsub(*output, 0, i);
	tmp2 = ft_strsub(*output, i, ft_strlen(*output) - i);
	*output = ft_strjoin(tmp, padding);
	*output = ft_strjoin(*output, tmp2);
	free(tmp);
	free(tmp2);
}
