/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 16:52:21 by yjohns            #+#    #+#             */
/*   Updated: 2019/06/30 19:52:04 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_number(const char **str)
{
	int	min;

	min = 1;
	while ((**str == ' ' || (**str < 14 && **str > 8)) && **str)
		(*str)++;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			min = -1;
		(*str)++;
	}
	return (min);
}

int			ft_atoi(const char *str)
{
	int	i;
	int	min;

	min = find_number(&str);
	i = 0;
	while (*str >= '0' && *str <= '9' && *str)
	{
		i = i * 10 + (*str - '0') * min;
		str++;
	}
	return (i);
}
