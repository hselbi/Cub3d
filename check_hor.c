#include "cub3d.h"

void    hor_ray(t_cub *cub)
{
    float   rx, ry, ra, xo, yo;
    int mx, my, mp, dof;

    ra = cub->p.p_angle;
    dof = 0;
    float atan = -1/tan(ra);
    xo = 0.0;
    yo = 0.0;
    rx = 0.0;
    ry = 0.0;
    if (ra > PI)
    {
        ry = (int)(cub->p.y/64) * 64 - 0.0001;
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
    if (ra == 0.0 || ra == PI)
    {
        ry = cub->p.y;
        rx = cub->p.x;
        if(ra == 0.0)
            xo = 64;
        else
            xo = -64;
        yo = 0.0;
        dof = 8;
    }
    while (dof<8)
    {
        mx = (int)(rx)/64;
        my = (int)(ry)/64;
        mp = my * ROW + mx;
        printf("%d/%d\n", mx, my);
        if (check_cor(mx, my) && cub->map[my][mx] == 1)
            dof = 8;
        else
        {
            rx += xo;
            ry += yo;
            dof += 1;
        }
    }
    cub->p.hx = rx;
    cub->p.hy = ry;
}

