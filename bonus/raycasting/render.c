/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hselbi <hselbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 01:03:19 by hselbi            #+#    #+#             */
/*   Updated: 2022/12/07 01:03:20 by hselbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	wall_checker(t_cub *cub)
{
	int	tmp_i;
	int	tmp_j;
	int	prev_i;
	int	prev_j;

	tmp_i = (int)(cub->p.x / 64);
	tmp_j = (int)(cub->p.y / 64);
	prev_i = (int)(cub->p.prev_x / 64);
	prev_j = (int)(cub->p.prev_y / 64);
	if ((prev_i < 0 && prev_i >= cub->row) || (prev_j < 0 \
		&& prev_j >= cub->col))
		return (0);
	if (cub->par.map[tmp_j][tmp_i] == '1')
		return (1);
	else if (cub->par.map[tmp_j][prev_i] == '1' && \
		cub->par.map[prev_j][tmp_i] == '1')
		return (2);
	return (0);
}

void	rand_wall(t_cub *cub, float ra)
{
	int	x;

	x = 0;
	while (x < cub->width)
	{
		if (ra > 2 * PI)
			ra -= 2 * PI;
		if (ra < 0)
			ra += 2 * PI;
		if (wall_checker(cub))
		{
			cub->p.x = cub->p.prev_x;
			cub->p.y = cub->p.prev_y;
		}
		hor_ray(cub, ra);
		ver_ray(cub, ra);
		shortest(&cub->p);
		v_field(cub, x, ra);
		x += 1;
		ra += ((PI / 3) / cub->width);
	}
}

void	frames_sprite(t_cub *cub)
{
	if (cub->sprite.ind < 5)
		mlx_put_image_to_window(cub->mlx, cub->win, \
			cub->sprite.farme_one, 350, 470);
	else if (cub->sprite.ind < 10)
		mlx_put_image_to_window(cub->mlx, cub->win, \
			cub->sprite.farme_two, 350, 470);
	else if (cub->sprite.ind < 15)
		mlx_put_image_to_window(cub->mlx, cub->win, \
			cub->sprite.farme_three, 350, 470);
	else if (cub->sprite.ind < 20)
		mlx_put_image_to_window(cub->mlx, cub->win, \
			cub->sprite.farme_four, 350, 470);
	else if (cub->sprite.ind < 25)
		mlx_put_image_to_window(cub->mlx, cub->win, \
			cub->sprite.farme_five, 350, 470);
}

int	mlx_windows(t_cub *cub)
{
	float	ra;

	ra = cub->p.p_angle - (PI / 6);
	ceilling_floor_max(cub);
	cub->p.mini_x = cub->p.x / (3.2);
	cub->p.mini_y = cub->p.y / (3.2);
	cub->p.i = (int)((cub->p.x - 32) / 64);
	cub->p.j = (int)((cub->p.y - 32) / 64);
	rand_wall(cub, ra);
	draw_minimap(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->mmap.img, 0, 0);
	if (cub->gun_shot == TRUE)
	{
		frames_sprite(cub);
		cub->sprite.ind++;
	}
	if (cub->sprite.ind >= 25)
		cub->gun_shot = FALSE;
	return (0);
}
