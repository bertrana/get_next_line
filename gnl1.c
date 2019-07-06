#include <fcntl.h>
#include "get_next_line.h"

t_list	*ft_lstnew(char *str, size_t fd)
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
	while (end->next)
	{
		if (end->content_size == (int)fd)
			return (end);
		printf("content_size = %s\n", end->content_size);
		end = end->next;
	}
	if (end == NULL)
		end = ft_lstnew(NULL, (size_t)fd);
	return (end);
}

int		get_next_line(const int fd, char **line)
{
	static t_list *lst = NULL;

	if (fd < 0 || read(fd, NULL, 0) == -1 )//|| !line)
		return (-1);
	if (!(lst = ft_lstsearchfd(fd, lst)))
		return(0);
	lst->content = (char *)malloc(BUFF_SIZE + 1);
	printf("1 lst->content = %s\n", lst->content);
	if (BUFF_SIZE != read(fd, lst->content, BUFF_SIZE))
		return (-1);
	printf("2 lst->content = %s\n", lst->content);
	return (0);
}

int		main(int argv, char **argc)
{
	int		fd;
	char	*line;

	fd = 0;
	line = NULL;
	if (argv < 2)
		return (0);
	while (argv > 1)
	{
		fd = open(*argc, O_RDONLY);
		argv--;
		argc++;
		return (get_next_line(fd, &line));
	}
	return (0);
}