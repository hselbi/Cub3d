#include "cub3d.h"

int check_cor(int mx, int my)
{
    if (mx >= 0 && mx <= COL)
    {
        if (my >= 0 && mx <= ROW)
            return (0);
        else
            return (1);
    }
    else
        return (1);
}
