/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imendonc <imendonc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:10:22 by imendonc          #+#    #+#             */
/*   Updated: 2022/12/07 15:49:20 by imendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//bibliotecas a incluir

/*fcntl - manipulate file description -- biblioteca para fopen
que e utilizada na funcao principal
*/

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

//funcoes pertencentes
char		*get_next_line(int fd);
char		*ft_strjoin(char *s1, char *s2);
int			fake_bzero(char *buf);
size_t		ft_strlen(char *str);

#endif