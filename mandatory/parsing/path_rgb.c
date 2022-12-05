/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_rgb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:37:29 by adbaich           #+#    #+#             */
/*   Updated: 2022/11/30 18:51:54 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_pars.h"
#include "libft/libft.h"

void	valid_members(char *path)
{
	int	i;

	i = 0;
	if (path[ft_strlen(path) - 1] == '+')
		ft_error();
	while (path[i] && ((path[i] >= '0' && path[i] <= '9')
			|| path[i] == ',' || path[i] == '+'))
	{
		if (i && path[i] == '+' && ((path[i + 1] < '0' || path[i + 1] > '9')
				|| path[i - 1] != ','))
			ft_error();
		i++;
	}
	if (path[i])
		ft_error();
}

void	before_after_comma(char *path)
{
	int	i;

	i = 0;
	if (path[i] == ',' || path[ft_strlen(path) - 1] == ',')
		ft_error();
	while (path[i])
	{
		if (path[i] == ',' && (!ft_isdigit(path[i - 1])
				|| (!ft_isdigit(path[i + 1]) && path[i + 1] != '+')))
			ft_error();
		i++;
	}
}

void	num_of_commas(char *path)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (path[i])
	{
		if (path[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		ft_error();
}

void	valid_path_rgb(char *path)
{
	valid_members(path);
	num_of_commas(path);
	before_after_comma(path);
}
