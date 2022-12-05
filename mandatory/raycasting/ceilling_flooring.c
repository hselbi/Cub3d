#include "../cub3d.h"

void	ceilling_floor(t_cub *cub)
{
	unsigned int	i;
	int				j;

	i = 0;
	j = 0;
	while (j < (cub->height / 2))
	{
		i = 0;
		while (++i < (unsigned)cub->width - 1)
			cub->addr[(cub->width) * j + i] = create_rgb(cub->par.color[1][0], \
				cub->par.color[1][1], cub->par.color[1][2]);
		j++;
	}
	while (j < (cub->height - 1))
	{
		i = 0;
		while (++i < (unsigned)cub->width - 1)
			cub->addr[(cub->width) * j + i] = create_rgb(cub->par.color[0][0], \
				cub->par.color[0][1], cub->par.color[0][2]);
		j++;
	}
}
