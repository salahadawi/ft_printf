/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:26:55 by sadawi            #+#    #+#             */
/*   Updated: 2022/02/07 16:26:09 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	handle_char_minus(char **output, char *padding)
{
	*output = ft_strjoin("a", padding);
	(*output)[0] = '\0';
}

int	handle_char_width(char **output, char *flag, int width)
{
	if (ft_strchr(flag, 'c'))
		if (!(**output) && width > 1)
			return (--width);
	return (width);
}

int	handle_char_output(char **output, char *flag, t_data *data)
{
	int	width;
	int	i;

	i = 0;
	width = 1;
	while (ft_strchr("#0-+ ", flag[i]))
		i++;
	if (ft_isdigit(flag[i]))
		width = ft_atoi(flag + i);
	i = 0;
	while (width > i)
		data->output = join_char_to_str(data->output, (*output)[i++]);
	return (width);
}
