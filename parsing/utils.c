/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:58:55 by adbaich           #+#    #+#             */
/*   Updated: 2022/12/08 15:44:55 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include "cub3d_pars.h"

void	ft_error(void)
{
	write(2, "Error\nInvalid Map !\n", ft_strlen("Error\nInvalid Map !\n"));
	exit(1);
}

size_t	max_len(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s1_len > s2_len)
		return (s1_len);
	return (s2_len);
}

void	fill_id(char *id, char *str, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		id[i] = str[i];
		i++;
	}
	id[len - 1] = '\0';
}

char	*fill_path(char *str, char *path, int i)
{
	int	j;

	j = 0;
	while (str[i])
	{
		path[j] = str[i];
		j++;
		i++;
	}
	path[j] = '\0';
	return (path);
}

int	check_ext(char *file)
{
	char	*str;

	str = ft_strrchr(file, '.');
	if (str && !ft_strncmp(str, ".cub", max_len(str, ".cub")))
		return (0);
	return (1);
}
