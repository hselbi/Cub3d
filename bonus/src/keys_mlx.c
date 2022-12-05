#include "../cub3d.h"

int	ft_close(t_cub *cub)
{
	if (!mlx_destroy_window(cub->mlx, cub->win))
		exit(0);
	return (0);
}

void	mv_fb(t_cub *cub, int key)
{
	if (key == W)
	{
		cub->p.prev_x = cub->p.x;
		cub->p.prev_y = cub->p.y;
		if (cub->p.p_angle == 0.0)
			cub->p.y -= 5;
		else
		{
			cub->p.x += cub->p.dem_x;
			cub->p.y += cub->p.dem_y;
		}
	}
	else if (key == S)
	{
		cub->p.prev_x = cub->p.x;
		cub->p.prev_y = cub->p.y;
		if (cub->p.p_angle == 0.0)
			cub->p.y += 5;
		else
		{
			cub->p.x -= cub->p.dem_x;
			cub->p.y -= cub->p.dem_y;
		}
	}
}

void	mv_rl(t_cub *cub, int key)
{
	if (key == D)
	{
		cub->p.prev_x = cub->p.x;
		cub->p.prev_y = cub->p.y;
		cub->p.dm_x = cos(cub->p.p_angle + PI / 2) * 5;
		cub->p.dm_y = sin(cub->p.p_angle + PI / 2) * 5;
		cub->p.x += cub->p.dm_x;
		cub->p.y += cub->p.dm_y;
	}
	else if (key == A)
	{
		cub->p.prev_x = cub->p.x;
		cub->p.prev_y = cub->p.y;
		cub->p.dm_x = cos(cub->p.p_angle + PI / 2) * 5;
		cub->p.dm_y = sin(cub->p.p_angle + PI / 2) * 5;
		cub->p.x -= cub->p.dm_x;
		cub->p.y -= cub->p.dm_y;
	}
}

void	frames(t_cub *cub)
{
	void	*img;
	int		width_img;
	int		height_img;
	int i = 0;
	img = mlx_xpm_file_to_image(cub->mlx, "./gun_shot/1.xpm", &width_img, &height_img);
	printf("%d, %d\n", cub->sprite.width_two, cub->win_x);
	// printf("%d, %d\n", cub->sprite.height_two, cub->win_y);
	// mlx_put_image_to_window(cub->mlx, cub->win, cub->sprite.farme_one, 305, 520);
	// mlx_destroy_image(cub->mlx, cub->sprite.farme_one);
	while (i < 800)
	{
		printf("%d\n", i);
		if (i >= 0 && i < 100)
		{
			usleep(100);
			mlx_put_image_to_window(cub->mlx, cub->win, cub->sprite.farme_one, 305, 520);
		}
		else if (i >= 200 && i < 300)
		{
			usleep(100);
			mlx_put_image_to_window(cub->mlx, cub->win, cub->sprite.farme_two, 345, 485);
		}
		else if (i >= 400 && i < 500)
		{
			usleep(100);
			mlx_put_image_to_window(cub->mlx, cub->win, cub->sprite.farme_three, 340, 410);
		}
		else if (i >= 600 && i < 700)
		{
			usleep(100);
			mlx_put_image_to_window(cub->mlx, cub->win, cub->sprite.farme_four, 345, 430);
		}
		i++;
	}
	// mlx_destroy_image(cub->mlx, cub->sprite.farme_two);
	// mlx_destroy_image(cub->mlx, cub->sprite.farme_three);
	// mlx_destroy_image(cub->mlx, cub->sprite.farme_four);
}

int	advance_keys(int key, t_cub *cub)
{
	if (key == SPACE)
		frames(cub);
	if (key == ESC)
		ft_close(cub);
	mv_fb(cub, key);
	mv_rl(cub, key);
	if (key == RIGHT)
	{
		cub->p.p_angle -= 0.1;
		if (cub->p.p_angle < 0)
			cub->p.p_angle += 2 * PI;
		cub->p.dem_x = cos(cub->p.p_angle) * 5;
		cub->p.dem_y = sin(cub->p.p_angle) * 5;
	}
	if (key == LEFT)
	{
		cub->p.p_angle += 0.1;
		if (cub->p.p_angle > 2 * PI)
			cub->p.p_angle -= 2 * PI;
		cub->p.dem_x = cos(cub->p.p_angle) * 5;
		cub->p.dem_y = sin(cub->p.p_angle) * 5;
	}
	return (0);
}
