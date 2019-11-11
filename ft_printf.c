/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:26:55 by sadawi            #+#    #+#             */
/*   Updated: 2019/11/06 16:20:14 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"

int	handle_flags(const char **format, va_list *args);

int	ft_printf(const char *format, ...)
{
  va_list args;
  int amount;

  while (*format)
    {
      if (*format == '%')
	amount += handle_flags(&format, &args);
      ft_putchar(*format++);
      amount++;
    }
  return (amount);
}

int	handle_flags(const char **format, va_list *args)
{
  char *flag;
  int i;

  i = 0;
  if (*format[1] == '%')
    {
      format++;
      return (0);
    }
  while (!ft_strchr("cspdiouxXf", *format[i]) && *format[i] != '\0')
	 i++;
  flag = ft_strsub(*format, 1, i);
  if (check_flag(flag))
    {
      format += i;
	return (print_flag(flag, args));
    }
  return (0);
}

int	print_flag(char *flag, va_list *args)
{
  
}

int	check_flag(char *flag)
{
  int i;

  i = 0;
  while (strchr("#0-+ ", flag[i]))
    i++;
  while (ft_isdigit(flag[i]))
    i++;
  if (flag[i] == '.')
    i++;
  while (ft_isdigit(flag[i]))
    i++;
  if (flag[i] == 'h')
    {
      i++;
      if (flag[i] == 'h')
	i++;
    }
  else if (flag[i] == 'l')
    {
      i++;
      if (flag[i] == 'l')
	i++;
    } 
  else if (flag[i] == 'L')
    i++;
  if (ft_strchr("cspdiouxXf", flag[i]))
    return (1);
  return (0);
}

int	main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  ft_putnbr(check_flag(argv[1]));
  return (0);
}

//count each % in format, take in to memory all flags, then check va_arg for content
//or, read straight from format, when % is encountered check if valid flag, then find content from va_arg
