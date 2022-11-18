/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iblanco- <iblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:16:02 by inigo             #+#    #+#             */
/*   Updated: 2022/11/18 19:08:45 by iblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static int			i = -2;
	static int			j = BUFFER_SIZE;
	static char			*acumulator;
	char				*temp;
	char				*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (i == -2)
	{
		acumulator = malloc(1);
		if (!acumulator)
			return (NULL);
		acumulator[0] = '\0';
	}
	while (j == BUFFER_SIZE || ft_check_n(acumulator) >= 0 || i == -2)
	{
		i = ft_check_n(acumulator);
		if (i >= 0)
		{
			temp = acumulator;
			acumulator = ft_substr(temp, i + 1, ft_strlen(temp));
			free (temp);
			temp[i + 1] = '\0';
			return (temp);
		}
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		j = read(fd, buffer, BUFFER_SIZE);
		buffer[j] = '\0';
		temp = ft_strjoin(acumulator, buffer, j);
		free (acumulator);
		free (buffer);
		acumulator = temp;
		i = ft_check_n(acumulator);
	}
	if (i == -3)
	{
		free (acumulator);
		return (NULL);
	}
	i = -3;
	return (acumulator);
}

// //printf("\nDEBUGGER-ACUMULATOR = %s", acumulator);

// int main(void)
// {
// 	char	*test;
// 	int fd1 = open("test.txt", O_RDONLY);
// 	if (fd1 < 0)
// 	{
// 		perror("c1");
// 		exit(1);
// 	}
// 	for(int i = 0; i < 4; i++)
// 	{
// 		test = get_next_line(fd1);
// 		printf("\nreturned string is = %s", test);
// 	}
// 	if (close(fd1) < 0)
// 	{
// 		printf("ha entrado");
// 		perror("c1");
// 		exit(1);
// 	}
// 	free (test);
// 	//printf("\nclosed the fd.\n");
// }
