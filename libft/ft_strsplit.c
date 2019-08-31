/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:31:51 by yjohns            #+#    #+#             */
/*   Updated: 2019/08/29 20:25:54 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n(const char *s, char c)
{
	int		i;
	int		num;
	char	flag;

	i = 0;
	num = 0;
	if ((flag = s[i]) == '\0')
		return (1);
	i++;
	while (s[i] != '\0')
	{
		if (s[i] != c && (flag == c || (flag != c && i == 1)))
			num++;
		flag = s[i];
		i++;
	}
	return (num);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**matr;
	int		st_w;
	int		en_w;
	int		j;

	st_w = 0;
	j = 0;
	if (!s || (!(matr = (char **)malloc(sizeof(char *) * n(s, c)))))
		return (NULL);
	while (s[st_w] != '\0')
	{
		while (s[st_w] == c && s[st_w] != '\0')
			st_w++;
		en_w = st_w;
		while (s[en_w] != c && s[en_w] != '\0')
			en_w++;
		if (!(matr[j] = ft_strsub(s, st_w, en_w - st_w)))
			return (NULL);
		if (s[en_w] == '\0' && en_w == st_w)
			break ;
		j++;
		st_w = en_w;
	}
	matr[j] = NULL;
	return (matr);
}
