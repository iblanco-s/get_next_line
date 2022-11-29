/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inigo <inigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:08:41 by iblanco-          #+#    #+#             */
/*   Updated: 2022/11/29 20:20:03 by inigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_divide(char *ret)
{
	int		i;
	char	*temp;

	i = ft_check_n(ret);
	if (i < 0)
		return (NULL);
	temp = ft_substr(ret, i + 1, ft_strlen(ret) - i);
	if (*temp == '\0')
	{
		// printf("\nDIVIDE RET = %s //ACUM(TEMP) = %s", ret, temp);
		free (temp);
		temp = NULL;
	}
	ret[i + 1] = '\0';
	return (temp);
}

char	*ft_first(void)
{
	char	*str;

	str = malloc(sizeof(char) * (1));
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char		*acumulator;
	char			*ret;
	char			*buffer;
	int				j;

	j = 42;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	ret = ft_read(acumulator, buffer, fd, &j);
	free (buffer);
	if (!ret)
	{
		if (j < 0)
		{
			free(acumulator);
			acumulator = NULL;
		}
		return (NULL);
	}
	acumulator = ft_divide(ret);
	return (ret);
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
// 	// free (test);
// 	//printf("\nclosed the fd.\n");
// }
