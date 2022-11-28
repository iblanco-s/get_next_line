/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iblanco- <iblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:08:47 by iblanco-          #+#    #+#             */
/*   Updated: 2022/11/28 13:06:18 by iblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_strlen(char *a)
{
	int	len;

	len = 0;
	while (a[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		i;
	size_t		k;
	char		*ret;

	i = 0;
	k = 0;
	ret = (malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char)));
	if (!ret)
		return (0);
	while (s1[k] != '\0')
	{
		ret[k] = s1[k];
		k++;
	}
	while (s2[i] != '\0')
	{
		ret[k] = s2[i];
		k++;
		i++;
	}
	ret[k] = '\0';
	return (ret);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
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
	int	i;

	i = 0;
	while (acumulator[i] != '\0')
	{
		if (acumulator[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_read(char *acumulator, char *buffer, int fd)
{
	char		*temp;
	int			j;

	j = 42;
	while (j > 0)
	{
		j = read(fd, buffer, BUFFER_SIZE);
		if (j < 0)
			return (NULL);
		else if (j == 0)
			break ;
		if (!acumulator)
			acumulator = ft_first();
		buffer[j] = '\0';
		temp = acumulator;
		acumulator = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_check_n(acumulator) >= 0)
			break ;
	}
	return (acumulator);
}
