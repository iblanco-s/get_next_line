/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iblanco- <iblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:08:41 by iblanco-          #+#    #+#             */
/*   Updated: 2022/11/28 13:27:29 by iblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_divide(char *ret, char **acumulator, int i)
{
	*acumulator = ft_substr(ret, i + 1, ft_strlen(ret) - i);
	if (**acumulator == '\0')
	{
		free (acumulator);
		acumulator = NULL;
	}
	ret[i + 1] = '\0';
	return (ret);
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
	static int		i = 0;
	static char		*acumulator;
	char			*ret;
	char			*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	ret = ft_read(acumulator, buffer, fd);
	free (buffer);
	if (!ret || i == -5)
	{
		free(acumulator);
		acumulator = NULL;
		return (NULL);
	}
	i = ft_check_n(ret);
	if (i >= 0)
	{
		// acumulator = ret;
		return (ft_divide(ret, &acumulator, i));
	}
	i = -5;
	return (ret);
}

//printf("\nDEBUGGER-ACUMULATOR = %s", acumulator);

int main(void)
{
	char	*test;
	int fd1 = open("test.txt", O_RDONLY);
	if (fd1 < 0)
	{
		perror("c1");
		exit(1);
	}
	for(int i = 0; i < 4; i++)
	{
		test = get_next_line(fd1);
		printf("\nReturned string is = %s", test);
	}
	if (close(fd1) < 0)
	{
		printf("ha entrado");
		perror("c1");
		exit(1);
	}
	free (test);
	//printf("\nclosed the fd.\n");
}
