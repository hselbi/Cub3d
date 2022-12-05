#include "../cub3d.h"

void	background(t_cub *cub)
{
	int	i;
	int	j;

	j = 0;
	while (j < cub->height - 1)
	{
		i = 0;
		while (i < cub->width - 1)
		{
			cub->addr[(cub->width) * j + i] = 0x6E6259;
			i++;
		}
		j++;
	}
}
