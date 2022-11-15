#include "cub3d.h"

void    hor_ray(t_cub *cub, float ra)
{
    float   rx, ry, xo, yo;
    int mx, my, mp, dof;

    ra = ra + cub->p.p_angle;
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
        dof = 8;
    }
    while (dof<8)
    {
        mx = (int)(rx)/64;
        my = (int)(ry)/64;
        mp = my * ROW + mx;
        if (mp > 0 && mp < ROW * COL && cub->map[my][mx] == 1)
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

