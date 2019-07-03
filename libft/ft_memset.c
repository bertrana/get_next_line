/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 18:02:27 by yjohns            #+#    #+#             */
/*   Updated: 2019/06/24 12:57:37 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*temp;

	temp = (unsigned char *)ptr;
	while (num > 0)
	{
		*temp = (unsigned char)value;
		temp++;
		num--;
	}
	return (ptr);
}
