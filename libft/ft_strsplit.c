/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:31:51 by yjohns            #+#    #+#             */
/*   Updated: 2019/06/30 19:51:48 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	n(const char *s, char c)
{
	int		i;
	int		flag;

	flag = 0;
	i = 0;
	while (*s != '\0')
	{
		if (*s == c)
		{
			if (flag == 0)
				i++;
			s++;
			flag = 1;
		}
		else
		{
			s++;
			flag = 0;
		}
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**matr;
	int		st_w;
	int		en_w;
	int		j;

	st_w = 0;
	en_w = 0;
	j = 0;
	if (!(matr = (char **)malloc(sizeof(char *) * n(s, c))) && !s)
		return (0);
	while (s[en_w] != '\0')
	{
		while (s[st_w] == c && s[st_w] != '\0')
			st_w++;
		en_w = st_w;
		while (s[en_w] != c && s[en_w] != '\0')
			en_w++;
		if (!(matr[j] = ft_strsub(s, st_w, en_w - st_w)))
			return (0);
		if (s[en_w] == '\0' && en_w == st_w)
			matr[j] = NULL;
		j++;
		st_w = en_w;
	}
	return (matr);
}
