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
		printf("$$$ %d/%d\n", dx, dy);
		while (i < step)
		{
			// if (cub->addr[(COL * 64) * y + x] == 0xEC7063)
			// 	return ;
			cub->addr[(COL * 64) *  y +  x] = 0x00FF00;
			// my_mlx_pixel(cub, x, y, 0xFFFFFF);
			x += dx;
			y += dy;
			i++;
		}
	}
}

void dda_line2(int start_x, int end_x, int start_y, int end_y, t_cub *cub)
{
	// if (end_x < start_x)
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
		cub->addr[(COL * 64) *  (int)y +  (int)x] = 0x00FF00;
		x += xinc;
		y += yinc;
		i++;
	}
}

// void DDA(int X0, int Y0, int X1, int Y1)
// {
//     // calculate dx & dy
//     int dx = X1 - X0;
//     int dy = Y1 - Y0;
 
//     // calculate steps required for generating pixels
//     int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
 
//     // calculate increment in x & y for each steps
//     float Xinc = dx / (float)steps;
//     float Yinc = dy / (float)steps;
 
//     // Put pixel for each step
//     float X = X0;
//     float Y = Y0;
//     for (int i = 0; i <= steps; i++) {
//         putpixel(round(X), round(Y),
//                  RED); // put pixel at (X,Y)
//         X += Xinc; // increment in x at each step
//         Y += Yinc; // increment in y at each step
//         delay(100); // for visualization of line-
//                     // generation step by step
//     }
// }