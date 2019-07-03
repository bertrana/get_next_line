/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:48:19 by yjohns            #+#    #+#             */
/*   Updated: 2019/06/30 19:48:25 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)buf1;
	str2 = (unsigned char *)buf2;
	if (!buf1 && !buf2)
		return (0);
	while (*str1 == *str2 && count && str1 && str2)
	{
		count--;
		str1++;
		str2++;
		if (!count || (!str1 && !str2))
			return (0);
	}
	return (*str1 - *str2);
}
