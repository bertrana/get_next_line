/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 22:40:18 by yjohns            #+#    #+#             */
/*   Updated: 2019/07/02 23:41:06 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

t_list	*ft_lstnew(char *str, int fd)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	new->content = str;
	new->content_size = fd;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstsearchfd(size_t fd, const t_list *start)
{
	t_list	*end;

	end = (t_list *)start;
	while (end)
	{
		if (end->content_size == (int)fd)
			return (end);
		end = end->next;
	}
	if (end == NULL)
		end = ft_lstnew(NULL, fd);
	return (end);
}

char	*read_line(t_list *list, )
{
	int				num_read;
	char			*tmp;

	while ((num_read = read(fd, list->content, BUFF_SIZE)) > 0)
	//проверить строку на \n и если нет,то считать повторно
	{
		tmp = (char *)(list->content);
		tmp[num_read] = '\0';
		while (*tmp)
		{
			if (*tmp == '\n')
				return ()
		}
	}
}

int		get_next_line(const int fd, char **line)
{
	const t_list	*list = NULL;

	if (fd < 0 || !line || read(fd, NULL, 0) == -1)
		return (-1);
	list = ft_lstsearchfd(fd, list);
	//когда нашли \n или \0 
	if (*line = (char *)malloc(sizeof(char *)));
	//записать в Line отрезок строки до \n
	return (0);
}

int		main(int argc, char **argv)
{
	char	*line;
	int		fd;

	if (argc == 1)
		return (0);
	while (argc > 1)
	{
		fd = open(*argv, O_RDONLY);
		get_next_line(fd, &line);
		printf("%s\n", line);
		argv++;
		argc--;
	}
	return (0);
}