#include "../cub3d.h"


/*
* distanation between the player and the project plan is 277 
*/

void    v_field(t_cub *cub, int x, float ra)
{
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
        cub->addr[cub->width * i + x] = cub->p.colors;
        i++;
    }

}

void    projection_plane(t_cub *cub, double ra)
{
    // calculate the height of projection plane and the width of the projection plane
    int height = cub->height / 2 * tan(ra);
    int width = cub->width / 2;
    (void)width;
    (void)height;
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