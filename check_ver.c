#include "cub3d.h"

void    ver_ray(t_cub *cub, float ra)
{
    float   rx, ry, xo, yo;
    int mx, my, mp, dof;

    ra = ra + cub->p.p_angle;
    if (ra >= PI * 2)
        ra -= PI * 2;
     if (ra <= 0)
        ra += PI * 2;
    dof = 0;
    double P1 = PI/2;
    double P2 = (3 * PI)/2;
    float ntan = -tan(ra);
    xo = 0.0;
    yo = 0.0;
    if (ra == P1 || ra == P2)
    {
        ry = cub->p.y;
        rx = cub->p.x;
        if(ra == P1)
            yo = -64;
        else
            yo = 64;
        xo = 0.0;
        dof = 8;
    }
    else if (ra > P1 && ra < P2)
    {
        rx = (int)(cub->p.x)/64 * 64 - 0.001;
        ry = (cub->p.x - rx) * ntan + cub->p.y;
        xo = -64;
        yo = -xo * ntan;
    }
    else if (ra < P1 || ra > P2)
    {
        rx = (int)(cub->p.x/64) * 64 + 64;
        ry = (cub->p.x - rx) * ntan + cub->p.y;
        xo = 64;
        yo = -xo * ntan;
    }
    while (dof < 8)
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
    cub->p.vx = rx;
    cub->p.vy = ry;
}