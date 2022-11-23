/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iblanco- <iblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:16:02 by inigo             #+#    #+#             */
/*   Updated: 2022/11/23 17:17:41 by iblanco-         ###   ########.fr       */
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

char	*ft_first(void)
{
	char	*str;

	str = malloc(1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static int			i;
	static int			j;
	static int			first = 0;
	static char			*acumulator;
	char				*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!acumulator)
		acumulator = ft_first(&j);
	while (j == BUFFER_SIZE)
		ret = ft_read(acumulator, &j, fd);
	if (!ret)
	{
		free(acumulator);
		acumulator = NULL;
		return (NULL);
	}
	if (j == 0)
		return(acumulator)
	// if (acumulator)
	// {
	// 	i = ft_check_n(acumulator);
	// 	if (i >= 0)
	// 		return (ft_divide(&acumulator, &i));
	// }
	// if (!i == -3)
	// {
	// 	if (first == 0)
	// 		free(acumulator);
	// 	return (first++, NULL);
	// }
	// i = -3;
	// return (acumulator);
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
// 		printf("\nReturned string is = %s", test);
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
