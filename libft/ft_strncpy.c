/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:38:22 by yjohns            #+#    #+#             */
/*   Updated: 2019/06/30 19:38:25 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t num)
{
	size_t	i;

	i = 0;
	if (num == 0)
		return (dest);
	while (num--)
	{
		if (!(*src))
			dest[i] = '\0';
		else
		{
			dest[i] = *src;
			src++;
		}
		i++;
	}
	return (dest);
}
