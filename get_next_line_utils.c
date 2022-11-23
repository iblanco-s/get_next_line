/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iblanco- <iblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:19:38 by inigo             #+#    #+#             */
/*   Updated: 2022/11/23 17:20:26 by iblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_strlen(const char *a)
{
	int	len;

	len = 0;
	while (a[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2, int lens2)
{
	size_t		i;
	size_t		k;
	char		*ret;

	i = ft_strlen(s1);
	k = 0;
	ret = (malloc((i + lens2 + 1) * sizeof(char)));
	if (ret == NULL)
		return (0);
	i = 0;
	while (s1[k] != '\0')
	{
		ret[k] = s1[k];
		k++;
	}
	while (s2[i])
	{
		ret[k] = s2[i];
		k++;
		i++;
	}
	ret[k] = '\0';
	return (ret);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*ret;
	size_t				i;

	i = 0;
	if (!s)
		return (0);
	else if ((unsigned int)ft_strlen(s) < start)
		len = 0;
	else if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	ret = ((char *)malloc(sizeof(char) * (len + 1)));
	if (ret == NULL)
		return (0);
	while (len > (size_t)i)
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

int	ft_check_n(char *acumulator)
{
	static int	j = 0;
	int	i;

	i = 0;
	while (acumulator[i] != '\0')
	{
		if (acumulator[i] == '\n')
			return (i);
		i++;
	}
	if (j == 0)
		return (j++, -1);
	else	
		return (-3);
}

char	*ft_read(char *acumulator, int *j, int fd)
{
	char	*buffer;
	char	*temp;
	int		i;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	*j = read(fd, buffer, BUFFER_SIZE);
	if (*j > 0)
	{
		buffer[*j] = '\0';
		temp = acumulator;
		acumulator = ft_strjoin(temp, buffer, *j);
		free (temp);
		temp = NULL; //el porque preguntar a jon/es
	}
	free (buffer);
	buffer = NULL;
	i = ft_check_n(acumulator);
	if (i >= 0)
		return (ft_divide(&acumulator, &i));
	return (acumulator);
}


char	*ft_read(int fd)
{
	static int		j = BUFFER_SIZE;
	static char		*acumulator;
	char			*temp;
	char			*buffer;
	
	buffer = malloc(BUFFER_SIZE + 1);
	while (j == BUFFER_SIZE)
	{
		j = read(fd, buffer, BUFFER_SIZE);
		buffer[*j] = '\0';
		if (j <= 0)
			break;
		if (!acumulator)
			acumulator = ft_first();
		temp = ft_strjoin(acumulator, buffer, *j);
		acumulator = temp;
		free
		
	}
}