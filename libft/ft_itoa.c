/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 10:36:35 by yjohns            #+#    #+#             */
/*   Updated: 2019/06/30 19:51:47 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int		length(int n)
{
	int		i;

	i = 1;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	i++;
	return (i);
}

static char		*do_str(int len, int n)
{
	int		i;
	char	*str;

	i = 0;
	if (n < 0)
	{
		i = 1;
		if (!(str = (char*)malloc(len)))
			return (0);
		str[0] = '-';
		n = -n;
	}
	else
	{
		if (!(str = (char*)malloc(len)))
			return (0);
	}
	while (n > 9 && len > i)
	{
		len--;
		str[len - 1] = (n % 10) + 48;
		n = n / 10;
	}
	str[len - 2] = (n % 10) + 48;
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = 0;
	if (n != -2147483648)
	{
		i = length(n);
		if (!(str = do_str(i, n)))
			return (NULL);
		str[i - 1] = '\0';
		return (str);
	}
	if (!(str = (char*)malloc(13)))
		return (0);
	str = "-2147483648\0";
	return (str);
}
