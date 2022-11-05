#include "cub3d.h"

void draw_ver(t_cub *cub, int x, int y)
{
	int i = x;
	int j = 0;
	if (cub->flag_x)
		return;
	if (!(x % 2) && x != 8)
	{
		printf("==> %d\n", x);
		draw_ver(cub, x / 2, y);
	}
	else
	{
		while (j < cub->win_y)
		{
			i = x * 8;
			while (i < cub->win_x)
			{
				my_mlx_pixel(cub, i, j, 16304479);
				i += (x * 8);
			}
			j++;
		}

		cub->flag_x = 1;
	}
}

void draw_hori(t_cub *cub, int x, int y)
{
	int i = 0;
	int j = y;
	if (cub->flag_y)
		return;
	if (!(y % 2) && y != 8)
	{
		draw_hori(cub, x, y / 2);
	}
	else
	{
		while (i < cub->win_x)
		{
			j = y * 8;
			while (j < cub->win_y)
			{
				my_mlx_pixel(cub, i, j, 16304479);
				j += y * 8;
			}
			i++;
		}
		cub->flag_y = 1;
	}
}

void drawing_palyer(t_cub *cub)
{
	int mid_x = cub->mid_x + cub->win_x / 2;
	int mid_y = cub->mid_y + cub->win_y / 2;

	cub->pos_x = mid_x - 4;
	int end_x = mid_x + 4;
	cub->pos_y = mid_y - 4;
	int end_y = mid_y + 4;

	while (cub->pos_x <= end_x)
	{
		cub->pos_y = mid_y - 4;
		while (cub->pos_y <= end_y)
		{
			if (end_y >= cub->win_y)
				my_mlx_pixel(cub, cub->pos_x, cub->win_y, 0xFFFFFF);
			else if (end_x >= cub->win_x)
				my_mlx_pixel(cub, cub->win_x, cub->pos_y, 0xFFFFFF);
			else if (end_x >= cub->win_x && end_y >= cub->win_y)
				my_mlx_pixel(cub, cub->win_x, cub->win_y, 0xFFFFFF);
			else if (end_x <= 0)
				my_mlx_pixel(cub, 0, cub->pos_y, 0xFFFFFF);
			else if (end_y <= 0)
				my_mlx_pixel(cub, cub->pos_x, 0, 0xFFFFFF);
			else if (end_y <= 0 && end_x <= 0)
				my_mlx_pixel(cub, 0, 0, 0xFFFFFF);
			else
				my_mlx_pixel(cub, cub->pos_x, cub->pos_y, 0xFFFFFF);
			cub->pos_y++;
		}
		cub->pos_x++;
	}
}

void angle_fov(t_cub *cub)
{
	int x = 0;
	int y = 0;
	// float ray_angle = 0.0;
	float x_rotated = 0.0;
	float y_rotated = 0.0;
	while (x < 100)
	{
		x_rotated = ((x - cub->pos_x) * cos(acos(FOV))) - ((cub->pos_y - y) * sin(asin(FOV))) + cub->pos_x;
		printf("x = %lf\n", x_rotated);
		y = 0;
		while (y < 100)
		{
			y_rotated = cub->pos_y + ((cub->pos_y - y) * cos(acos(FOV))) + ((x - cub->pos_x) * sin(asin(FOV)));
			printf("y = %lf\n", y_rotated);
			my_mlx_pixel(cub, x_rotated, y_rotated, 0xEC7063);
			y++;
		}
		x++;
	}
}


// void    line_player(t_cub *cub)
// {
//     int x = cub->pos_x - 4;
//     int y = cub->pos_y - 5;
//     while (++x < cub->pos_x + 100)
//         my_mlx_pixel(cub, x, y, 0xEC7063);

// }

void fov_angle(t_cub *cub)
{
	int new_x;
	int new_y;

	cub->degree = FOV * 180 / PI;
	printf("degree %f\n", cub->degree);
	new_x = (cub->pos_x - 4) * cos((double)cub->degree) - (cub->pos_y - 5) * sin((double)cub->degree);
	new_y = (cub->pos_x - 4) * sin((double)cub->degree) + (cub->pos_y - 5) * cos((double)cub->degree);
	int x_rotated = ((new_x - 0) * cos((double)cub->degree)) - ((0 - new_y) * sin((double)cub->degree)) + 0;
	int y_rotated = 0 - ((0 - new_y) * cos((double)cub->degree)) + ((new_x - 0) * sin((double)cub->degree));
	printf("this new x, y (%d, %d)\n", x_rotated, y_rotated);
	printf("difference in x, %d\n", cub->pos_x - x_rotated);
	printf("difference in y, %d\n", cub->pos_y - y_rotated);
	dda_line(cub->pos_x, x_rotated, cub->pos_y, y_rotated, cub);
}

