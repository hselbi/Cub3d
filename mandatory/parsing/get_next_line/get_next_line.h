/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:04:57 by adbaich           #+#    #+#             */
/*   Updated: 2022/12/07 11:42:31 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 100
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
void	ft_free(char **s);
char	*ft_reading(int fd, char *d_main);
char	*ft_returning(char	*d_main);
char	*ft_modifying(char *d_main);

#endif
