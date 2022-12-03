#include "../cub3d.h"


void    v_field(t_cub *cub, int x, float ra)
{
    cub->p.dist = cub->p.dist * cos(ra - cub->p.p_angle);
    float dplan = 64 * cub->height / cub->p.dist;
    cub->c_plan = cub->height/2 - dplan/2;
    cub->b_wall = cub->c_plan + dplan;
    cub->t_wall = cub->c_plan;
    if (cub->b_wall >= cub->height)
        cub->b_wall = cub->height;
    if (cub->t_wall < 0)
        cub->t_wall = 0;
    int a = 0;
    int width_text = 0;
    int flag_v = -1;
    int flag_h = -1;
    int tx;
    if ((cub->p.f_hor == 1  && cub->p.hx == cub->p.rx))
    {
        a = 1;
        if (ra > PI && ra < 2 * PI)
        {
            width_text = cub->no_width;
            flag_h = 2;
        }
        else
        {
            width_text = cub->so_width;
            flag_h = 1;
        }
        tx = ((int)cub->p.hx % 64) * (width_text / 64);
    }
    else if ((cub->p.f_ver == 1 && cub->p.vy == cub->p.ry))
    {
        if (ra > PI / 2 && ra < (3 * PI) / 2)
        {
            flag_v = 1;
            width_text = cub->we_width;
        }
        else
        {
            flag_v = 2;
            width_text = cub->ea_width;
        }
        tx = ((int)cub->p.vy % 64) * (width_text / 64);
    }
    
    int i = (int)cub->t_wall;
    int j = (int)cub->b_wall;
    while(i < j)
    {
        if (tx > width_text)
            tx = width_text;
        int dist = i + (dplan / 2) - (cub->height / 2);
        int ty = dist * (width_text / dplan);
        int texel = 0;
        if (ty > width_text)
            ty = width_text;
        if (a == 1)
        {
            if (flag_h == 2)
                texel = cub->no[(width_text * ty) + tx];
            else
                texel = cub->so[(width_text * ty) + tx];
        }
        else
        {
            if (flag_v == 1)
                texel = cub->we[(width_text * ty) + tx];
            else
                texel = cub->ea[(width_text * ty) + tx];
        }
        cub->addr[cub->width * i + x] = texel;
        i++;
    }
}
