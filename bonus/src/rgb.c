#include "../cub3d.h"

unsigned long create_rgb(int r, int g, int b)
{
    return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

unsigned long create_yrgb(int t, int r, int g, int b)
{
    return (((t & 0xff) << 24) + ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}
