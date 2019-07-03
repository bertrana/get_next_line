/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 15:52:38 by yjohns            #+#    #+#             */
/*   Updated: 2019/06/29 13:10:13 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	unsigned char	*tmp;

	tmp = dest;
	if (dest == src)
		return (NULL);
	if (dest > src)
	{
		while (num)
		{
			tmp[num - 1] = ((unsigned char *)src)[num - 1];
			num--;
		}
		return (dest);
	}
	else
		return (ft_memcpy(dest, src, num));
}
