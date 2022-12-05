/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_mv_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hselbi <hselbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:36:14 by adbaich           #+#    #+#             */
/*   Updated: 2022/12/05 21:13:54 by hselbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	func(int x, int y, t_cub *cub)
{
    int	old_x = (cub->width / 2);

	(void)y;
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

int	mouse_btn(int key_code, t_cub *cub)
{
	printf("%d\n", cub->col);
	printf("the key's code is : %d\n", key_code);
	return (0);
}
