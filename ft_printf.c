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

int g_fd;
char *g_output;

int		ft_fprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		amount;

	g_fd = fd;
	g_output = NULL;
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

char*	ft_sprintf(const char *format, ...)
{
	va_list	args;

	g_fd = 1;
	g_output = "";
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			handle_flags(&format, &args);
		else
			ft_putchar(*format);
		format++;
	}
	return (g_output);
}

int		ft_printf(const char *format, ...)
{
	va_list	args;
	int		amount;

	g_fd = 1;
	g_output = NULL;
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
		if (!g_output)
			ft_putstr_fd(*output, g_fd);
		else
			g_output = ft_strdup(*output);
		len = ft_strlen(*output);
	}
	free(*output);
	return (len);
}
