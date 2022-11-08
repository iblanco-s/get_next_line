/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inigo <inigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:16:02 by inigo             #+#    #+#             */
/*   Updated: 2022/11/08 20:31:45 by inigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	//static ssize_t		i;
	static char			*acumulator;
	char				buffer[BUFFER_SIZE];
	char				*temp;


	//i = 0;
	if (fd < -1)
		return (NULL);
	acumulator = malloc(1);
	if (!acumulator)
		return (NULL);
	acumulator[0] = '\0';
	//read(fd, buffer, BUFFER_SIZE);
	while (BUFFER_SIZE == read(fd, buffer, BUFFER_SIZE))
	{
		temp = ft_strjoin(acumulator, buffer);
		acumulator = temp;
		//printf("\nDEPURAR %s", acumulator);
	}
	return (acumulator);
}

int main()
{
	int fd1 = open("test.txt", O_RDONLY);
	if (fd1 < 0)
	{
		perror("c1");
		exit(1);
	}
	printf("\nreturned string is = \n%s", get_next_line(fd1));
	if (close(fd1) < 0)
	{
		perror("c1");
		exit(1);
	}
	//printf("\nclosed the fd.\n");
}
