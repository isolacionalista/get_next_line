/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imendonc <imendonc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:02:43 by imendonc          #+#    #+#             */
/*   Updated: 2023/01/04 13:25:38 by imendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char		b[FOPEN_MAX][BUFFER_SIZE + 1];
	char			*str;

	str = NULL;
	if (fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	if (!b[fd][0])
		b[fd][read(fd, b[fd], BUFFER_SIZE)] = 0;
	while (b[fd][0])
	{
		str = ft_strjoin(str, b[fd]);
		if (!str)
			return (NULL);
		if (fake_bzero(b[fd]))
			break ;
		if (read(fd, 0, 0) < 0)
		{
			free(str);
			return (NULL);
		}
		b[fd][read(fd, b[fd], BUFFER_SIZE)] = 0;
	}
	return (str);
}

int main()
{
	char *line;
	char *line2;
	char *line3;
	int fd1;
	int fd2;
	int fd3;

	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	line = get_next_line(fd1);
	line2 = get_next_line(fd2);
	line3 = get_next_line(fd3);

	printf("%s", line);
	printf("%s", line2);
	printf("%s", line3);

	free(line);
	free(line2);
	free(line3);
}