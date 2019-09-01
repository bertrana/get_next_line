#include "get_next_line.h"

t_list	*ft_lstsearchfd(const int fd, const t_list *start)
{
	t_list	*end;
	char	*str;

	if (fd < 0)
	    return (NULL);
	if (start == NULL)
	{
		str = (char *)malloc(1);
		str[0] = '\0';
		return (ft_lstnew(str, (size_t) fd));
	}
	end = (t_list *)start;
	while (end->next)
	{
		if (end->content_size == (size_t)fd)
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
    if (was_read < BUFF_SIZE && (*str)[i] == '\0')// конец файла
    {
        *line = *str;
        return (0);
    }
    if ((*str)[i] == '\n') //строка до абзаца
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
	char	        str[BUFF_SIZE + 1];
	int	    	    was_read;
	char            *tmp;
	int             i;

	i = 0;
	if (!(lst = ft_lstsearchfd(fd, lst)))
		return (-1);//free_all(&lst, line, &tmp));
	was_read = BUFF_SIZE;
	while (!(ft_strchr(lst->content, '\n')))
	{
		if ((was_read = read(fd, str, BUFF_SIZE)) < 0)
			return (-1);
		if (was_read != 0)
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

int		main()//int argv, char **argc)
{
	int		fd;
	char	*line;
	int     i;

	int		out;
	int		p[2];
	//int		gnl_ret;

	fd = 1;
	out = dup(fd);
	pipe(p);
	dup2(p[1], fd);
	write(fd, "aaa", 3);
	close(p[1]);
	dup2(out, fd);
	i = gnl(p[0], &line);

/*
	fd = 0;
	line = NULL;
	fd = open("/Users/yjohns/gnl_my_git/ab.c", O_RDONLY);
	while ((i = gnl(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}*/
	if (i == 0)
    {
        printf("%s\n", line);
        free(line);
    }
	return (0);
}