/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 10:38:34 by yjohns            #+#    #+#             */
/*   Updated: 2019/06/27 16:51:32 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	char	*str;

	j = 0;
	if (!(i = ft_strlen(s) - 1) || !s)
		return (NULL);
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] && i)
		i--;
	if (!i)
		return (ft_strnew(1));
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && s[j])
		j++;
	if (i == j - 1)
		return ((char *)s);
	if (!(str = ft_strsub(s, j, i - j + 1)))
		return (NULL);
	return (str);
}
