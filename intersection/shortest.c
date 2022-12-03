#include "../cub3d.h"

void	shortest(t_player *pl)
{
	float	h;
	float	v;

	pl->dist = 0.0;
	h = sqrt(pow((pl->x - pl->hx), 2.0) + pow((pl->y - pl->hy), 2.0));
	v = sqrt(pow((pl->x - pl->vx), 2.0) + pow((pl->vy - pl->y), 2.0));
	if (pl->f_ver == 0)
		v = 12212155.00;
	if (pl->f_hor == 0)
		h = 12212155.00;
	pl->colors = 0x6E6259;
	if (v < h)
	{
		pl->rx = pl->vx;
		pl->ry = pl->vy;
		pl->dist = v;
		pl->colors = 0xD35400;
	}
	else
	{
		pl->rx = pl->hx;
		pl->ry = pl->hy;
		pl->dist = h;
		pl->colors = 0x0000FF;
	}
}
