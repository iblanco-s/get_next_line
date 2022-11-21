/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inigo <inigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:43:33 by iblanco-          #+#    #+#             */
/*   Updated: 2022/11/21 21:55:37 by inigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2, int lens2);
int		ft_strlen(const char *a);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_mod_substr(char const *s, unsigned int start);
int		ft_check_n(char *acumulator);
char	*ft_read(char *acumulator, int *j, int fd);
char	*ft_divide(char **acumulator, int *i);
char	*ft_first(int *j);

#endif