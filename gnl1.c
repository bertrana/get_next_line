#include "get_next_line.h"

t_list	*ft_lstsearchfd(size_t fd, const t_list *start)
{
	t_list	*end;

	if (start == NULL)
		return (ft_lstnew("", (size_t)fd));
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
    if (was_read == 0 && (*str)[i] == '\0')// || was_read < BUFF_SIZE)
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

int		gnl(const int fd, char **line)
{
	static t_list	*lst = NULL;
	char	        str[BUFF_SIZE + 1];// чтобы не возиться с очищением и выделением памяти
	int	    	    was_read;
	char            *tmp;

	if (fd < 0) //|| read(fd, NULL, 0) == -1 )//|| !line)
		return (-1);
	if (!(lst = ft_lstsearchfd(fd, lst)))
		return (0);
    //lst = ft_lstsearchfd(fd, lst);
	was_read = BUFF_SIZE;
	while (!(ft_strchr(lst->content, '\n')))
	{
		if ((was_read = read(fd, str, BUFF_SIZE)) < 0)
			return (-1);
		str[was_read] = '\0';
		if (!(tmp = ft_strjoin(lst->content, str)))
			return (-1);
		//free(lst->content);
		lst->content = tmp;
	}
	return (ft_cut_cont(&(lst->content), was_read, line));
}

int		main()//int argv, char **argc)
{
	int		fd;
	char	*line;

	fd = 0;
	line = NULL;
	//if (argv < 2)
	//	return (0);

	fd = open("get_next_line.c", O_RDONLY);
	while (gnl(fd, &line) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	return (0);
}