#include "../cub3d.h"

int	check_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	else
		return (0);
}

void	player_side(t_cub *cub, int stop, int i, int j)
{
	if (stop && cub->par.map[j - 1][i] == 'N')
	{
		cub->p.p_angle = (3 * PI) / 2;
		cub->side = 'N';
	}
	else if (stop && cub->par.map[j - 1][i] == 'S')
	{
		cub->side = 'S';
		cub->p.p_angle = PI / 2;
	}
	else if (stop && cub->par.map[j - 1][i] == 'W')
	{
		cub->side = 'W';
		cub->p.p_angle = PI;
	}
	else if (stop && cub->par.map[j - 1][i] == 'E')
	{
		cub->side = 'E';
		cub->p.p_angle = 0.0;
	}
	cub->p.dem_x = cos(cub->p.p_angle) * 5;
	cub->p.dem_y = sin(cub->p.p_angle) * 5;
	cub->p.dist_plan = 277;
}

void	init_player(t_cub *cub)
{
	int	i;
	int	j;
	int	stop;

	i = -1;
	j = -1;
	stop = 0;
	while ((++j < cub->col) && cub->par.map[j] && !stop)
	{
		i = -1;
		while (++i < cub->row && cub->par.map[j][i] && !stop)
		{
			if (check_player(cub->par.map[j][i]))
			{
				cub->p.x = i * 64 + (64 / 2);
				cub->p.y = j * 64 + (64 / 2);
				stop = 1;
				break ;
			}
		}
	}
	cub->p.mini_x = (cub->p.x / (16 / 5));
	cub->p.mini_y = (cub->p.y / (16 / 5));
	cub->p.prev_x = cub->p.x;
	cub->p.prev_y = cub->p.y;
	cub->p.p_angle = (3 * PI) / 2;
	player_side(cub, stop, i, j);
}

void	init_img_win(t_cub *cub)
{
	int	i;

	i = 0;
	cub->row = 0;
	while (cub->par.map[i])
	{
		cub->len = (int)ft_strlen(cub->par.map[i]);
		if (cub->row < cub->len)
			cub->row = cub->len;
		i++;
	}
	cub->col = i;
	cub->width = cub->win_x;
	cub->height = cub->win_y;
	cub->img = mlx_new_image(cub->mlx, cub->width, cub->height);
	if (!cub->img)
		printf("Failed!!\n");
	cub->addr = (int *)mlx_get_data_addr(cub->img, &cub->bits_per_pixel, \
		&cub->line_length, &cub->endian);
	if (!cub->addr)
		printf("Failed!!\n");
	cub->mmap.img = mlx_new_image(cub->mlx, cub->mini_w, cub->mini_h);
	cub->mmap.add = (int *)mlx_get_data_addr(cub->mmap.img, \
		&cub->bits_per_pixel, &cub->line_length, &cub->endian);
	cub->sprite.farme_one = mlx_xpm_file_to_image(cub->mlx, "./gun_shot/1.xpm", &cub->sprite.width_one, &cub->sprite.height_one);
	cub->sprite.farme_two = mlx_xpm_file_to_image(cub->mlx, "./gun_shot/4.xpm", &cub->sprite.width_two, &cub->sprite.height_two);
	cub->sprite.farme_three = mlx_xpm_file_to_image(cub->mlx, "./gun_shot/3.xpm", &cub->sprite.width_three, &cub->sprite.height_three);
	cub->sprite.farme_four = mlx_xpm_file_to_image(cub->mlx, "./gun_shot/2.xpm", &cub->sprite.width_four, &cub->sprite.height_four);
}


// int mouse_hook(int button, int x, int y, t_cub *cub)
// {
// 	// static int	old_x;

// 	(void)cub;
// 	(void)y;
// 	(void)x;
// 	printf("%d\n", button);
// 	// if (old_x - x < 0)
// 	// {
// 	// 	cub->p.p_angle += 0.1;
// 	// 	if (cub->p.p_angle > 2 * PI)
// 	// 		cub->p.p_angle -= 2 * PI;
// 	// 	cub->p.dem_x = cos(cub->p.p_angle) * 5;
// 	// 	cub->p.dem_y = sin(cub->p.p_angle) * 5;
// 	// }
// 	// else if (old_x - x > 0)
// 	// {
// 	// 	cub->p.p_angle -= 0.1;
// 	// 	if (cub->p.p_angle < 0)
// 	// 		cub->p.p_angle += 2 * PI;
// 	// 	cub->p.dem_x = cos(cub->p.p_angle) * 5;
// 	// 	cub->p.dem_y = sin(cub->p.p_angle) * 5;
// 	// }
// 	// old_x = x;
// 	return (0);
// }

int	main(int ac, char **av)
{
	t_cub	cub;
	int		fd;

	cub.win_x = 960;
	cub.win_y = 720;
	cub.mini_h = 180;
	cub.mini_w = 180;
	if (ac > 1)
	{
		cub.mlx = mlx_init();
		fd = open_fd(av[1]);
		cub.par = fill_struct(fd);
		cub.win = mlx_new_window(cub.mlx, cub.win_x, cub.win_y, "CUB3D");
		if (!cub.win)
			printf("failed!!!\n");
		init_img_win(&cub);
		mlx_mouse_get_pos(cub.win, &cub.mouse_x, &cub.mouse_y);
		init_player(&cub);
		init_texture(&cub);
		mlx_loop_hook(cub.mlx, mlx_windows, &cub);
		mlx_mouse_hide();
		// mlx_mouse_hook(cub.win, mouse_hook, &cub);
		mlx_hook(cub.win, 6, 0, func, &cub);
		mlx_hook(cub.win, 2, 0, advance_keys, &cub);
		mlx_hook(cub.win, 17, 0, ft_close, &cub);
		mlx_loop(cub.mlx);
	}
	return (0);
}
