/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:14:45 by sadawi            #+#    #+#             */
/*   Updated: 2019/12/09 14:37:52 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int  ft_doublelen(long n, int precision)
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

char	*ft_itoa_double(long double d, int precision)
{
	int		i;
	char	*arr;

	i = ft_doublelen(d, precision);
	if (!(arr = ft_strnew(i)))
		return (NULL);
	ft_strcpy(arr, ft_itoa_base((long)d, 10));
	d -= (long)d;
	if (d < 0)
		d *= -1;
	if (precision > 0)
		ft_strcat(arr, ".");
	while (precision-- >= 0)
	{
		d *= 10;
		if (precision == -1)
			if (((long)d % 10) > 4)
				d += 10;
	}
	d /= 10;
	ft_strcat(arr, ft_itoa_base((long)d, 10));
	return (arr);
}
