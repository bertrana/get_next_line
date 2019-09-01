#include "libft.h"

void    ft_strdup_free(char **s, char *arg)
{
    char    *tmp;
    tmp = *s;
    tmp = ft_strdup(arg);
    printf("%s - t\n", tmp);
    *s = tmp;
    free(tmp);
}