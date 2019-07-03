/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 10:38:08 by yjohns            #+#    #+#             */
/*   Updated: 2019/06/24 15:46:16 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	i = ft_strlen(s);
	str = (char *)malloc(i + 1);
	if (str && s && f)
	{
		while (j < i)
		{
			str[j] = f(s[j]);
			j++;
		}
		str[j] = '\0';
		return (str);
	}
	return (NULL);
}
