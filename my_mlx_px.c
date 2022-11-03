#include "cub3d.h"

void my_mlx_pixel(t_cub *data, int x, int y, int color)
{
	int *dst;
	// printf("@@@ %d\n", x * (data->bits_per_pixel / 8));
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
