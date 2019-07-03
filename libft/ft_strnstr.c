/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 16:50:53 by yjohns            #+#    #+#             */
/*   Updated: 2019/06/30 19:35:41 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	if (*str1 == '\0' || ft_strlen(str2) > ft_strlen(str1))
		return (NULL);
	if (*str2 == '\0' || len == 0)
		return ((char *)str1);
	while (*str1 && len >= ft_strlen(str2))
	{
		if (*str1 == *str2 && ft_memcmp(str1, str2, ft_strlen(str2)) == 0)
			return ((char *)str1);
		str1++;
		len--;
	}
	return (NULL);
}
