/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imendonc <imendonc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:10:22 by imendonc          #+#    #+#             */
/*   Updated: 2022/12/07 13:18:19 by imendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//bibliotecas a incluir

//fcntl - manipulate file description
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

//funcoes pertencentes
char		*get_next_line(int fd);

#endif