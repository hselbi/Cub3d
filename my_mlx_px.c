#include "cub3d.h"

void my_mlx_pixel(t_cub *data, int x, int y, int color)
{
	int *dst;
	// printf("@@@ %d\n", x * (data->bits_per_pixel / 8));
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}


void	pix_mlx(t_cub *cub, int x, int y, int color)
{
	if (COL * 64 * y + x < 0 || COL * 64 * y + x > COL * 64 * ROW * 64)
		return ;
	else
		cub->addr[(COL * 64) * y + x] = color;
}