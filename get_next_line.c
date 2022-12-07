/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imendonc <imendonc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:10:16 by imendonc          #+#    #+#             */
/*   Updated: 2022/12/07 15:32:42 by imendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
a funcao read tenta ler nbytes de um ficheiro que esta associado a
descricao depois do open (estara no main)
*/

/*
o BUFFER_SIZE esta definido no header. quando e testado,
o size e alteravel. neste caso usamos o termo BUFFER_SIZE
previamente definido para que a variavel possa ser modificada
ex: o meu buffer esta definido para 50, quando digo BUFFER_SIZE + 1
(para ter espaco para o null) estou na verdade a dizer 50 + 1
*/

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
			return NULL;
		if (fake_bzero(b) == 1)
			break;
		if (read(fd, b , 0) < 0)
		{
			free(str);
			return (NULL);
		}
		b[read(fd, b, BUFFER_SIZE)] = 0;
	}
	return (str);
}

/*
as primeiras 2 condicoes sao apenas protecoes
------------
enquanto o array de b se encontra na posicao 0, a variavel
str passa a ser a juncao de *str + b[]
a primeira condicao e mais uma protecao pedida no enunciado
-------------
quando o ficheiro que a funcao read vai abrir for negativo
(impossivel) ele liberta a variavel str e retorna NULL
------------
retorna str que dentro do loop foi definido como a juncao de *str e b[]
*/