#include "cub3d.h"

void    dplayer(t_cub *cub)
{
    int x = -1;
    int y = 0;
	int	i = cub->p.x / 64;
	int	j = cub->p.y / 64;
	// printf(:)
	
	while (++x < 4)
	{
		y = -1;
		while (++y < 4)
		{
			if (cub->par.map[j][i] != '0' && !player_pos(cub->par.map[j][i]))
			{
				cub->p.x = cub->p.prev_x;
				cub->p.y = cub->p.prev_y;
			}
			cub->addr[(cub->width) * ((int)cub->p.y + y) + ((int)cub->p.x + x)] = 0x00FF00;
		}
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
	background(cub);
	draw_sqs(cub);
	// dplayer(cub);
	float ra = - PI / 12;
	// bisector(cub);
	
	while (ra < PI / 6)
	{
		dplayer(cub);
		hor_ray(cub, ra);
		ver_ray(cub, ra);
		shortest(&cub->p);
		dda_line2((int)cub->p.x + 2, (int)cub->p.rx, (int)cub->p.y + 2, (int)cub->p.ry, cub);	
		ra += PI / 180;
	}
	
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
	return (0);
}

int	check_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	else
		return (0);
}

void	init_player(t_cub *cub)
{
	int i = 0;
	int j = 0;
	int stop = 0;
	while ((j < cub->col) && cub->par.map[j] && !stop)
	{
		i = 0;
		while (i < cub->max_row && cub->par.map[j][i] && !stop)
		{
			if (check_player(cub->par.map[j][i]))
			{
				cub->p.x = i * 64 + (64 / 2);
				cub->p.y = j * 64 + (64 / 2);
				stop = 1;
				break;
			}
			i++;
		}
		j++;
	}
	cub->p.p_angle = 0.0;
	if (stop && cub->par.map[j - 1][i] == 'N')
		cub->p.p_angle = (3 * PI) / 2;
	else if (stop && cub->par.map[j - 1][i] == 'S')
		cub->p.p_angle = PI / 2;
	else if (stop && cub->par.map[j - 1][i] == 'E')
		cub->p.p_angle = PI;
	else if (stop && cub->par.map[j - 1][i] == 'W')
		cub->p.p_angle = 0.0;
	cub->p.dem_x = cos(cub->p.p_angle) * 5;
	cub->p.dem_y = sin(cub->p.p_angle) * 5;
}

/************	main	**********/

int main(int ac, char **av)
{
	t_cub cub;

	cub.win_x = 1024;
	cub.win_y = 512;
	cub.mid_x = 0;
	cub.mid_y = 0;
	cub.pos_x = 30;
	cub.pos_y = 30;
	cub.x = 300;
	cub.x = 456;
	cub.degree = 0.1;
	if (ac > 1)
	{
		cub.mlx = mlx_init();
		cub.relative_path = av[1];
		int fd = open_fd(av[1]);
		cub.par = fill_struct(fd);
		// print_infos(cub.par);
		// memcpy(cub.map, map, sizeof(int) * ROW * COL);
		int i = 0;
		cub.max_row = 0;
		// cub.len = 0;
		cub.win = mlx_new_window(cub.mlx, 1920, 1080, "CUB3D");
		if (!cub.win)
			printf("failed!!!\n");
		while (cub.par.map[i])
		{
			cub.len = (int)ft_strlen(cub.par.map[i]);
			// fprintf(stderr, "%d\n", cub.max_row);
			if (cub.max_row < cub.len)
				cub.max_row = cub.len;
			printf("%d -> %d ==> %s\n", i, cub.len, cub.par.map[i]);
			i++;
		}
		cub.col = i;
		// cub.win = mlx_new_window(cub.mlx, (int)(cub.col * 64 * 2.5), (int)(cub.max_row * 64 * 1.5), "CUB3D");
		cub.width = cub.max_row * 64 * 1.5;
		cub.height = cub.col * 64 * 2;
		cub.img = mlx_new_image(cub.mlx, cub.width, cub.height);

		if (!cub.img)
			printf("Failed!!\n");
		cub.addr = (int *)mlx_get_data_addr(cub.img, &cub.bits_per_pixel, &cub.line_length, &cub.endian);
		init_player(&cub);
		mlx_loop_hook(cub.mlx, mlx_windows, &cub);
		mlx_key_hook(cub.win, advance_keys, &cub);
		mlx_hook(cub.win, 17, 0, ft_close, &cub);
		mlx_loop(cub.mlx);
	}
	return 0;
}
