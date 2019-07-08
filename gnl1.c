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

	if (start == NULL)
		return (ft_lstnew(NULL, (size_t)fd));
	end = (t_list *)start;
	while (end->next)
	{
		if (end->content_size == (int)fd)
			return (end);
		printf("content_size = %s\n", end->content_size);
		end = end->next;
	}
	return (end);
}

char	*ft_strchr(const char *str, int symbol)
{
	while (*str && *str != symbol)
		str++;
	if (*str == symbol)
		return ((char *)str);
	else
		return (NULL);
}

int		ft_search_n(t_list *lst, char **line)
{

	if ()
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	t_list	*lst = NULL;
	char			*str;
	int				was_read;

	if (fd < 0 || read(fd, NULL, 0) == -1 )//|| !line)
		return (-1);
	if (!(lst = ft_lstsearchfd(fd, lst)))
		return(0);
	str = (char *)malloc(BUFF_SIZE + 1);
	while (!(str = ft_strchr(lst->content, '\n')))
	{
		if (!(was_read = read(fd, str, BUFF_SIZE)))
			return (-1);
		str[was_read] = '\0';
		lst->content = str;
		//ft_search_n(lst, line);
		printf("2 lst->content = %s\n", lst->content);
	}
	free(str);
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
	argc++;
	while (argv > 1)
	{
		fd = open(*argc, O_RDONLY);
		//printf("%s\n", *argc);
		argv--;
		argc++;
		get_next_line(fd, &line);
	}
	return (0);
}