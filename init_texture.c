#include "cub3d.h"


int	*load_image(t_cub *cub, char *path, t_text *img)
{
	int		*res;

	img->img = mlx_xpm_file_to_image(cub->mlx, path, &img->width, &img->height);
	img->add = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->line_length, &img->endian);
    // fprintf(stderr, "line %d\n", img->line_length);
    // fprintf(stderr, "bpp %d\n", img->bpp);
    // fprintf(stderr, "endian %d\n", img->endian);
	res = (int *)malloc(sizeof(int) * (img->width * img->height));
	for (int y = 0; y < img->height; y++)
	{
		for (int x = 0; x < img->width; x++)
		{
			res[img->width * y + x] = img->add[img->width * y + x];
		}
	}
	mlx_destroy_image(cub->mlx, img->img);
	return (res);
}



int *fill_texture(t_cub *cub, int red)
{
    int *res;
    int i = 0;
    int j = 0;
    cub->tx_img.img = mlx_xpm_file_to_image(cub->mlx, cub->par.text[red], &cub->tx_img.width, &cub->tx_img.height);
    cub->tx_img.add = (int *)mlx_get_data_addr(cub->tx_img.img, &cub->bits_per_pixel, &cub->line_length, &cub->endian);
    // printf("w %d\nh %d\n", cub->tx_img.width, cub->tx_img.height);
    res = (int *)malloc(sizeof(int) * (cub->tx_img.height * cub->tx_img.width));
    if (!res)
        return (0);
    while (j < cub->tx_img.height)
    {
        i = 0;
        while (i < cub->tx_img.width)
        {

            res[(cub->tx_img.width * j) + i] = cub->tx_img.add[cub->tx_img.width * j + i];
            // printf("x : %d = %d\n", i, cub->tx_img.add[cub->tx_img.width * j + i]);
            i++;
        }
        j++;
    }
    mlx_destroy_image(cub->mlx, cub->tx_img.img);
    return (res);
}

void    init_texture(t_cub *cub)
{
    // printf("test 0\n");
    // cub->no = load_image(cub, 0, &cub->tx_img);
    cub->no = fill_texture(cub, 0);
    cub->no_width = cub->tx_img.width;
    cub->so = fill_texture(cub, 1);
    cub->so_width = cub->tx_img.width;
    cub->we = fill_texture(cub, 2);
    cub->we_width = cub->tx_img.width;
    cub->ea = fill_texture(cub, 3);
    cub->ea_width = cub->tx_img.width;
    // printf("==> w %d\n==> h %d\n", cub->tx_img.width, cub->tx_img.height);

    // for (int y = 0; y < cub->tx_img.height; y++)
	// {
	// 	for (int x = 0; x < cub->tx_img.width; x++)
	// 	{
    //         if (cub->no[cub->tx_img.width * y + x] > 0)
    //             printf("x : %d = %d\n", x, cub->ea[cub->tx_img.width * y + x]);
	// 		else
    //             break;
    //         // r÷es[img->img_width * y + x] = img->data[img->img_width * y + x];
	// 	}
	// }
    
    // printf("test 1\n");
    // cub->texture[1] = fill_texture(cub, 1);
    // printf("test 2\n");
    // cub->texture[2] = fill_texture(cub, 2);
    // printf("test 3\n");
    // cub->texture[3] = fill_texture(cub, 3);
}