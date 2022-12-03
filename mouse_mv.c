/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_mv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hselbi <hselbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:36:14 by adbaich           #+#    #+#             */
/*   Updated: 2022/12/03 13:46:06 by hselbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	func(int x, int y, t_cub *cub)
{
    static int	old_x;

	(void)y;
	if (old_x - x < 0)
	{
		cub->p.p_angle += 0.08;
		if (cub->p.p_angle > 2 * PI)
			cub->p.p_angle -= 2 * PI;
		cub->p.dem_x = cos(cub->p.p_angle) * 5;
		cub->p.dem_y = sin(cub->p.p_angle) * 5;
	}
	else if (old_x - x > 0)
	{
		cub->p.p_angle -= 0.08;
		if (cub->p.p_angle < 0)
			cub->p.p_angle += 2 * PI;
		cub->p.dem_x = cos(cub->p.p_angle) * 5;
		cub->p.dem_y = sin(cub->p.p_angle) * 5;
	}
	old_x = x;
	return (0);
}