/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:26:55 by sadawi            #+#    #+#             */
/*   Updated: 2022/02/07 16:28:06 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	handle_flags(const char **format, va_list *args, t_data *data)
{
	char	*flag;
	int		i;
	int		amount;

	i = 1;
	amount = 0;
	while (!ft_strchr("cspdiouxXf%", (*format)[i]) && (*format)[i] != '\0')
		i++;
	if (!(*format)[i])
		return (0);
	flag = ft_strsub(*format, 1, i);
	if (check_flag(flag))
	{
		*format += i;
		amount = print_flag(flag, args, data);
	}
	free(flag);
	return (amount - 1);
}

int	check_flag(char *flag)
{
	int	i;

	i = 0;
	while (ft_strchr("#0-+ ", flag[i]))
		i++;
	while (ft_isdigit(flag[i]))
		i++;
	if (flag[i] == '.')
		i++;
	while (ft_isdigit(flag[i]))
		i++;
	if (flag[i] == 'h')
		i++;
	if (flag[i] == 'h')
		i++;
	if (flag[i] == 'l')
		i++;
	if (flag[i] == 'l')
		i++;
	else if (flag[i] == 'L')
		i++;
	if (ft_strchr("cspdiouxXf%", flag[i]))
		return (1);
	return (0);
}

int	print_flag(char *flag, va_list *args, t_data *data)
{
	int	len;

	if (!handle_signed(flag, args, data, &len))
		if (!handle_unsigned(flag, args, data, &len))
			if (!handle_pointer(flag, args, data, &len))
				if (!handle_base(flag, args, data, &len))
					if (!handle_float(flag, args, data, &len))
						if (!handle_percent(flag, data, &len))
							return (0);
	return (len);
}

void	handle_flag(char **output, char *flag)
{
	int	i;

	i = 0;
	if (ft_strchr(flag, '.'))
		handle_precision(output, flag);
	if (ft_strchr(flag, '#'))
		handle_hashtag(output, flag);
	if (ft_strchr(flag, '+'))
		handle_plus(output, flag);
	else if (ft_strchr(flag, ' '))
		handle_space(output, flag);
	while (flag[i])
	{
		if (ft_isdigit(flag[i++]))
		{
			if (flag[i - 1] == '0')
			{
				if (!ft_strchr(flag, '-'))
					handle_zero(output, flag);
			}
			else
				handle_width(output, flag);
		}
	}
}

int	flag_integer(char *flag)
{
	if (ft_strchr(flag, 'd'))
		return (1);
	if (ft_strchr(flag, 'i'))
		return (1);
	if (ft_strchr(flag, 'o'))
		return (1);
	if (ft_strchr(flag, 'u'))
		return (1);
	if (ft_strchr(flag, 'x'))
		return (1);
	if (ft_strchr(flag, 'X'))
		return (1);
	return (0);
}
