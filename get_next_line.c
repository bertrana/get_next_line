/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 22:40:18 by yjohns            #+#    #+#             */
/*   Updated: 2019/09/01 23:38:04 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstsearchfd(const int fd, t_list *start)
{
	t_list	*end;
	char	*str;

	str = (char *)malloc(1);
	str[0] = '\0';
	if (start == NULL)
		return (ft_lstnew(str, (size_t) fd));
	end = start;
	while (end->next && end->content_size != (size_t)fd)
		end = end->next;
	if (end->content_size == (size_t)fd)
	{
		while (start != end && start)
		{
			end = ft_lstradd(end, start);
			start = start->next;
		}
		return (end);
	}
	end = ft_lstnew(str, (size_t) fd);
	end->next = start;
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
	if ((*str)[i] == '\n' && was_read <= BUFF_SIZE) //строка до абзаца
	{
		if (!(*line = ft_strsub(*str, 0, i)) ||
			!(tmp = ft_strsub(*str, i + 1, ft_strlen(*str) - i - 1)))
			return (-1);
		free(*str);
		*str = tmp;
	}
	else
	{
		*line = ft_strsub(*str, 0, i);
		free(*str);
		*str = ft_strnew(0);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*lst = NULL;
	char	        str[BUFF_SIZE + 1];
	int	    	    was_read;
	char            *tmp;

	if (fd < 0 || !(lst = ft_lstsearchfd(fd, lst)))
		return (-1);
	was_read = BUFF_SIZE;
	while (!(ft_strchr(lst->content, '\n')))
	{
		if ((was_read = read(fd, str, BUFF_SIZE)) < 0)
			return (-1);
		if (was_read == 0 && *((char *)lst->content)== '\0')
		{
			//*line = NULL;
			return (0);
		}
		str[was_read] = '\0';
		if (!(tmp = ft_strjoin(lst->content, str)))
			return (-1);
		free(lst->content);
		lst->content = tmp;
		if (was_read < BUFF_SIZE)
			break ;
	}
	return (ft_cut_cont(&(lst->content), was_read, line));
}
