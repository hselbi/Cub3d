#include "cub3d.h"

void    test(t_cub *cub)
{

    int i = 0;
    int j = 0;
    while(i < 64)
    {
    	j = 0;
    	while (j < 64)
    	{
    		cub->mmap.add[200 * i + j] = 0x00FFA1;
    		j++;
    	}
    	i++;
    }
    i = 0;
    j = 0;
}

int mlx_windows(t_cub *cub)
{
	ceilling_floor_max(cub);

	float ra = cub->p.p_angle -  (PI / 6); // -30
	int x = 0;
	int tmp_i = 0;
	int tmp_j = 0;
	cub->p.mini_x = cub->p.x / (3.2);
	cub->p.mini_y = cub->p.y / (3.2);
	cub->p.i = (int)((cub->p.x - 32) / 64);
	cub->p.j = (int)((cub->p.y - 32) / 64);
	while (x < cub->width) // +30
	{
		if (ra > 2 * PI)
			ra -= 2 * PI;
		if(ra < 0)
			ra += 2*PI;
		tmp_i = (int)(cub->p.x / 64);
		tmp_j = (int)(cub->p.y / 64);
		if (cub->par.map[tmp_j][tmp_i] == '1')
		{
			cub->p.x = cub->p.prev_x;
			cub->p.y = cub->p.prev_y;
		}
		hor_ray(cub, ra);
		ver_ray(cub, ra);
		shortest(&cub->p);
		v_field(cub, x, ra);
		x += 1;
		ra += ((PI / 3) / cub->width);
	}
	draw_minimap(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
    mlx_put_image_to_window(cub->mlx, cub->win, cub->mmap.img, 0, 0);
	return (0);
}
