/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:27:35 by sadawi            #+#    #+#             */
/*   Updated: 2019/12/09 17:00:06 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int		ft_printf(const char *format, ...);

int		handle_flags(const char **format, va_list *args);

int		check_flag(char *flag);

int		print_flag(char *flag, va_list *args);

int		handle_signed(char *flag, va_list *args);

int		handle_unsigned(char *flag, va_list *args);

int		handle_pointer(char *flag, va_list *args);

int		handle_base(char *flag, va_list *args);

int		handle_float(char *flag, va_list *args);

char	*toaddress(unsigned long n);

int		handle_output(char **output, char *flag);

void	handle_flag(char **output, char *flag);

void	handle_width(char **output, char *flag);

#endif
