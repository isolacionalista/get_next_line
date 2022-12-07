/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imendonc <imendonc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:31:07 by imendonc          #+#    #+#             */
/*   Updated: 2022/12/07 17:03:08 by imendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char		b[BUFFER_SIZE + 1];
	char			*str;

	str = NULL;
	if (fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	if (!b[0])
		b[read(fd, b, BUFFER_SIZE)] = 0;
	while (b[0])
	{
		str = ft_strjoin(str, b);
		if (!str)
			return (NULL);
		if (fake_bzero(b) == 1)
			break ;
		if (read(fd, b, 0) < 0)
		{
			free(str);
			return (NULL);
		}
		b[read(fd, b, BUFFER_SIZE)] = 0;
	}
	return (str);
}

/* int main()
{
	char *line;
	int		fd1;
	fd1 = open("test.txt", O_RDONLY);
	line = get_next_line(fd1);
	printf("T1:%s", line);
	free(line);
	line = get_next_line(fd1);
	printf("T1:%s", line);
	free(line);
		line = get_next_line(fd1);
	printf("T1:%s", line);
	free(line);
	line = get_next_line(fd1);
	printf("T1:%s", line);
	free(line);
}
*/
