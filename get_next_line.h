/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inigo <inigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:43:33 by iblanco-          #+#    #+#             */
/*   Updated: 2022/11/29 20:15:02 by inigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *a);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_check_n(char *acumulator);
char	*ft_read(char *acumulator, char *buffer, int fd, int *j);
char	*ft_divide(char *ret);
char	*ft_first(void);

#endif