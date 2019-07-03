/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 10:38:30 by yjohns            #+#    #+#             */
/*   Updated: 2019/06/30 19:26:21 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;

	i = 0;
	str = (char *)malloc(len + 1);
	if (!str || !s || start > ft_strlen(s))
		return (NULL);
	while (s[start] != '\0' && len > i)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	if (s[start] != '\0' && len != i)
		return (NULL);
	str[i] = '\0';
	return (str);
}
