/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inigo <inigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:16:02 by inigo             #+#    #+#             */
/*   Updated: 2022/11/08 21:05:44 by inigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	//static ssize_t		i;
	static char			*acumulator;
	static char			*temp;
	char				buffer[BUFFER_SIZE];

	if (fd < -1)
		return (NULL);
	acumulator = malloc(1);
	if (!acumulator)
		return (NULL);
	acumulator[0] = '\0';
	while (read(fd, buffer, BUFFER_SIZE))
	{
		//i = 0;
		temp = ft_strjoin(acumulator, buffer);
		acumulator = temp;
		// while (acumulator[i] != '\0')
		// {
		// 	if(acumulator[i] == '\n')
		// 	{
		// 		ft_mod_substr(acumulator, s)
		// 	}
		// }
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
