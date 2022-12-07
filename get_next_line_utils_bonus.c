/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imendonc <imendonc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:30:35 by imendonc          #+#    #+#             */
/*   Updated: 2022/12/07 17:03:02 by imendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	a;

	if (!str)
		return (0);
	a = 0;
	while (str[a] != '\n' && str[a])
	{
		a++;
	}
	return (a + (str[a] == '\n'));
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	a;
	size_t	b;
	char	*str;

	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	a = 0;
	b = 0;
	while (s1 && s1[a])
		str[b++] = s1[a++];
	a = 0;
	while (s2 && s2[a] && s2[a] != '\n')
		str[b++] = s2[a++];
	if (s2[a] == '\n')
		str[b++] = '\n';
	str[b] = '\0';
	free(s1);
	return (str);
}

int	fake_bzero(char *buf)
{
	int		a;
	int		b;
	int		nl;

	a = 0;
	b = 0;
	nl = 0;
	while (buf[a])
	{
		if (nl)
			buf[b++] = buf[a];
		if (buf[a] == '\n')
			nl = 1;
		buf[a++] = '\0';
	}
	return (nl);
}
