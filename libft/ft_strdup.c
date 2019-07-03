/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:40:59 by yjohns            #+#    #+#             */
/*   Updated: 2019/06/30 19:41:03 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!(tmp = (char *)malloc(ft_strlen(s) + 1)) || !s)
		return (NULL);
	while (*s)
	{
		tmp[i] = *s;
		s++;
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
