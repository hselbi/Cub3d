#include "cub3d.h"

void dda_line(int start_x, int end_x, int start_y, int end_y, t_cub *cub)
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
		dx = dx / step;
		dy = dy / step;
		while (i < step)
		{
			if (cub->addr[(COL * 64) * y + x] == 0xEC7063)
				return ;
			cub->addr[(COL * 64) *  y +  x] = 0xFFFFF;
			// my_mlx_pixel(cub, x, y, 0xFFFFFF);
			x += dx;
			y += dy;
			i++;
		}
	}
}
