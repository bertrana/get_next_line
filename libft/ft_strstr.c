/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 16:50:19 by yjohns            #+#    #+#             */
/*   Updated: 2019/06/30 19:35:25 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	if ((*str2 == '\0' && *str1 == '\0') || *str2 == '\0')
		return ((char *)str1);
	while (*str1)
	{
		if (*str1 == *str2 && ft_memcmp(str1, str2, ft_strlen(str2)) == 0)
			return ((char *)str1);
		str1++;
	}
	return (NULL);
}
