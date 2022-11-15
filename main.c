#include "cub3d.h"

void    dplayer(t_cub *cub)
{
    int x = -1;
    int y = 0;
	while (++x < 5)
	{
		y = -1;
		while (++y < 5)
			cub->addr[(COL * 64) * ((int)cub->p.y + y) + ((int)cub->p.x + x)] = 0x00FF00;
	}
}

void	bisector(t_cub *cub)
{
	dda_line2((int)cub->p.x + 2, (int)(cub->p.x + cub->p.dem_x * 10), (int)cub->p.y + 2, (int)(cub->p.y + cub->p.dem_y * 10), cub);
}

void	shortest(t_player *pl)
{
	float h = sqrt(pow((pl->x - pl->hx), 2.0) + pow((pl->y - pl->hy), 2.0));
	float v = sqrt(pow((pl->x - pl->vx), 2.0) + pow((pl->vy - pl->y), 2.0));
	if (v < h || pl->p_angle == 0.0)
	{
		pl->rx = pl->vx;
		pl->ry = pl->vy;
	}
	else if (v > h || pl->p_angle == (3 * PI) / 2)
	{
		pl->rx = pl->hx;
		pl->ry = pl->hy;
	}
}

int mlx_windows(t_cub *cub)
{
	cub->flag_x = 0;
	cub->flag_y = 0;
	draw_sqs(cub);
	float ra = 0.0;
	// bisector(cub);
	while (ra < PI / 6)
	{
		dplayer(cub);
		hor_ray(cub, ra);
		ver_ray(cub, ra);
		shortest(&cub->p);
		dda_line2((int)cub->p.x, (int)cub->p.rx, (int)cub->p.y, (int)cub->p.ry, cub);	
		ra += PI / 96;
	}
	
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
	return (0);
}

void	init_player(t_player *p)
{
	p->x = 300;
	p->y = 300;
	p->dem_x = cos(p->p_angle) * 5;
	p->dem_y = sin(p->p_angle) * 5;
}

/************	main	**********/

int main(int ac, char **av)
{
	t_cub cub;

	(void)ac;
	(void)av;
	int  map[ROW][COL] =  {
	{ 1 ,  1 ,  1 ,  1 ,  1 ,  1 ,  1 ,  1 ,  1 ,  1 ,  1 ,  1 ,  1 ,  1 ,  1 },
	{ 1 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  1 ,  0 ,  1 },
	{ 1 ,  0 ,  0 ,  0 ,  0 ,  1 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  1 ,  0 ,  1 },
	{ 1 ,  1 ,  1 ,  1 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  1 ,  0 ,  1 ,  0 ,  1 },
	{ 1 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  1 ,  0 ,  1 ,  0 ,  1 },
	{ 1 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  1 ,  1 ,  1 ,  1 ,  1 ,  0 ,  1 },
	{ 1 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  1 },
	{ 1 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  1 },
	{ 1 ,  1 ,  1 ,  1 ,  1 ,  1 ,  0 ,  0 ,  0 ,  1 ,  1 ,  1 ,  1 ,  0 ,  1 },
	{ 1 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  1 },
	{ 1 ,  1 ,  1 ,  1 ,  1 ,  1 ,  1 ,  1 ,  1 ,  1 ,  1 ,  1 ,  1 ,  1 ,  1 }
	};

	cub.win_x = 1024;
	cub.win_y = 512;
	cub.mid_x = 0;
	cub.mid_y = 0;
	cub.pos_x = 300;
	cub.pos_y = 300;
	cub.x = 300;
	cub.x = 456;
	cub.degree = 0.1;
	cub.relative_path = av[1];
	cub.mlx = mlx_init();
	cub.win = mlx_new_window(cub.mlx, COL * 64, ROW * 64, "CUB3D");
	memcpy(cub.map, map, sizeof(int) * ROW * COL);
	cub.img = mlx_new_image(cub.mlx, COL * 64, ROW * 64);
	if (!cub.img)
		printf("Failed!!\n");
	cub.addr = (int *)mlx_get_data_addr(cub.img, &cub.bits_per_pixel, &cub.line_length, &cub.endian);
	init_player(&cub.p);
	mlx_loop_hook(cub.mlx, mlx_windows, &cub);
	mlx_key_hook(cub.win, advance_keys, &cub);
	mlx_hook(cub.win, 17, 0, ft_close, &cub);
	mlx_loop(cub.mlx);
	return 0;
}
