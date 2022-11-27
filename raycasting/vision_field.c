#include "../cub3d.h"



// void	put_image_wall(int x, int y, t_img *img, void *win, void *mlx)
// {
// 	int	img_width;
// 	int	img_height;
// 	img->img = mlx_xpm_file_to_image(mlx, "./textures/bricks.xpm", &img_width, &img_height);
// 	mlx_put_image_to_window(mlx, win, img->img, x, y);
// }

// int	my_get_color(t_text *data, int x, int y)
// {
// 	int *dst;
// 	dst = data->add + x * (data->bits_per_pixel / 8));
// 	return(*(unsigned int *)dst);
// }

int get_color_xpm(t_text *tx_img, float x, float y, int h, int w)
{
    
    int colors;
    (void)w;
    // (void)h;
    int i = ((int)x % 64);
    // int i = 1;
    int j = ((int)y * 64) / h;
    printf("w %d\n", tx_img->width);
    printf("h %d\n", tx_img->height);
    // printf("x: %f\bi: %d\n", x, i);
    // printf("y: %f\bj: %d\n", y, j);
    colors = tx_img->add[tx_img->width * (int)j + (int)i];
    return (colors);
}

/*
* distanation between the player and the project plan is 277 
*/

void    v_field(t_cub *cub, int x, float ra)
{
    // int colors = 0;
    // ra = ra + cub->p.p_angle;
    if (ra >= PI * 2)
        ra -= PI * 2;
    if (ra <= 0)
        ra += PI * 2;
    cub->p.dist = cub->p.dist * cos(ra);
    float dplan = 64 * cub->height / cub->p.dist;
    // if (dplan > (float)cub->height)
    //     dplan = cub->height;
    cub->c_plan = cub->height/2 - dplan/2;
    cub->b_wall = cub->c_plan + dplan;
    cub->t_wall = cub->c_plan;
    if (cub->b_wall >= cub->height)
        cub->b_wall = cub->height;
    if (cub->t_wall < 0)
        cub->t_wall = 0;
    int flag_h = -1;
    int flag_v = -1;
    int ver = 0;
    int tx = 64 * cub->we_width;
    if ((cub->p.f_hor == 1 && cub->p.hx > 0 && cub->p.hx == cub->p.rx)) 
    {
        if (cub->p.p_angle >= PI && cub->p.p_angle <= 2 * PI)
        {
            tx = ((int)cub->p.hx % 64) * (cub->no_width / 64);
            flag_h = 2;
        }
        else
        {
            tx = ((int)cub->p.hx % 64) * (cub->so_width / 64);
            flag_h = 1;
        }
    }
    else if ((cub->p.f_ver == 1 && cub->p.vy > 0 && cub->p.vy == cub->p.ry)) 
    {
        ver = 1;
        if (cub->p.p_angle >= PI / 2 && cub->p.p_angle < (3 * PI) / 2)
        {
            flag_v = 1;
            tx = ((int)cub->p.vy % 64) * (cub->ea_width / 64);
        }
        else
        {
            flag_v = 2;
            tx = ((int)cub->p.vy % 64) * (cub->we_width / 64);
        }
    }
    int i = (int)cub->t_wall;
    int j = (int)cub->b_wall;
    while(i < j)
    {
        int dist = i + (dplan / 2) - (cub->height / 2);
        int ty = 0;
        int texel = 0;
        if (ver == 0)
        {
            if (flag_h == 2)
            {
                ty = dist * (cub->no_width / dplan);
                texel = cub->no[(cub->no_width * ty) + tx];
            }
            else
            {
                ty = dist * (cub->so_width / dplan);
                texel = cub->so[(cub->so_width * ty) + tx];
            }
        }
        else
        {
            if (flag_v == 2)
            {
                ty = dist * (cub->we_width / dplan);
                texel = cub->we[(cub->we_width * ty) + tx];
            }
            else
            {
                ty = dist * (cub->ea_width / dplan);
                texel = cub->ea[(cub->ea_width * ty) + tx];
            }
        }
    
        // int ty = dist * (width_text / dplan);
        // int texel = texture[width_text * ty + tx];
    
        // if(flag == 0)
        //     texel = cub->no[(width_text * ty) + tx];
        // else if(flag == 1)
        //     texel = cub->so[(width_text * ty) + tx];
        // else if(flag == 2)
        //     texel = cub->we[(width_text * ty) + tx];
        // else if(flag == 3)
        //     texel = cub->we[(width_text * ty) + tx];
    
        cub->addr[cub->width * i + x] = texel;
        i++;
    }
}


/*
! to do list
    * need to have the  distance from the player to plan
    * need to split the upper screen with 
*/

/*
* var projectedWallHeight=(this.WALL_HEIGHT*this.fPlayerDistanceToTheProjectionPlane/dist);
*			bottomOfWall = this.fProjectionPlaneYCenter+(projectedWallHeight*0.5);
*			topOfWall = this.fProjectionPlaneYCenter-(projectedWallHeight*0.5);
*			if (topOfWall<0)
*				topOfWall=0;
*			if (bottomOfWall>=this.PROJECTIONPLANEHEIGHT)
*				bottomOfWall=this.PROJECTIONPLANEHEIGHT-1;
*/