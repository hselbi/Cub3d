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
			cub->addr[cub->width * y + x] = 0x00FF00;
			x += dx;
			y += dy;
			i++;
		}
	}
}

void dda_line2(int start_x, int end_x, int start_y, int end_y, t_cub *cub)
{
	int dx = end_x - start_x;
	int dy = end_y - start_y;
	
	int step = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	float xinc = dx / (float)step;
	float yinc = dy / (float)step;

	float x = (float)start_x;
	float y = (float)start_y;
	int i = 0;
	while (i <= step)
	{
		cub->addr[cub->width *  (int)y +  (int)x] = 0x000000;
		x += xinc;
		y += yinc;
		i++;
	}
}
