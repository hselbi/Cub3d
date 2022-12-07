/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_mv_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hselbi <hselbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:36:14 by adbaich           #+#    #+#             */
/*   Updated: 2022/12/07 01:09:34 by hselbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	func(int x, int y, t_cub *cub)
{
	int	old_x;

	(void)y;
	old_x = (cub->width / 2);
	if (old_x - x < 0)
	{
		cub->p.p_angle += 0.05;
		if (cub->p.p_angle > 2 * PI)
			cub->p.p_angle -= 2 * PI;
		cub->p.dem_x = cos(cub->p.p_angle) * 5;
		cub->p.dem_y = sin(cub->p.p_angle) * 5;
	}
	else if (old_x - x > 0)
	{
		cub->p.p_angle -= 0.05;
		if (cub->p.p_angle < 0)
			cub->p.p_angle += 2 * PI;
		cub->p.dem_x = cos(cub->p.p_angle) * 5;
		cub->p.dem_y = sin(cub->p.p_angle) * 5;
	}
	mlx_mouse_move(cub->win, (cub->width / 2), (cub->height / 2));
	return (0);
}

int	mouse_hook(int button, int x, int y, t_cub *cub)
{
	(void)cub;
	(void)y;
	(void)x;
	if (button == 1 && cub->gun_shot == FALSE)
	{
		cub->gun_shot = TRUE;
		cub->sprite.ind = 0;
	}
	return (0);
}
