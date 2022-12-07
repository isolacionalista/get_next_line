/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imendonc <imendonc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:10:22 by imendonc          #+#    #+#             */
/*   Updated: 2022/12/07 14:49:06 by imendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//bibliotecas a incluir

//fcntl - manipulate file description -- biblioteca para fopen
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

//funcoes pertencentes
char		*get_next_line(int fd);
char		*ft_strjoim(char *s1, char *s2);
size_t		ft_strlen(char *str);

#endif