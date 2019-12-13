/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:14:45 by sadawi            #+#    #+#             */
/*   Updated: 2019/12/13 19:02:30 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	ft_doublelen(long n, int precision)
{
	int i;

	i = 0;
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i + precision + 1);
}

static void	handle_rounding(char **arr, long double *d)
{
	int len;
	long dlen;
	char *tmp;

	dlen = ft_doublelen((long)*d, 0);
	*d += 10;
	if (dlen != ft_doublelen((long)*d, 0))
	{
		len = 1;
		while (ft_doublelen((long)*d, 0) != ft_doublelen(len, 0))
			len *= 10;
		*d -= len;
		tmp = *arr;
		*arr = ft_itoa_base(ft_atoi(*arr) + 1, 10);
		if (ft_strchr(tmp, '.'))
		{
			*arr = ft_strjoin(*arr, ft_strchr(tmp, '.'));
			while ((long)ft_strlen(ft_strchr(*arr, '.')) < dlen - 2)
				ft_strcat(*arr, "0");
		}		
		free(tmp);
	}
}

char		*ft_itoa_double(long double d, int precision)
{
	int		i;
	char	*arr;

	i = ft_doublelen(d, precision);
	if (!(arr = ft_strnew(i)))
		return (NULL);
	if (d < 0)
	{
		ft_strcpy(arr, "-");
		d *= -1;
	}
	ft_strcat(arr, ft_itoa_base((long)d, 10));
	d -= (long)d;
	if (precision > 0)
		ft_strcat(arr, ".");
	while (precision-- >= 0)
	{
		d *= 10;
		if (precision == -1)
			if (((long)d % 10) > 4)
				handle_rounding(&arr, &d);
		if (!(long)d && precision > 0)
			ft_strcat(arr, "0");
	}
	d /= 10;
	if (ft_strchr(arr, '.'))
		ft_strcat(arr, ft_itoa_base((long)d, 10));
	return (arr);
}
