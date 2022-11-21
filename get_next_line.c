/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iblanco- <iblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:16:02 by inigo             #+#    #+#             */
/*   Updated: 2022/11/21 16:46:19 by iblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_divide(char **acumulator, int *i)
{
	char	*temp;

	temp = *acumulator;
	*acumulator = ft_substr(temp, *i + 1, ft_strlen(temp));
	temp[*i + 1] = '\0';
	return (temp);
}

char	*get_next_line(int fd)
{
	static int			i;
	static int			j;
	static char			*acumulator;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!acumulator)
	{
		acumulator = malloc(1);
		if (!acumulator)
			return (NULL);
		acumulator[0] = '\0';
		j = BUFFER_SIZE;
	}
	while (j == BUFFER_SIZE || ft_check_n(acumulator) >= 0)
	{
		i = ft_check_n(acumulator);
		if (i >= 0)
			return (ft_divide(&acumulator, &i));
		acumulator = ft_read (acumulator, &j, fd);
		i = ft_check_n(acumulator);
	}
	if (i == -3)
		return (NULL);
	i = -3;
	return (acumulator);
}

//printf("\nDEBUGGER-ACUMULATOR = %s", acumulator);

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
