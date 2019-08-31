/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 10:37:59 by yjohns            #+#    #+#             */
/*   Updated: 2019/08/28 17:30:53 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str || (!s1 && !s2))
		return (NULL);
	if (s1)
		while (s1[i] != '\0' && s1)
		{
			str[i] = s1[i];
			i++;
		}
	while (s2[j] != '\0' && s2)
	{
		str[i++] = s2[j++];
	}
	str[i] = '\0';
	return (str);
}
