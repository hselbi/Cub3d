#include "cub3d.h"

void new_point(t_cub *cub)
{
	double new_x = 0;
	double new_y = 0;
	double block_y = 0;
	double block_x = 0;
	int x = 0;
	int y = 0;
	double next_x = 0;
	double next_y = 0;
	
	if (cub->p.p_angle > PI)
	{
		block_y = -64;
		new_y = ((int)cub->p.y / 64) * 64 - 0.0001;
	}
	else
	{
		block_y = 64; 
		new_y = ((int)cub->p.y / 64) * 64;
	}
	// printf("y = %d\n", y);
	// printf("new_y = %d\n", new_y);
	// printf("pos_p y = %d\n", (int)cub->p.y - new_y);
	// printf("pos_p x = %d\n", (int)cub->p.x);
	new_x = cub->p.x + ((cub->p.y - new_y)/-tanf(cub->p.p_angle));

	y = (int)new_y/64;
	x = (int)new_x/64;
	cub->degree = cub->p.p_angle * 180 / PI;
	block_x = -block_y/-tanf(cub->p.p_angle);
	// dda_line((int)cub->p.x, (int)cub->p.x + 10, (int)cub->p.y, (int)cub->p.y + 10, cub);
	printf("%f , %f\n", new_x, new_y);
	dda_line2((int)cub->p.x, new_x, (int)cub->p.y + 4, new_y, cub);
	while (((x > 0 && x < COL ) && (y > 0 && y < ROW)) && cub->map[y][x] != 1)
	{
		// printf("map[%d][%d] = %d\n", y, x, cub->map[y][x]);
		// printf("block_x = %d/block_y = %d\n", block_x, block_y);
		// printf("x ==> %dy ==> %d\n", x,÷ y);
		next_x = new_x + block_x;
		next_y = new_y + block_y;
		x = (int)next_x/64;
		y = (int)next_y/64;
	}
	// printf("%f , %f\n", new_x, new_y);
	dda_line2((int)cub->p.x, next_x, (int)cub->p.y + 4, next_y, cub);
}

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
	// int x = (int)cub->p.x;
	// int y = (int)cub->p.y;
	
	// while (x < 50)
	// {
	// 	cub->addr[(COL * 64) *  y +  x] = 0x00FF00;
	// 	x++;
	// }
	// x = (int)cub->p.x;
	// while (y < 50)
	// {
	// 	cub->addr[(COL * 64) *  y +  x] = 0x00FF00;
	// 	y++;
	// }
	// fprintf(stderr, "%d/%d\n", (make fint)cub->p.x, (int)(cub->p.x + cub->p.dem_x * 10));
	dda_line2((int)cub->p.x + 2, (int)(cub->p.x + cub->p.dem_x * 10), (int)cub->p.y + 2, (int)(cub->p.y + cub->p.dem_y * 10), cub);
}

int mlx_windows(t_cub *cub)
{
	cub->flag_x = 0;
	cub->flag_y = 0;
	draw_sqs(cub);
	draw_borders(cub);
	dplayer(cub);
	bisector(cub);
	// hor_ray(cub);
	// ver_ray(cub);
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
	// mlx_windows(&cub);
	// drawing_palyer(&cub);
	// my_mlx_pixel(&cub, cub.pos_x, cub.pos_y, 0xFFFFFF);
	// mlx_loop_hook(cub.mlx, sq_draw, &cub);
	init_player(&cub.p);
	mlx_loop_hook(cub.mlx, mlx_windows, &cub);
	mlx_key_hook(cub.win, advance_keys, &cub);
	// mlx_key_hook(cub.win, ft_keys, &cub);
	mlx_hook(cub.win, 17, 0, ft_close, &cub);
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