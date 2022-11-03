/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inigo <inigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:16:02 by inigo             #+#    #+#             */
/*   Updated: 2022/11/03 20:55:50 by inigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*kdest;
	char	*ksrc;

	kdest = (char *)dest;
	ksrc = (char *)src;
	if (dest == NULL && src == NULL)
		return (0);
	while (n > 0)
	{
		*kdest = *ksrc;
		kdest++;
		ksrc++;
		n--;
	}
	return (dest);
}

char	*get_next_line(int fd)
{
	static ssize_t		numbytes;
	static ssize_t		i;
	char	buffer[BUFFER_SIZE];
	char	*ret;

	i++;
	if (fd < -1)
		return (NULL);
	ret = malloc(sizeof(char) * BUFFER_SIZE);
	if (!ret)
		return (NULL);
	numbytes = read(fd, buffer, BUFFER_SIZE); //ahora falta hacer el salto de linea (no vale leer todo y luego devolver hasta el salto de linea)
	printf("numbytes variable = %zd ", numbytes);
	ft_memcpy(ret, buffer, numbytes);
	// while (i <= BUFFER_SIZE)
	// {
	// 	//printf("i variable = %zd ", i);
	// 	//numbytes = read(fd, buffer, 1);
	// 	ft_memcpy(ret, buffer, 3);
	// 	if (ret[i] == '\n')
	// 		break;
	// 	i++;
	// }
	return (ret);
}

int main()
{
	int fd1 = open("test.txt", O_RDONLY);
	if (fd1 < 0)
	{
		perror("c1");
		exit(1);
	}
	printf("\nreturned string is = %s", get_next_line(fd1));
	if (close(fd1) < 0)
	{
		perror("c1");
		exit(1);
	}
	//printf("\nclosed the fd.\n");
}
