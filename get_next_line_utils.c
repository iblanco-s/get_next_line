/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iblanco- <iblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:19:38 by inigo             #+#    #+#             */
/*   Updated: 2022/11/21 16:15:20 by iblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	while (lens2 > 0)
	{
		ret[k] = s2[i];
		k++;
		i++;
		lens2--;
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
	int	i;

	i = 0;
	while (acumulator[i] != '\0')
	{
		if (acumulator[i] == '\n')
			return (i);
		i++;
	}
	if (acumulator[0] == '\0')
		return (-3);
	else
		return (-1);
}

char	*ft_read(char *acumulator, int *j, int fd)
{
	char	*buffer;
	char	*temp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	*j = read(fd, buffer, BUFFER_SIZE);
	buffer[*j] = '\0';
	temp = ft_strjoin(acumulator, buffer, *j);
	free (acumulator);
	free (buffer);
	acumulator = temp;
	return (acumulator);
}
