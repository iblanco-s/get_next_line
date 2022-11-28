/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iblanco- <iblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:43:33 by iblanco-          #+#    #+#             */
/*   Updated: 2022/11/28 13:17:43 by iblanco-         ###   ########.fr       */
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
char	*ft_read(char *acumulator, char *buffer, int fd);
char	*ft_divide(char *ret, char **acumulator, int i);
char	*ft_first(void);

#endif