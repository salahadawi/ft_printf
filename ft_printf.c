/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:26:55 by sadawi            #+#    #+#             */
/*   Updated: 2019/11/12 17:44:36 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
  va_list args;
  int amount;

  amount = 0;
  va_start(args, format);
  while (*format)
    {
      if (*format == '%' && format[1] == '%')
	ft_putchar(*format++);
      else if (*format == '%')
	amount += handle_flags(&format, &args);
      else
	ft_putchar(*format);
      format++;
      amount++;
    }
  return (amount);
}

int	handle_flags(const char **format, va_list *args)
{
  char *flag;
  int i;
  int amount;

  i = 0;
  amount = 0;
  if ((*format)[1] == '%')
    {
      format++;
      return (0);
    }
  while (!ft_strchr("cspdiouxXf", (*format)[i]) && (*format)[i] != '\0')
	 i++;
  flag = ft_strsub(*format, 1, i);
  if (check_flag(flag))
    {
      *format += i;
      amount = print_flag(flag, args);
    }
  free(flag);
  return (amount - 1);
}

int	print_flag(char *flag, va_list *args)
{
  int len;

  len = 0; // remove later
  if (!(len = handle_signed(flag, args)))
    if (!(len = handle_unsigned(flag, args)))
      if (!(len = handle_pointer(flag, args)))
	return (0);
  return (len);
}

int	handle_signed(char *flag, va_list *args)
{
  long	output;

  if (ft_strchr(flag, 'c'))
    {
      output = va_arg(*args, int);
      ft_putchar(output);
    }
  else if (ft_strstr(flag, "hhi") || ft_strstr(flag, "hhd"))
      output = (signed char)va_arg(*args, int);
  else if (ft_strstr(flag, "hi") || ft_strstr(flag, "hd"))
      output = (short)va_arg(*args, int);
  else if (ft_strstr(flag, "lli") || ft_strstr(flag, "li"))
      output = (long)va_arg(*args, long);
  else if (ft_strchr(flag, 'd') || ft_strchr(flag, 'i'))
      output = va_arg(*args, int);
  else
    return (0);
  if (!ft_strchr(flag, 'c'))
    ft_putlong(output);
  return (ft_longlen(output));
}

int	handle_unsigned(char *flag, va_list *args)
{
  unsigned long	output;
  
  if (ft_strstr(flag, "hhu"))
    output = (unsigned char)va_arg(*args, unsigned int);
  else if (ft_strstr(flag, "hu"))
    output = (unsigned short)va_arg(*args, unsigned int);
  else if (ft_strstr(flag, "llu") || ft_strstr(flag, "lu"))
    output = (unsigned long)va_arg(*args, unsigned long);
  else if (ft_strchr(flag, 'u'))
    output = (unsigned int)va_arg(*args, unsigned int);
  else
    return (0);
  ft_putulong(output);
  return (ft_ulonglen(output));
}

int	handle_pointer(char *flag, va_list *args)
{
  void *output;
  unsigned int tmp;
  int len;

  if (ft_strchr(flag, 's'))
    output = ft_strdup(va_arg(*args, char*));
  if (ft_strchr(flag, 'p'))
    {
      tmp = va_arg(*args, unsigned long);
      output = toaddress(tmp);
    }
  ft_putstr(output);
  len = ft_strlen(output);
  return (len);
}

char	*toaddress(unsigned long n)
{
  char *address;
  char *tmp;
  
  address = (char*)malloc(15);
  ft_strcpy(address, "0x7fff");
  tmp = ft_tobase16(n);
  ft_strcat(address, tmp);
  free(tmp);
  return (address);
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
  ft_putnbr(ft_printf("%hhu %s\n", 300, "test") - 1);
  return (0);
}

//implement ft_itoa_base, then print pointer adddress with %u
//check if long and long long have a difference on mac