void maps_barriers(t_cub *cub)
{
	int nor = 10;
	int sou = cub->win_y - 10;
	int eas = cub->win_x - 10;
	int wes = 10;
	// draw lest line
	int i = nor - 1;
	while (++i < sou)
		my_mlx_pixel(cub, wes, i, 0xE10606);
	// draw buttom line
	i = wes - 1;
	while (++i < eas)
		my_mlx_pixel(cub, i, sou, 0xE10606);
	// draw right line
	i = sou + 1;
	while (--i > nor)
		my_mlx_pixel(cub, eas, i, 0xE10606);
	// draw top line
	i = eas + 1;
	while (--i > wes)
		my_mlx_pixel(cub, i, nor, 0xE10606);
}

void	draw_dir_ray(t_cub *cub, double angle)
{
	double	ray_x;
	double	ray_y;
	double	dx = 0.0;
	double	dy = 0.0;
	double	max_vulue;

	ray_x = cub->pos_x;
	ray_y = cub->pos_y;

	dx = cos(angle) * cub->x - sin(angle) * cub->y;
	// printf("dx => %lf\n", dx);
	dy = sin(angle) * cub->x + cos(angle) * cub->y;
	// printf("dy => %lf\n", dy);
	max_vulue = fmax(fabs(dx), fabs(dy));
	dx /= max_vulue;
	dy /= max_vulue;
	// printf("4 ==> %d\n", cub->addr[(COL * 64) *  ( int )floor(ray_y) +  ( int )floor(ray_x)]);
	while (1)
	{
			// my_mlx_pixel(cub, (int)floor(ray_x), (int)floor(ray_y), 0xFFFFFF);
		// printf("==>%d/%d\n", cub->line_length, cub->bits_per_pixel);
		if  (cub->addr[(COL * 64) * (int)floor(ray_y) + (int)floor(ray_x)] != 16304479)
            cub->addr[(COL * 64) *  ( int )floor(ray_y) +  ( int )floor(ray_x)] =  0xFFFFFF;
        else
            break ;
		ray_x += dx;
		ray_y += dy;
	}
	
}

/************	keys check	**********/

void	draw_ray(t_cub *cub)
{
	double angle = 0.0;

	while (angle < PI / 6)
	{
		draw_dir_ray(cub, angle);
		draw_dir_ray(cub, -angle);
		angle += PI / 976;
	}
	// mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
}

void new_point(t_cub *cub)
{
	int new_x = 0;
	int new_y = 0;
	int block_y = 0;
	int block_x = 0;
	int x = 0;
	int y;
	int next_x;
	int next_y;

	// check_if(cub);
	// 136 is difference between y0 and y1
	if (cub->up_y)
	{
		block_y = -135; 
		new_y = floor(cub->pos_y / 135) * 135 - 1;
	}
	else if (cub->down_y)
	{
		block_y = 135; 
		new_y = floor(cub->pos_y / 135) * 135;
	}
	// if u want to check which block is this new_y
	// u can easily do new_y/135 which will give us the y_block
	y = new_y/135;
	new_x = cub->pos_x + (cub->pos_y - new_y) / tan(cub->degree);
	x = new_x/135;
	printf("==> init block(%d, %d)\n", x, y);
	// the same thing for x if u want to check the block of new_x
	printf("==> new (%d, %d)\n", new_x, new_y);
	block_x = 135/tan(cub->degree);
	while (x && y)
	{
		next_x = new_x + block_x;
		next_y = new_y + block_y;
		x = next_x/136;
		y = next_y/136;
	}
	printf("==> next(%d, %d)\n", next_x, next_y);
	printf("==> final block(%d, %d)\n", x, y);
	printf("==> next(%d, %d)\n", next_x, next_y);
}

