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
        dof = 18;
    }
    while (dof < 18)
    {
        mx = (int)(rx)/64;
        my = (int)(ry)/64;
        mp = my * cub->col + mx;
      if (my < 0 || my >= cub->col || mx < 0 || mx >= cub->max_row)
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
    cub->p.hx = rx;
    cub->p.hy = ry;
}


void    bi_hor_ray(t_cub *cub, float ra)
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
        ry = (int)(cub->mini.y/16) * 16 - 0.001;
        rx = (cub->mini.y - ry) * atan + cub->mini.x;
        yo = -16;
        xo = -yo * atan;
    }
    else if (ra && ra < PI)
    {
        ry = (int)(cub->mini.y/16) * 16 + 16;
        rx = (cub->mini.y - ry) * atan + cub->mini.x;
        yo = 16;
        xo = -yo * atan;
    }
    else if (ra == 0.0 || ra == PI)
    {
        ry = cub->mini.y;
        rx = cub->mini.x;
        if(ra == 0.0)
            xo = 16;
        else
            xo = -16;
        yo = 0.0;
        dof = 18;
    }
    while (dof < 18)
    {
        mx = (int)(rx)/16;
        my = (int)(ry)/16;
        mp = my * cub->col + mx;
      if (my < 0 || my >= cub->col || mx < 0 || mx >= cub->max_row)
            break;
        if (mp > 0 && mp < cub->max_row * cub->col && cub->par.map[my][mx] == 1)
            break;
        else
        {
            rx += xo;
            ry += yo;
            dof += 1;
        }
    }
    cub->mini.rx = rx;
    cub->mini.ry = ry;
}

