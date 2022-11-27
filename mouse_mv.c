/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_mv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:36:14 by adbaich           #+#    #+#             */
/*   Updated: 2022/11/27 22:09:41 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	func(int x, int y, t_cub *cub)
{
    static int	old_x;

	(void)y;
	// mlx_mouse_get_pos(cub->win, &cub->mouse_x, &cub->mouse_y);
	// printf("x: %d\n", x);
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
	old_x = x;
	return (0);
}