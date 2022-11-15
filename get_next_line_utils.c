/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inigo <inigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:19:38 by inigo             #+#    #+#             */
/*   Updated: 2022/11/10 18:06:19 by inigo            ###   ########.fr       */
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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*kdest;
	char	*ksrc;

	kdest = (char *)dest;
	ksrc = (char *)src;
	if (dest == NULL && src == NULL)
		return (0);
	while (n > 0)
	{
		*kdest = *ksrc;
		kdest++;
		ksrc++;
		n--;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		j;
	size_t		k;
	char		*ret;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	k = 0;
	ret = (malloc((i + j + 1) * sizeof(char)));
	if (ret == NULL)
		return (0);
	j = 0;
	while (s1[k] != '\0')
	{
		ret[k] = s1[k];
		k++;
	}
	while (s2[j] != '\0')
	{
		ret[k] = s2[j];
		k++;
		j++;
	}
	ret[k] = '\0';
	return (ret);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (src[i] != '\0')
		i++;
	if (len > 0)
	{
		while (src[k] != '\0')
		{
			dest[k] = src[k];
			k++;
			if (k == len)
			{
				k--;
				break ;
			}
		}
		dest[k] = '\0';
	}
	return (i);
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

char	*ft_mod_substr(char const *s, unsigned int start)
{
	char				*ret;
	size_t				i;
	size_t				len;
	
	len = ft_strlen(s);
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

int ft_check_n(char *acumulator)
{
  int i;
 
  i = 0;
  while (acumulator[i] != '\0')
  {
    if(acumulator[i] == '\n')
      return (i);
    i++;
  }
  i = -1;
  return (i);
}

