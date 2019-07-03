/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 13:26:12 by yjohns            #+#    #+#             */
/*   Updated: 2019/06/24 15:47:56 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t num)
{
	unsigned char	*tmp;
	int				i;

	i = 0;
	tmp = (unsigned char *)dest;
	while (num)
	{
		*tmp = *(unsigned char *)src;
		if (*tmp == (unsigned char)c)
			return (dest + i + 1);
		src++;
		tmp++;
		i++;
		num--;
	}
	return (NULL);
}
