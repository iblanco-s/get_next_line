/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inigo <inigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:16:02 by inigo             #+#    #+#             */
/*   Updated: 2022/11/10 19:16:44 by inigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static int			i = -2;
	static char			*acumulator;
	static char			*temp;
	char				buffer[BUFFER_SIZE];

	if (fd < -1) // no seria menor que 0?
		return (NULL);
	if (i == -2)
	{
		acumulator = malloc(1);
		if (!acumulator)
			return (NULL);
		acumulator[0] = '\0'; //esto esta bien asi en el primer ft_strjoin?
	}
    while (read(fd, buffer, BUFFER_SIZE))
    {
    	temp = ft_strjoin(acumulator, buffer);
    	acumulator = temp;
    	i = ft_check_n(acumulator); //esta bien la `posicion o debo restar -1 ?
    	if (i >= 0)
    	{
     		acumulator = ft_mod_substr(temp, i + 1);
			printf("\nDEBUGGER-ACUMULATOR = %s", acumulator);
      		temp[i + 1] = '\0';
      		return (temp);
    	}
	}
	printf("\nDEBUGGER-BUFFER = %s", buffer);
	return (acumulator);
}

int main(void)
{
	int fd1 = open("test.txt", O_RDONLY);
	if (fd1 < 0)
	{
		perror("c1");
		exit(1);
	}
	for(int i = 0; i < 4; i++)
		printf("\nreturned string is = %s", get_next_line(fd1));
	if (close(fd1) < 0)
	{
		perror("c1");
		exit(1);
	}
	//printf("\nclosed the fd.\n");
}
