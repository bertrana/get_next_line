#include <fcntl.h>
#include <unistd.h>
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
		end = end->next;
	}
	return (end);
}

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	if (!str)
	    return (0);
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *str, int symbol)
{
	if (!str)
		return (NULL);
	while (*str && *str != symbol)
		str++;
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
	if (!str || (!s1 && !s2))
		return (NULL);
	if (s1)
        while (s1[i] != '\0' && s1)
        {
            str[i] = s1[i];
            i++;
        }
	while (s2[j] != '\0' && s2)
	{
		str[i++] = s2[j++];
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
    char		*str;
    size_t		i;

    i = 0;
    str = (char *)malloc(len + 1);
    if (!str || !s || start > ft_strlen(s))
        return (NULL);
    while (s[start] != '\0' && len > i)
    {
        str[i] = s[start];
        i++;
        start++;
    }
    if (s[start] != '\0' && len != i)
        return (NULL);
    str[i] = '\0';
    return (str);
}

int     ft_cut_cont(const t_list *lst, int was_read, char **line)
{
    char *str;
    int i;

    i = 0;
    str = (char *)lst->content;
    while (str[i] != '\n' && str[i])
        i++;
    if (was_read == 0)// || was_read < BUFF_SIZE)
    {
        *line = (char *)lst->content;
    }
    if (str[i] == '\n')
        *line = ft_strsub((const char *)lst->content, 0, i);
    return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*lst = NULL;
	char	        str[BUFF_SIZE + 1];// чтобы не возиться с очищением и выделением памяти
	int	    	    was_read;

	if (fd < 0 || read(fd, NULL, 0) == -1 )//|| !line)
		return (-1);
	if (!(lst = ft_lstsearchfd(fd, lst)))
		return(0);
	was_read = BUFF_SIZE;
	while (!(ft_strchr(lst->content, '\n')))
	{
		if ((was_read = read(fd, str, BUFF_SIZE)) < 0)
			return (-1);
		str[was_read] = '\0';
		lst->content = ft_strjoin(lst->content, str);
	}
	return (ft_cut_cont(lst, was_read, line));
}

int		main(int argv, char **argc)
{
	int		fd;
	char	*line;

	fd = 0;
	line = NULL;
	//if (argv < 2)
	//	return (0);

	fd = open("C:\\1my_programs\\get_next_line\\README.md", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	return (0);
}