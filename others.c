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
		// printf("angle => %lf\n", angle);
		draw_dir_ray(cub, angle);
		draw_dir_ray(cub, -angle);
		angle += PI / 976;
	}
}

void	check_if(t_cub *cub)
{
	if (cub->degree > PI)
	{
		cub->up_y = 0;
		cub->down_y = 1;
	}
	else 
	{
		cub->up_y = 1;
		cub->down_y = 0;
	}
}

// int	check(int x, int y, t_cub *cub)
// {
// 	if ()
// }

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

void	direct_line(t_cub *cub)
{
	double x = cub->p.x;
	double y = cub->p.y;
	while (x < cub->p.x + cub->p.dem_x * 5)
	{
		y = cub->p.y;
		while (y < cub->p.y + cub->p.dem_y * 5)
		{
			cub->addr[(COL * 64) * (int)y + (int)x] = 0x00FF00;
			y += cub->p.dem_y;
		}
		
		x += cub->p.dem_x;
	}
	
}

int sq_draw(t_cub *cub)
{
	draw_sqs(cub);
	draw_borders(cub);
	draw_ray(cub);
	draw_player(cub);
	// direct_line(cub);
	// dda_line(cub->p.x, cub->p.x + cub->p.dem_x * 5, cub->p.y, cub->p.y + cub->p.dem_y * 5, cub);
	// fprintf(stderr, "==> %p\n", cub->mlx);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
	return (0);
}