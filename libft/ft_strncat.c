/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 12:31:08 by yjohns            #+#    #+#             */
/*   Updated: 2019/06/29 17:28:10 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *str1, const char *str2, size_t count)
{
	int i;

	i = ft_strlen(str1);
	while (count-- && *str2)
	{
		str1[i] = *str2;
		str2++;
		i++;
	}
	str1[i] = '\0';
	return (str1);
}
