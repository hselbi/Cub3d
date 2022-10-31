#include "cub3d.h"


void	my_mlx_pixel(t_cub *data, int x, int y, int color)
{
	char	*dst;
    // printf("@@@ %d\n", x * (data->bits_per_pixel / 8));
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void    draw_ver(t_cub *cub, int x, int y)
{
    int i = x;
    int j = 0;
    if (cub->flag_x)
        return ;
    if (!(x % 2))
    {
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

void    draw_hori(t_cub *cub, int x, int y)
{
    int i = 0;
    int j = y;
    if (cub->flag_y)
        return ;
    if (!(y % 2))
    {
        draw_hori(cub, x, y / 2);
    }
    else
    {
        while (i < cub->win_x)
        {
            j = y;
            while (j < cub->win_y)
            {
                my_mlx_pixel(cub, i, j, 16304479);
                j += y;
            }
            i++;
        }
        cub->flag_y = 1;
    }
}

void    drawing_palyer(t_cub *cub)
{
    int mid_x = cub->mid_x + cub->win_x / 2;
    int mid_y = cub->mid_y + cub->win_y / 2;

    cub->pos_x = mid_x - 4;
    int end_x =  mid_x + 4;
    cub->pos_y = mid_y - 4;
    int end_y = mid_y + 4;
    
        
    while (cub->pos_x <= end_x)
    {
        cub->pos_y = mid_y - 4;
        while (cub->pos_y <= end_y)
        {
            if (end_y >= cub->win_y)
                my_mlx_pixel(cub, cub->pos_x, cub->win_y, 0xEC7063);
            else if (end_x >= cub->win_x)
                my_mlx_pixel(cub, cub->win_x, cub->pos_y, 0xEC7063);
            else if (end_x >= cub->win_x && end_y >= cub->win_y)
                my_mlx_pixel(cub, cub->win_x, cub->win_y, 0xEC7063);
            else if (end_x <= 0)
                my_mlx_pixel(cub, 0, cub->pos_y, 0xEC7063);
            else if (end_y <= 0)
                my_mlx_pixel(cub, cub->pos_x, 0, 0xEC7063);
            else if (end_y <= 0 && end_x <= 0)
                my_mlx_pixel(cub, 0, 0, 0xEC7063);
            else
                my_mlx_pixel(cub, cub->pos_x, cub->pos_y, 0xEC7063);
            cub->pos_y++;
        }
        cub->pos_x++;
    }   
}

void    angle_fov(t_cub *cub)
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
            my_mlx_pixel(cub, x_rotated, y_rotated , 0xEC7063);
            y++;
        }
        x++;
    }
}

void    dda_line(int start_x, int end_x, int start_y, int end_y, t_cub *cub)
{
    int dx = end_x - start_x;
    int dy = end_y - start_y;
    int step = 0;
    int x = start_x;
    int y = start_y;
    int i = 0;
    if (start_x != end_x && start_y != end_y)
    {
        if (dx >= dy)
            step = dx;
        else
            step = dy;
        dx = dx/step;
        dy = dy/step;
        while (i < step)
        {
            my_mlx_pixel(cub, x, y, 0xEC7063);
            x += dx;
            y += dy;
            i++;
        }
    }
}

// void    line_player(t_cub *cub)
// {
//     int x = cub->pos_x - 4;
//     int y = cub->pos_y - 5;
//     while (++x < cub->pos_x + 100)
//         my_mlx_pixel(cub, x, y, 0xEC7063);
    
// }

void    fov_angle(t_cub *cub)
{
    int new_x;
    int new_y;

    int degree = FOV * 180 / PI;
    printf("degree %d\n", degree);
    new_x = (cub->pos_x - 4) * cos((double)degree) - (cub->pos_y - 5)* sin((double)degree);
    new_y = (cub->pos_x - 4) * sin((double)degree) + (cub->pos_y - 5) * cos((double)degree);
    int x_rotated = ((new_x - 0) * cos((double)degree)) - ((0 - new_y) * sin((double)degree)) + 0;
    int y_rotated = 0 - ((0 - new_y) * cos((double)degree)) + ((new_x - 0) * sin((double)degree));
    printf("this new x, y (%d, %d)\n", x_rotated, y_rotated);
    printf("difference in x, %d\n", cub->pos_x - x_rotated);
    printf("difference in y, %d\n", cub->pos_y - y_rotated);
    dda_line(cub->pos_x, x_rotated, cub->pos_y, y_rotated, cub);
}

void    maps_barriers(t_cub *cub)
{
    int nor = 10;
    int sou = cub->win_y - 10;
    int eas = cub->win_x - 10;
    int wes = 10;
    //draw lest line
    int i = nor - 1;
    while (++i < sou)
        my_mlx_pixel(cub, wes, i, 0xE10606);
    //draw buttom line
    i = wes - 1;
    while (++i < eas)
        my_mlx_pixel(cub, i, sou, 0xE10606);
    //draw right line
    i = sou + 1;
    while (--i > nor)
        my_mlx_pixel(cub, eas, i, 0xE10606);
     //draw top line
    i = eas + 1;
    while (--i > wes)
        my_mlx_pixel(cub, i, nor, 0xE10606);
}

void    drawing(t_cub *cub)
{
    draw_ver(cub, cub->win_x, 0);
    draw_hori(cub, 0, cub->win_y);
    drawing_palyer(cub);
    dda_line(cub->pos_x, cub->pos_x + 100, cub->pos_y, cub->pos_y + 100, cub);
    fov_angle(cub);
    // line_player(cub);
    // line_player(cub);
    printf("player position is P(%d, %d)\n", cub->pos_x, cub->pos_y);
    maps_barriers(cub);
    // angle_fov(cub);
}

void    mlx_windows(t_cub *cub)
{
    cub->img = mlx_new_image(cub->mlx, cub->win_x, cub->win_y);
    cub->addr = mlx_get_data_addr(cub->img, &cub->bits_per_pixel, &cub->line_length, &cub->endian);
    cub->flag_x = 0;
    cub->flag_y = 0;
    drawing(cub);
    mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
}

/*
! crose closing function
*/

int	ft_close(t_cub *cub)
{
	mlx_destroy_window(cub->mlx, cub->win);
	exit(0);
	return (0);
}

/*
! keys function
*/

int	ft_keys(int key, t_cub *cub)
{
	if (key == ESC)
		ft_close(cub);
	else if (key == W)
	{
        cub->mid_y -= 10;
	}
	else if (key == S)
	{
		cub->mid_y += 10;
	}
	else if (key == A)
	{
        cub->mid_x -= 10;
	}
	else if (key == D)
	{
        cub->mid_x += 10;
	}
    mlx_windows(cub);
	return (0);
}



int main(void)
{
    t_cub   cub;

    cub.win_x = 1920;
    cub.win_y = 1080;
    cub.mid_x = 0;
    cub.mid_y = 0;
    cub.mlx = mlx_init();
    cub.win = mlx_new_window(cub.mlx, cub.win_x, cub.win_y, "CUB3D");
    cub.img = mlx_new_image(cub.mlx, cub.win_x, cub.win_y);
    mlx_windows(&cub);
    mlx_key_hook(cub.win, ft_keys, &cub);
    mlx_hook(cub.win, 17, 0, ft_close, &cub);
    mlx_loop(cub.mlx);
    return 0;
}
