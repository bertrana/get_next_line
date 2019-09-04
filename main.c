#include "get_next_line.h"

int		main()//int argv, char **argc)
{
	int		fd;
	char	*line;
	int     i;

	line = NULL;
	fd = open("/Users/yjohns/gnl_my_git/gnl7_3.txt", O_RDONLY);
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("gnl return %d\n", i);
		printf("%s\n", line);
		free(line);
	}
	if (i == 0)
    {
        printf("%s", line);
        //free(line);
    }
	return (0);
}