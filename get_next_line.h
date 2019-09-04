/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 22:42:18 by yjohns            #+#    #+#             */
/*   Updated: 2019/08/30 14:31:35 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE 128
//# define FT_OPEN_MAX 1024

t_list	*ft_lstsearchfd(const int fd, t_list *start);
int		ft_cut_cont(void **vo, int was_read, char **line);
int		get_next_line(const int fd, char **line);

#endif
