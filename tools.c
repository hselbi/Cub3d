#include "cub3d.h"

int check_cor(int mx, int my)
{
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

int	pl_pos(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == '0')
		return (1);
	return (0);
}