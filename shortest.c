#include "cub3d.h"


void	shortest(t_player *pl)
{
	// int	alpha = 0;
	pl->dist = 0.0;
	float h = sqrt(pow((pl->x - pl->hx), 2.0) + pow((pl->y - pl->hy), 2.0));
	float v = sqrt(pow((pl->x - pl->vx), 2.0) + pow((pl->vy - pl->y), 2.0));
	if (pl->f_ver == 0)
	{
		v = 12212155.00;
	}
	if (pl->f_hor == 0)
	{
		h = 12212155.00;
	}
	pl->colors = 0x6E6259;
	if (v < h)
	{
		// alpha = (int)90/h;
		pl->rx = pl->vx;
		pl->ry = pl->vy;
		pl->dist = v;
		pl->colors = 0xD35400;
	}
	else
	{
		// alpha = (int)90/v;
		pl->rx = pl->hx;
		pl->ry = pl->hy;
		pl->dist = h;
		pl->colors = 0x0000FF;
	}
}

void	bi_shortest(t_cub *cub)
{
	cub->p.dist = 0.0;
	float h = sqrt(pow((cub->mini.x - cub->p.vx), 2.0) + pow((cub->mini.y - cub->p.vy), 2.0));
	float v = sqrt(pow((cub->mini.x - cub->p.vx), 2.0) + pow((cub->p.vy - cub->mini.y), 2.0));
	cub->p.colors = 0x6E6259;
	if (v < h || cub->p.p_angle == 0.0)
	{
		cub->p.rx = cub->p.vx;
		cub->p.ry = cub->p.vy;
		cub->p.dist = v;
		cub->p.colors = 0xE74C3C;
	}
	else if (v > h || cub->p.p_angle == (3 * PI) / 2)
	{
		cub->p.rx = cub->p.hx;
		cub->p.ry = cub->p.hy;
		cub->p.dist = h;
		cub->p.colors = 0xF1948A;
	}
}