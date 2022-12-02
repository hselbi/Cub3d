#include "cub3d.h"

/*
* this is for drawing line from player to the wall
*/

void dda_line(int start_x, int end_x, int start_y, int end_y, t_cub *cub)
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
		cub->addr[cub->width *  (int)y +  (int)x] = 0x00FF00;
		x += xinc;
		y += yinc;
		i++;
	}
}


void mini_dda_line(int start_x, int end_x, int start_y, int end_y, t_cub *cub)
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
		cub->mmap.add[cub->mini_w *  (int)y +  (int)x] = 0x00FF00;
		x += xinc;
		y += yinc;
		i++;
	}
}
