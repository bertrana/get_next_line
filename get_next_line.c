/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 22:40:18 by yjohns            #+#    #+#             */
/*   Updated: 2019/08/30 14:07:04 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstsearchfd(size_t fd, const t_list *start)
{
	t_list	*end;

	if (start == NULL)
		return (ft_lstnew(NULL, (size_t)fd));
	end = (t_list *)start;
	while (end->next)
	{
		if (end->content_size == fd)
			return (end);
		end = end->next;
	}
	return (end);
}

int		ft_cut_cont(void **vo, int was_read, char **line)
{
	char	**str;
	char	*tmp;
	int		i;

	str = (char **)vo;
	i = 0;
	while ((*str)[i] != '\n' && (*str)[i])
		i++;
	if (was_read == 0 && (*str)[i] == '\0')
	{
		*line = *str;
		return (0);
	}
	if ((*str)[i] == '\n')
	{
		if (!(*line = ft_strsub(*str, 0, i)) ||
			!(tmp = ft_strsub(*str, i + 1, ft_strlen(*str) - i - 1)))
			return (-1);
		free(*str);
		*str = tmp;
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*lst = NULL;
	char			str[BUFF_SIZE + 1];
	int				was_read;
	char			*tmp;

	if (fd < 0 || read(fd, NULL, 0) == -1)
		return (-1);
	if (!(lst = ft_lstsearchfd(fd, lst)))
		return (0);
	was_read = BUFF_SIZE;
	while (!(ft_strchr(lst->content, '\n')))
	{
		if ((was_read = read(fd, str, BUFF_SIZE)) < 0)
			return (-1);
		str[was_read] = '\0';
		if (!(tmp = ft_strjoin(lst->content, str)))
			return (-1);
		free(lst->content);
		lst->content = tmp;
	}
	return (ft_cut_cont(&(lst->content), was_read, line));
}
