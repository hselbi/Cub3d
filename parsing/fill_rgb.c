/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_rgb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:55:34 by adbaich           #+#    #+#             */
/*   Updated: 2022/12/08 13:08:28 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include "cub3d_pars.h"

int	open_fd(char *file)
{
	int	fd;

	if (check_ext(file))
		ft_error();
	fd = open(file, O_RDONLY, 0422);
	if (fd == -1)
		ft_error();
	return (fd);
}

char	*get_path(char *str)
{
	int		i;
	int		len;
	char	*path;

	i = 0;
	while (str[i] != ' ' && str[i] != '\t')
		i++;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	len = ft_strlen(str) - i;
	path = malloc(sizeof(char) * len + 1);
	if (!path)
		return (NULL);
	path = fill_path(str, path, i);
	return (path);
}

void	fill_rgb(char *str, t_txt *toto, int id_index)
{
	char	*rgb_txt;

	rgb_txt = get_path(str);
	valid_path_rgb(rgb_txt);
	get_color(rgb_txt, toto, id_index);
}
