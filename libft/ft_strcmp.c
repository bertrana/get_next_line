/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 16:51:24 by yjohns            #+#    #+#             */
/*   Updated: 2019/06/30 19:43:10 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *str1, const char *str2)
{
	size_t	len;

	if (ft_strlen(str1) >= ft_strlen(str2))
		len = ft_strlen(str2);
	else
		len = ft_strlen(str1);
	return (ft_strncmp(str1, str2, len));
}
