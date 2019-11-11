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

int	check_flag(char *str);

int	ft_printf(const char *format, ...)
{
  va_list args;
  int arg;

  va_start(args, format);
  while (arg != 0)
    {
      arg = va_arg(args, int);
      ft_putnbr(arg);
    }
  return (0);
}

int	check_flags(char *format)
{
  while (*format)
    if (*format == '%')
      
}

int	flags_amount(char *str)
{
  int i;

  i = 0;
  while (*str)
    {
      if (*str == '%')
	if (*(str + 1) == '%')
	  str++;
	else if (*(str + 1) != '\0')
	  i++;
      str++;
    }
  return (i);
}

int	check_flag(char *str)
{
  int i;

  i = 0;
  ft_putnbr(flags_amount(str));
  return (0);
  
}

int	main(int argc, char **argv)
{
  (void)argc;
  check_flag(argv[1]);
  ft_printf(argv[1], 5, 6, 7);
  return (0);
}

//count each % in format, take in to memory all flags, then check va_arg for content
//or, read straight from format, when % is encountered check if valid flag, then find content from va_arg
