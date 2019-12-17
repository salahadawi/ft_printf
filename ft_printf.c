/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:26:55 by sadawi            #+#    #+#             */
/*   Updated: 2019/12/17 18:45:54 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		ft_printf(const char *format, ...)
{
	va_list	args;
	int		amount;

	amount = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			amount += handle_flags(&format, &args);
		else
			ft_putchar(*format);
		format++;
		amount++;
	}
	return (amount);
}

char	*toaddress(unsigned long n)
{
	char *address;
	char *tmp;

	address = (char*)malloc(15);
	ft_strcpy(address, "0x");
	tmp = ft_itoa_base_ul_low(n, 16);
	ft_strcat(address, tmp);
	free(tmp);
	return (address);
}

int		handle_output(char **output, char *flag)
{
	int len;

	handle_flag(output, flag);
	if (ft_strchr(flag, 'c'))
		len = handle_char_output(output, flag);
	else
	{
		ft_putstr(*output);
		len = ft_strlen(*output);
	}
	free(*output);
	return (len);
}

int		handle_char_output(char **output, char *flag)
{
	int width;
	int i;

	i = 0;
	width = 1;
	while (ft_strchr("#0-+ ", flag[i]))
		i++;
	if (ft_isdigit(flag[i]))
		width = ft_atoi(flag + i);
	i = 0;
	while (width > i)
		ft_putchar((*output)[i++]);
	return (width);
}

int		handle_char_width(char **output, char *flag, int width)
{
	if (ft_strchr(flag, 'c'))
		if (!(**output) && width > 1)
			return (--width);
	return (width);
}
