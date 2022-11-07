#include "cub3d.h"

void    hor_ray(t_cub *cub)
{
    int r, mx, my, mp, dof;
    float   rx, ry, ra, xo, yo;

    r = 0;
    ra = cub->p.p_angle;
    while (r < 1)
    {
        if (ra > PI)
        {
            ry = (((int)cub->p.y>>6)<<6)-0.0001;
            rx = (cub->p.y - ry) * atan(ra) + cub->p.x;
            yo = -64;
            xo = -yo * atan(ra);
        }
        if (ra < PI)
        {
            ry = (((int)cub->p.y>>6)<<6)+64;
            rx = (cub->p.y - ry) * atan(ra) + cub->p.x;
            yo = 64;
            xo = -yo * atan(ra);
        }
        while (dof<8)
        {
            mx = (int)(rx) >> 6;
            my = (int)(ry) >> 6;
            mp = my * ROW + mx;
            if (mp < ROW * COL && cub->map[mp][0] == 1)
                dof = 8;
            else
            {
                rx += xo;
                ry += yo;
                dof += 1;
            }
        }
        dda_line((int)cub->p.x, (int)rx, (int)cub->p.y, (int)ry, cub);
        r++;
    }

}