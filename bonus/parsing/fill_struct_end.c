/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct_end.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:11:05 by adbaich           #+#    #+#             */
/*   Updated: 2022/12/05 20:06:57 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include "cub3d_pars.h"

void	valid_map_helper(char **map, int i, int j)
{
	if (included("NSWE0", map[i][j]))
	{
		if (j)
		{
			if (map[i][j + 1] == ' ' || map[i][j + 1] == '\t')
				ft_error();
			else if (map[i][j - 1] == ' ' || map[i][j - 1] == '\t')
				ft_error();
		}
		if (i)
		{
			if (map[i + 1][j] == ' ' || map[i + 1][j] == '\t')
				ft_error();
			else if (map[i - 1][j] == ' ' || map[i - 1][j] == '\t')
				ft_error();
		}
	}
}

void	valid_map(char **map)
{
	int	i;
	int	j;

	i = 1;
	first_last_line(map[0]);
	first_last_line(map[ft_strlen_2d(map) - 1]);
	while (i < (int)ft_strlen_2d(map) - 1)
	{
		j = 0;
		while (map[i][j])
		{
			valid_map_helper(map, i, j);
			j++;
		}
		i++;
	}
}

void	fill_struct_end(t_txt *toto)
{
	if (!toto->position)
		ft_error();
	toto->map = ft_split(toto->mini_map, '\n');
	free(toto->txt_index);
	free(toto->mini_map);
	valid_map(toto->map);
}
