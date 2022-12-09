/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hselbi <hselbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:09:33 by adbaich           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/12/07 11:32:06 by adbaich          ###   ########.fr       */
=======
/*   Updated: 2022/12/07 20:45:42 by hselbi           ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft/libft.h"

char	*ft_reading_helper(char *d_main, char *buff)
{
	char	*tmp;

	if (!d_main)
	{
		d_main = malloc(1 * sizeof(char));
		d_main[0] = '\0';
	}
	tmp = d_main;
	d_main = ft_strjoin(d_main, buff);
	free(tmp);
	return (d_main);
}

char	*ft_reading(int fd, char *d_main)
{
	char	*buff;
	int		rd_bytes;

	rd_bytes = 1;
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	if (!ft_strchr(d_main, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			ft_free(&buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		d_main = ft_reading_helper(d_main, buff);
	}
	ft_free(&buff);
	return (d_main);
}

char	*ft_returning(char	*d_main)
{
	char	*str;
	int		i;

	i = 0;
	while (d_main[i] != '\n' && d_main[i])
		i++;
	str = malloc(sizeof(char) * i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (d_main[i] && d_main[i] != '\n')
	{
		str[i] = d_main[i];
		i++;
	}
	if (d_main[i] == '\n')
	{
		str[i] = d_main[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_modifying(char *d_main)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (d_main[i] != '\n' && d_main[i])
		i++;
	if (d_main[i] == '\0')
	{
		ft_free(&d_main);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(d_main) - i +1));
	if (!str)
	{
		ft_free (&d_main);
		return (NULL);
	}
	i++;
	j = 0;
	while (d_main[i])
		str[j++] = d_main[i++];
	str[j] = '\0';
	ft_free(&d_main);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*d_main;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	d_main = ft_reading(fd, d_main);
	if (!d_main)
	{
		ft_free(&d_main);
		return (NULL);
	}
	if (!d_main[0])
	{
		ft_free(&d_main);
		return (NULL);
	}
	line = ft_returning(d_main);
	d_main = ft_modifying(d_main);
	return (line);
}
