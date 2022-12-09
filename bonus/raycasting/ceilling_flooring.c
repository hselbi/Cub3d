/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceilling_flooring.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hselbi <hselbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 01:00:50 by hselbi            #+#    #+#             */
/*   Updated: 2022/12/07 01:00:51 by hselbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ceilling_floor_max(t_cub *cub)
{
	unsigned int	i;
	int				j;

	i = 0;
	j = 0;
	while (j < (cub->height / 2))
	{
		i = 0;
		while (++i < (unsigned)cub->width - 1)
			cub->addr[(cub->width) * j + i] = create_rgb(cub->par.color[1][0], \
				cub->par.color[1][1], cub->par.color[1][2]);
		j++;
	}
	while (j < (cub->height - 1))
	{
		i = 0;
		while (++i < (unsigned)cub->width - 1)
			cub->addr[(cub->width) * j + i] = create_rgb(cub->par.color[0][0], \
				cub->par.color[0][1], cub->par.color[0][2]);
		j++;
	}
}
