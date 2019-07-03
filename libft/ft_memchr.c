/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:47:32 by yjohns            #+#    #+#             */
/*   Updated: 2019/06/30 19:47:35 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *buffer, int c, size_t count)
{
	while (count--)
	{
		if (*(unsigned char *)buffer == (unsigned char)c)
			return ((void *)buffer);
		buffer++;
	}
	return (NULL);
}
