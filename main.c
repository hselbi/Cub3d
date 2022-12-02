#include "cub3d.h"

/*
*	function that draw a player in exist map
*/

void    dplayer(t_cub *cub)
{
    int x = -1;
    int y = 0;
	int	i = cub->p.x / 64;
	int	j = cub->p.y / 64;

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

/*
*	check player if it's exist or not
*/

int	check_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	else
		return (0);
}

/*
*	function that initiale the values of every data for a player
		^ position of player
		^ angle of player
		^ demension that change everytime 
*/

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
				cub->p.i = i;
				cub->p.j = j;
				cub->p.x = i * 64 + (64 / 2);
				cub->p.y = j * 64 + (64 / 2);
				stop = 1;
				break;
			}
			i++;
		}
		j++;
	}
	cub->p.mini_x = (cub->p.x / (16/5));
	cub->p.mini_y = (cub->p.y / (16/5));
	cub->p.p_angle = (3 * PI) / 2;
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

/*
*	main function that
	^ calculate the column and the row for the map
	^ create a window that is multiply by 64 * x(1.5 or 2)
	^ create an image for the drawing
	^ initial the player infos
	^ make a loop for every change
*/

int main(int ac, char **av)
{
	t_cub cub;

	cub.win_x = 960;
	cub.win_y = 720;
	cub.mini_h = 180;
	cub.mini_w = 180;
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
		int fd = open_fd(av[1]);
		// cub.file_out = open("angles.txt", O_CREAT | O_WRONLY | O_APPEND , 0777);
		cub.file_out = fopen("file.txt", "w+");
		cub.par = fill_struct(fd);
		int i = 0;
		cub.max_row = 0;
		// cub.len = 0;
		cub.win = mlx_new_window(cub.mlx, cub.win_x, cub.win_y, "CUB3D");
		if (!cub.win)
			printf("failed!!!\n");
		while (cub.par.map[i])
		{
			cub.len = (int)ft_strlen(cub.par.map[i]);
			if (cub.max_row < cub.len)
				cub.max_row = cub.len;
			i++;
		}
		cub.col = i;
		cub.width = cub.win_x;
		cub.height = cub.win_y;
		
		cub.img = mlx_new_image(cub.mlx, cub.width, cub.height);
		if (!cub.img)
			printf("Failed!!\n");
		cub.addr = (int *)mlx_get_data_addr(cub.img, &cub.bits_per_pixel, &cub.line_length, &cub.endian);
		if (!cub.addr)
			printf("Failed!!\n");
		cub.mmap.img = mlx_new_image(cub.mlx, cub.mini_w, cub.mini_h);
		cub.mmap.add = (int *)mlx_get_data_addr(cub.mmap.img, &cub.bits_per_pixel, &cub.line_length, &cub.endian);
		// i = 0;
		// int j = 0;
		// while(i < 64)
		// {
		// 	j = 0;
		// 	while (j < 64)
		// 	{
		// 		// printf("%d>>>>>>> %d\n", j, my_get_color(&img.txt, j, i));
		// 		cub.mmap.add[200 * i + j] = 0x00FF00;
		// 		// my_mlx_pixel_put(&img, j, i, my_get_color(&img.txt, j, i));
		// 		j++;
		// 	}
		// 	i++;
		// }
		// i = 0;
		// j = 0;
		// while(i < cub.height)
		// {
		// 	j = 0;
		// 	while (j < cub.width)
		// 	{
		// 		// printf("%d>>>>>>> %d\n", j, my_get_color(&img.txt, j, i));
		// 		cub.addr[cub.width * i + j] = 0xA2FF00;
		// 		// my_mlx_pixel_put(&img, j, i, my_get_color(&img.txt, j, i));
		// 		j++;
		// 	}
		// 	i++;
		// }
		mlx_mouse_get_pos(cub.win, &cub.mouse_x, &cub.mouse_y);
		init_player(&cub);
		init_texture(&cub);
		mlx_loop_hook(cub.mlx, mlx_windows, &cub);
		mlx_mouse_hide();
		mlx_hook(cub.win, 6, 0, func, &cub);
		mlx_hook(cub.win, 2, 0, advance_keys, &cub);
		mlx_hook(cub.win, 17, 0, ft_close, &cub);
		printf("test\n");
		printf("test\n");
		mlx_loop(cub.mlx);
	}
	return 0;
}
