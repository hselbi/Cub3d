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

// int get_color_xpm(t_text *tx_img, float x, float y, int h, int w)
// {
    
//     int colors;
//     (void)w;
//     (void)h;
//     int i = ((int)x % 64);
//     // int i = 1;
//     int j = (((int)y % 64));
//     // printf("x:\t%d\n", i);
//     // printf("y:\t%d\n", j);
//     colors = tx_img->add[64 * (int)j + (int)i];
//     return (colors);
// }

/*
* distanation between the player and the project plan is 277 
*/

void    v_field(t_cub *cub, int x, float ra)
{
    // int colors = 0;
    if (ra >= PI * 2)
        ra -= PI * 2;
    if (ra <= 0)
        ra += PI * 2;
    cub->p.dist = cub->p.dist * cos(ra);
    float dplan = 64 * cub->height / cub->p.dist;
    if (dplan > (float)cub->height)
        dplan = cub->height;
    cub->c_plan = cub->height/2 - dplan/2;
    cub->b_wall = cub->c_plan + dplan;
    cub->t_wall = cub->c_plan;
    if (cub->b_wall >= cub->height)
        cub->b_wall = cub->height;
    if (cub->t_wall < 0)
        cub->t_wall = 0;

    int i = (int)cub->t_wall;
    int j = (int)cub->b_wall;
    while(i < j)
    {
        // get_color_xpm(&cub->img, cub->p.rx, cub->p.ry);
        // colors = get_color_xpm(&cub->tx_img, cub->p.rx, cub->p.ry, cub->height, cub->width);
        // printf("%d\n", colors);
        cub->addr[cub->width * i + x] = cub->p.colors;
        // cub->addr[cub->width * i + x] = cub->p.colors;
        // printf÷("");
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