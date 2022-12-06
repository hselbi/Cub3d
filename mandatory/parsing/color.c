/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:42:43 by adbaich           #+#    #+#             */
/*   Updated: 2022/11/30 18:39:29 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "cub3d_pars.h"

void	len_of_num(char *num)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (num[i])
	{
		if (!count && num[i] == '+')
			count++;
		if (num[i] != '0')
			break ;
		i++;
	}
	if (ft_strlen(num) - i - count > 3)
		ft_error();
}

void	valid_color_range(int *arr)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (arr[i] < 0 || arr[i] > 255)
			ft_error();
		i++;
	}
}

void	free_2d(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	get_color(char *path, t_txt *toto, int id_index)
{
	char	**colors;
	int		i;

	colors = ft_split(path, ',');
	free(path);
	i = 0;
	while (colors[i])
		len_of_num(colors[i++]);
	i = -1;
	if (id_index == 4)
	{
		while (colors[++i])
			toto->color[0][i] = ft_atoi(colors[i]);
		valid_color_range(toto->color[0]);
	}
	else if (id_index == 5)
	{
		while (colors[++i])
			toto->color[1][i] = ft_atoi(colors[i]);
		valid_color_range(toto->color[1]);
	}
	free_2d(colors);
}
