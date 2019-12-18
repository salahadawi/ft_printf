/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string_datatypes.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:26:55 by sadawi            #+#    #+#             */
/*   Updated: 2019/12/17 18:06:17 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	handle_base(char *flag, va_list *args)
{
	char			*output;
	unsigned long	tmp;

	if (ft_strstr(flag, "llx") || ft_strstr(flag, "llX")
			|| ft_strstr(flag, "llo"))
		tmp = (unsigned long)va_arg(*args, unsigned long);
	else if (ft_strstr(flag, "lx") || ft_strstr(flag, "lX")
			|| ft_strstr(flag, "lo"))
		tmp = (unsigned long)va_arg(*args, unsigned long);
	else if (ft_strstr(flag, "hhx") || ft_strstr(flag, "hhX")
			|| ft_strstr(flag, "hho"))
		tmp = (unsigned char)va_arg(*args, unsigned int);
	else if (ft_strstr(flag, "hx") || ft_strstr(flag, "hX")
			|| ft_strstr(flag, "ho"))
		tmp = (unsigned short)va_arg(*args, unsigned int);
	else if (ft_strchr(flag, 'x') || ft_strchr(flag, 'o')
			|| ft_strstr(flag, "X"))
		tmp = va_arg(*args, unsigned int);
	else
		return (0);
	if (ft_strchr(flag, 'x'))
		output = ft_itoa_base_ul_low(tmp, 16);
	else if (ft_strchr(flag, 'X'))
		output = ft_itoa_base_ul(tmp, 16);
	else
		output = ft_itoa_base_ul_low(tmp, 8);
	return (handle_output(&output, flag));
}

int	handle_pointer(char *flag, va_list *args)
{
	char			*output;
	unsigned long	tmp;

	if (ft_strchr(flag, 's'))
	{
		output = ft_strdup(va_arg(*args, char*));
		if (!output)
			output = ft_strdup("(null)");
	}
	else if (ft_strchr(flag, 'p'))
	{
		tmp = va_arg(*args, unsigned long);
		output = toaddress(tmp);
	}
	else
		return (0);
	return (handle_output(&output, flag));
}

int	handle_percent(char *flag)
{
	char	*output;

	if (ft_strchr(flag, '%'))
		output = ft_strdup("%");
	else
		return (0);
	return (handle_output(&output, flag));
}
