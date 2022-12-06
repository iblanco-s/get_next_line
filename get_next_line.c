/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iblanco- <iblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:08:41 by iblanco-          #+#    #+#             */
/*   Updated: 2022/11/30 17:31:27 by iblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_read(char *acumulator, char *buffer, int fd, int *j)
{
	char		*temp;

	while (*j > 0)
	{
		*j = read(fd, buffer, BUFFER_SIZE);
		if (*j < 0)
			return (NULL);
		else if (*j == 0)
			break ;
		if (!acumulator)
			acumulator = ft_first();
		buffer[*j] = '\0';
		temp = acumulator;
		acumulator = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_check_n(acumulator) >= 0)
			break ;
	}
	return (acumulator);
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

//MAIN
// int	main(void)
// {
// 	int		fd1;
// 	int 	i;
// 	char	*test;
//
// 	fd1 = open("test.txt", O_RDONLY);
// 	i = 0;
// 	test = "";
// 	while(i < 4)
// 	{
// 		test = get_next_line(fd1);
// 		printf("\nReturned string is = %s", test);
// 		if(!test)
// 			return(0);
// 		free(test);
// 		i++;
// 	}
// 	return (0);
// }