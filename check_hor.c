#include "cub3d.h"

int	pl_pos(char c)
{
    // printf("$$ ==> %d\n", c);
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == '0')
		return (1);
	return (0);
}

void    hor_ray(t_cub *cub, float ra)
{
    float   rx, ry, xo, yo;
    int mx, my, mp, dof;
    int mcol, mrow;

    ra = ra + cub->p.p_angle;
    // printf("p(%f, %f)\n", cub->p.x, cub->p.y);
    // printf("angle %lf\n", cub->p.p_angle);
    if (ra >= PI * 2)
        ra -= PI * 2;
    if (ra <= 0)
        ra += PI * 2;
    dof = 0;
    float atan = -1/tan(ra);
    xo = 0.0;
    yo = 0.0;
    rx = 0.0;
    ry = 0.0;
    if (ra > PI && ra <= PI * 2)
    {
        ry = (int)(cub->p.y/64) * 64 - 0.001;
        rx = (cub->p.y - ry) * atan + cub->p.x;
        yo = -64;
        xo = -yo * atan;
    }
    else if (ra && ra < PI)
    {
        ry = (int)(cub->p.y/64) * 64 + 64;
        rx = (cub->p.y - ry) * atan + cub->p.x;
        yo = 64;
        xo = -yo * atan;
    }
    else if (ra == 0.0 || ra == PI)
    {
        ry = cub->p.y;
        rx = cub->p.x;
        if(ra == 0.0)
            xo = 64;
        else
            xo = -64;
        yo = 0.0;
        dof = 18;
    }
    while (dof < 18)
    {
        // printf("before %d : => (%d, %d) ==> %d\n", dof, mx, my, mp);
        mx = (int)(rx)/64;
        my = (int)(ry)/64;
        mp = my * cub->col + mx;
        mcol = my * cub->col;
        mrow = mx * cub->max_row;
      if (my >= cub->col || mx >= cub->max_row)
            dof = 18;
        if (mp > 0 && mp < cub->max_row * cub->col && !pl_pos(cub->par.map[my][mx]))
            dof = 18;
        else
        {
            rx += xo;
            ry += yo;
            dof += 1;
        }
    }
    // printf("** (%f, %f) --> [%d][%d]\n", rx, ry, mx, my);
    cub->p.hx = rx;
    cub->p.hy = ry;
}

