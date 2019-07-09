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

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *str, int symbol)
{
	printf("ppppp\n");
	if (!str)
		return (NULL);
	while (*str && *str != symbol)
		str++;
	printf("find \\n\n");
	if (*str == symbol)
		return ((char *)str);
	else
		return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str || !s1 || !s2)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i++] = s2[j++];
	}
	str[i] = '\0';
	return (str);
}
/*
int		ft_search_n(t_list *lst, char **line)
{

	if ()
	return (0);
}
*/
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
	//пока в структуре не будет абзаца, то считываем буфер
	printf("myau\n");
	while (!(str = ft_strchr(lst->content, '\n')))
	{
		if (!(was_read = read(fd, str, BUFF_SIZE)))
			return (-1);
		str[was_read] = '\0';
		printf("str = %s\n", str);
		//lst->content = ft_strjoin(lst->content, str);
		//ft_search_n(lst, line);
		printf("2 lst->content = %s\n", lst->content);
	}
	printf("%c\n", *str);
	if (*str == '\n')
	{
		printf("yes\n");
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