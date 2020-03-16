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

int		ft_fprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		amount;

	amount = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			amount += handle_flags(&format, &args, fd);
		else
			ft_putchar_fd(*format, fd);
		format++;
		amount++;
	}
	return (amount);
}

int		ft_printf(const char *format, ...)
{
	va_list	args;
	int		amount;

	amount = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			amount += handle_flags(&format, &args, 1);
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

int		handle_output(char **output, char *flag, int fd)
{
	int len;

	handle_flag(output, flag);
	if (ft_strchr(flag, 'c'))
		len = handle_char_output(output, flag, fd);
	else
	{
		ft_putstr_fd(*output, fd);
		len = ft_strlen(*output);
	}
	free(*output);
	return (len);
}
