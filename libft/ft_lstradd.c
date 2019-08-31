/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstradd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 17:26:37 by yjohns            #+#    #+#             */
/*   Updated: 2019/08/28 17:49:06 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*ft_lstradd(t_list *alst, t_list *new)
{
	t_list	*start;

	if (!new)
		return (NULL);
	start = alst;
	while (alst->next)
		alst = alst->next;
	alst->next = new;
	return (start);
}
