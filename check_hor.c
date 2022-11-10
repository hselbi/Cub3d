#include "cub3d.h"

void    hor_ray(t_cub *cub)
{
    float   rx, ry, ra, xo, yo;
    int mx, my, mp, dof;

    ra = cub->p.p_angle;
    dof = 0;
    // printf("angle %f/%f\n", ra, cub->p.p_angle);
    float atan = -1/tan(ra);
    if (ra > PI)
    {
        // ry = (((int)cub->p.y>>6)<<6) - 0.0001;
        ry = (int)(cub->p.y/64) * 64 -0.0001;
        rx = (cub->p.y - ry) * atan + cub->p.x;
        // printf("x %d\ny %d\n", mx, my);
        yo = -64;
        xo = -yo * atan;
    }
    if (ra < PI)
    {
        // ry = (((int)cub->p.y>>6)<<6) + 64;
        ry = (int)(cub->p.y/64) * 64 + 64;
        rx = (cub->p.y - ry) * atan + cub->p.x;
        // printf("r : %f\n", rx);
        yo = 64;
        xo = -yo * atan;
    }
    if (ra == 0.0 || ra == PI)
    {
        ry = cub->p.y;
        rx = cub->p.x;
        dof = 8;
    }
    while (dof<8)
    {
        mx = (int)(rx)/64 - 2;
        my = (int)(ry)/64;
        mp = my * ROW + mx;
        // printf("x %d\ny %d ==> %d\n", mx, my, mp);
        if ( mp > 0 && mp < ROW * COL && cub->map[my][mx] == 1)
            dof = 8;
        else
        {
            rx += xo;
            ry += yo;
            dof += 1;
        }
    }
    // printf("rx : %f\n", rx);
    // printf("ry : %f\n", ry);
    // dda_line((int)cub->p.x, (int)rx, (int)cub->p.y, (int)ry, cub);
    dda_line2((int)cub->p.x, (int)rx, (int)cub->p.y, (int)ry, cub);
}