#include "cub3d.h"

int check_cor(int mx, int my)
{
    printf("x ==> %d\n", mx);
    printf("y ==> %d\n", my);
    if (mx >= 0 && mx <= COL)
        return (1);
    if (my >= 0 && my <= ROW)
        return (1);
    else
        return (0);
}


int	player_pos(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}