/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 17:31:29 by yjohns            #+#    #+#             */
/*   Updated: 2019/08/28 17:51:36 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnchr(const char *str, int symbol)
{
	size_t		i;
	size_t		len;
	int			num;

	i = 0;
	num = 0;
	len = ft_strlen(str);
	if (!(ft_strchr(str, symbol)))
		return (0);
	while (i < len)
	{
		if (str[i] == symbol)
			num++;
		i++;
	}
	return (num);
}
