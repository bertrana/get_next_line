/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 16:49:44 by yjohns            #+#    #+#             */
/*   Updated: 2019/06/30 19:36:15 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int symbol)
{
	int	i;

	i = ft_strlen(str);
	while (i >= 0 && str[i] != symbol)
		i--;
	if (str[i] == symbol)
		return (&(((char *)str)[i]));
	else
		return (NULL);
}
