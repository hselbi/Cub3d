#include "cub3d.h"

static void	set_minimap(t_cub *cub, int y, int x, char op)
{
	int	color;
	int	i;
	int	j;

	if (op == ' ')
		return ;
	if (op == '1')
		color = 0X000000;
	if (op == '0')
		color = 0Xffffff;
	if (op == 'p')
		color = 0xff0000;
	i = -1;
	while (++i < 5)
	{
		j = -1;
		while (++j < 5)
			m->tmp[(y * 5) + i][(x * 5) + j] = color;
	}
}

void	draw_minimap(t_cub *cub)
{
	int	y;
	int	x;

	y = -1;
	while (++y < cub->height)
	{
		x = -1;
		while (++x < cub->width)
		{
			if (y == (int)cub->p.y && x == (int)cub->p.x)
				set_minimap(g->mlx, y, x, 'p');
			else
				set_minimap(g->mlx, y, x, g->cub->map[y/64][x/64]);
		}
	}
}