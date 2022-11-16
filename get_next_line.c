/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inigo <inigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:16:02 by inigo             #+#    #+#             */
/*   Updated: 2022/11/16 19:48:14 by inigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static int			i = -2;
	static int			j = BUFFER_SIZE;
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
		acumulator[0] = '\0'; 
	}
    while (j == BUFFER_SIZE || ft_check_n(acumulator) >= 0)
    {
    	i = ft_check_n(acumulator); 
    	if (i >= 0)
    	{
			temp = acumulator;
     		acumulator = ft_substr(temp, i + 1, ft_strlen(temp));
			printf("\nDEBUGGER-ACUMULATOR = %s", acumulator);
      		temp[i + 1] = '\0';
      		return (temp);
    	}
		j = read(fd, buffer, BUFFER_SIZE);
		temp = ft_strjoin(acumulator, buffer, j);
    	acumulator = temp;
	}
	//printf("\nDEBUGGER-BUFFER = %s", temp);
	//acumulator = ft_mod_substr(temp, 0, ft_strlen(temp) + j);
	return (acumulator);
}

// int main(void)
// {
// 	int fd1 = open("test.txt", O_RDONLY);
// 	if (fd1 < 0)
// 	{
// 		perror("c1");
// 		exit(1);
// 	}
// 	for(int i = 0; i < 4; i++)
// 		printf("\nreturned string is = %s", get_next_line(fd1));
// 	if (close(fd1) < 0)
// 	{
// 		perror("c1");
// 		exit(1);
// 	}
// 	//printf("\nclosed the fd.\n");
// }
