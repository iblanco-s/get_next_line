/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inigo <inigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:16:02 by inigo             #+#    #+#             */
/*   Updated: 2022/11/02 18:46:19 by inigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// char	*get_next_line(int fd)
// {
// C program to illustrate close system Call
#include <stdio.h>
#include <fcntl.h>
#include <errno.h> 
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int fd1 = open("test.txt", O_RDONLY);
	if (fd1 < 0)
	{
		perror("c1");
		exit(1);
	}
	printf("opened the fd = % d\n", fd1);
	
	// Using close system Call
	if (close(fd1) < 0)
	{
		perror("c1");
		exit(1);
	}
	printf("closed the fd.\n");
}

// }