void drawing(t_cub *cub)
{
	draw_ver(cub, cub->win_x, 0);
	draw_hori(cub, 0, cub->win_y);
	// drawing_palyer(cub);
	// dda_line(cub->pos_x, cub->pos_x + 116, cub->pos_y, cub->pos_y - 116, cub);
	cub->up_y = 1;
	cub->down_y = 0;
	// fov_angle(cub);
	// new_point(cub);
	// line_player(cub);
	// line_player(cub);
	// printf("player position is P(%d, %d)\n", cub->pos_x, cub->pos_y);
	// maps_barriers(cub);
	// angle_fov(cub);
}
/*
void mlx_windows(t_cub *cub)
{
	cub->img = mlx_new_image(cub->mlx, cub->win_x, cub->win_y);
	cub->addr = ()mlx_get_data_addr(cub->img, &cub->bits_per_pixel, &cub->line_length, &cub->endian);
	cub->flag_x = 0;
	cub->flag_y = 0;
	drawing(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
}
*/

void	draw_player(t_cub *cub)
{
	int x = cub->pos_x - 2;
	int y = cub->pos_y - 2;
	while (y < cub->pos_y + 2)
	{
		x = cub->pos_x - 2;
		while (x < cub->pos_x + 2)
		{
			pix_mlx(cub, x, y, 0x00FF00);
			x++;
		}
		y++;
	}
}

int sq_draw(t_cub *cub)
{
	draw_sqs(cub);
	draw_borders(cub);
	draw_ray(cub);
	draw_player(cub);
	// fprintf(stderr, "==> %p\n", cub->mlx);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
	return (0);
}

// void	draw_rays_3d()

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
	cub.pos_y = 456;
	cub.x = 300;
	cub.x = 456;
	cub.degree = 0.1;
	cub.relative_path = av[1];
	cub.mlx = mlx_init();
	cub.win = mlx_new_window(cub.mlx, COL * 64, ROW * 64, "CUB3D");
	memcpy(cub.map, map, sizeof(int) * ROW * COL);
	cub.img = mlx_new_image(cub.mlx, COL * 64, ROW * 64);
	cub.addr = (int *)mlx_get_data_addr(cub.img, &cub.bits_per_pixel, &cub.line_length, &cub.endian);
	// cub.img = mlx_new_image(cub.mlx, cub.win_x, cub.win_y);
	// cub.img = mlx_xpm_file_to_image(cub.mlx, cub.relative_path, &cub.win_x, &cub.win_y);
	if (!cub.img)
		printf("Failed!!\n");
	// mlx_windows(&cub);
	mlx_key_hook(cub.win, ft_keys, &cub);
	mlx_hook(cub.win, 17, 0, ft_close, &cub);
	// drawing_palyer(&cub);
	// my_mlx_pixel(&cub, cub.pos_x, cub.pos_y, 0xFFFFFF);
	mlx_loop_hook(cub.mlx, sq_draw, &cub);
	fprintf(stderr, "@@@%p\n", cub.mlx);
	mlx_loop(cub.mlx);
	return 0;
}



/*

void     draw_dir_ray(t_game * game,  double  angle)
{
    double     ray_x;
    double     ray_y;
    double     dx;
    double     dy;
    double     max_value;
 
    ray_x =  game-> pos.x;
    ray_y =  game-> pos.y;
 
    dx =  cos(angle) *  game-> dir_vec.x -  sin(angle) *  game-> dir_vec.y;
    dy =  sin(angle) *  game-> dir_vec.x +  cos(angle) *  game-> dir_vec.y;
 
    max_value =  fmax(fabs(dx), fabs(dy));
    dx /=  max_value;
    dy /=  max_value;
    while  ( 1 )
    {
        if  (game-> map_img.data[WIDTH *  ( int )floor(ray_y) +  ( int )floor(ray_x)] !=  0x0000FF )
            game-> map_img.data[WIDTH *  ( int )floor(ray_y) +  ( int )floor(ray_x)] =  0xFF0000 ;
        else
            break ;
        ray_x +=  dx;
        ray_y +=  dy;
    }
}
 
void     draw_ray(t_game * game)
{
    double  angle;
 
    angle =  0 ;
    while  (angle <  PI/ 6 )
    {
        draw_dir_ray(game, angle);
        draw_dir_ray(game, - angle);
        angle +=  PI/ 72 ;
    }
    mlx_put_image_to_window(game-> mlx, game-> win, game-> map_img.img,  0 ,  0 );
}

*/