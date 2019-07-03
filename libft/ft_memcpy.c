/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 13:04:06 by yjohns            #+#    #+#             */
/*   Updated: 2019/06/24 15:50:20 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	unsigned char *tmp;

	if (!dest && !src)
		return (NULL);
	tmp = (unsigned char *)dest;
	while (num)
	{
		*tmp = *((unsigned char *)src);
		num--;
		tmp++;
		src++;
	}
	return (dest);
}
