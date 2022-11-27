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
*	function that create a bisector
*/




/*
*	function that gives the shortest line to the wall
*/



// void	ft_minimap(t_cub *cub)
// {
// 	dplayer(cub);
// 	dda_line2((int)cub->p.x + 2, (int)cub->p.rx, (int)cub->p.y + 2, (int)cub->p.ry, cub);

	
// }

/*
*	function that we loop for every change
		^	draw background
		^	draw squares
		^	a loop for rays
			&	draw player
			&	check horizontale lines
			&	check vertical lines
			&	choose the shortest to the wall
			&	draw the shortest line
*/

int mlx_windows(t_cub *cub)
{
	cub->flag_x = 0;
	cub->flag_y = 0;
	// background(cub);
	// mlx
	ceilling_floor_max(cub);
	// draw_sqs(cub);
	// mini_dplayer(cub);
	// bisector(cub);
	// float height_line = 0.0;
	// cub->par.
	float ra = - PI / 6; // -30
	int x = 0;
	int tmp_i = 0;
	int tmp_j = 0;
	while (x < cub->width) // +30
	{
		// dplayer(cub);
		
		if (ra > 2 * PI)
			ra -= 2 * PI;
		if(ra < 0)
			ra += 2*PI;
		tmp_i = (int)(cub->p.x / 64);
		tmp_j = (int)(cub->p.y / 64);
		if (cub->par.map[tmp_j][tmp_i] == '1')
		{
			cub->p.x = cub->p.prev_x;
			cub->p.y = cub->p.prev_y;
		}
		hor_ray(cub, ra);
		ver_ray(cub, ra);
		shortest(&cub->p);
		v_field(cub, x, ra);
		// mini_draw_sqs(cub);
		// mini_dplayer(cub);
		// mini_bisector(cub);
		// dda_line2((int)cub->p.x, (int)cub->p.rx, (int)cub->p.y, (int)cub->p.ry, cub);
		x += 1;
		ra += ((PI / 3) / cub->width);
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
	return (0);
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
	else if (stop && cub->par.map[j - 1][i] == 'W')
		cub->p.p_angle = PI;
	else if (stop && cub->par.map[j - 1][i] == 'E')
		cub->p.p_angle = 0.0;
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

	cub.win_x = 1920;
	cub.win_y = 1080;
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
		cub.par = fill_struct(fd);
		int i = 0;
		cub.max_row = 0;
		// cub.len = 0;
		cub.win = mlx_new_window(cub.mlx, 640, 480, "CUB3D");
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
		cub.width = 640;
		cub.height = 480;
		cub.img = mlx_new_image(cub.mlx, cub.width, cub.height);
		if (!cub.img)
			printf("Failed!!\n");
		cub.addr = (int *)mlx_get_data_addr(cub.img, &cub.bits_per_pixel, &cub.line_length, &cub.endian);
		printf("%s\n", cub.par.text[1]);

		cub.tx_img.img = mlx_xpm_file_to_image(cub.mlx, cub.par.text[1], &cub.tx_img.width, &cub.tx_img.height);
		cub.tx_img.add = (int *)mlx_get_data_addr(cub.tx_img.img, &cub.bits_per_pixel, &cub.line_length, &cub.endian);
		init_player(&cub);
		init_texture(&cub);
		mlx_loop_hook(cub.mlx, mlx_windows, &cub);
		mlx_hook(cub.win, 2, (1L<<0), advance_keys, &cub);
		mlx_hook(cub.win, 17, 0, ft_close, &cub);
		mlx_loop(cub.mlx);
	}
	return 0;
}
