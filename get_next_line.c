/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iblanco- <iblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:16:02 by inigo             #+#    #+#             */
/*   Updated: 2022/11/07 18:21:58 by iblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static ssize_t		i;
	static char			*acumulator;
	char				buffer[BUFFER_SIZE];
	char				ret[1];

	i = 0;
	if (fd < -1)
		return (NULL);
	read(fd, buffer, BUFFER_SIZE);
	while (buffer[i++] != '\n')
		i++;
	ft_memcpy(&ret[i], &buffer[i], 1);
	if (ret[i] == '\n')
	{	
		break ;
		i++;
	}
	return (ret);
}

// int main()
// {
// 	int fd1 = open("test.txt", O_RDONLY);
// 	if (fd1 < 0)
// 	{
// 		perror("c1");
// 		exit(1);
// 	}
// 	printf("\nreturned string is = %s", get_next_line(fd1));
// 	if (close(fd1) < 0)
// 	{
// 		perror("c1");
// 		exit(1);
// 	}
// 	//printf("\nclosed the fd.\n");
// }
