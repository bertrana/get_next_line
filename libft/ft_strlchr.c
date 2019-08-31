/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 17:27:42 by yjohns            #+#    #+#             */
/*   Updated: 2019/08/28 17:50:18 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlchr(const char *str, int symbol, int num_s)
{
	int len;

	len = 0;
	if (num_s <= 0)
		return (0);
	while (num_s > 0)
	{
		while (str[len] && str[len] != symbol)
			len++;
		num_s--;
		len++;
	}
	len--;
	if (str[len] != symbol)
		return (0);
	return (len);
}
