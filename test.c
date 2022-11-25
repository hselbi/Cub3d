// #include "cub3d.h"



#include <mlx.h>
#include <stdio.h>

// int	main(void)
// {
// 	void	*mlx;

// 	mlx = mlx_init();
//     mlx_loop(mlx);
// }


// typedef struct s_img
// {
// 	int x;
// 	int y;
// 	void *addr;
// 	void *img;
// 	int		line_len;
// 	int		endien;
// 	int bpp;
// }t_img;

// typedef struct s_image
// {
// 	int x;
// 	int y;
// 	void *addr;
// 	void *img;
// 	int		line_len;
// 	int		endien;
// 	int bpp;
// }t_image;


// int	my_get_color(t_img *data, int x, int y)
// {
// 	int *dst;
// 	// printf("@@@ %d\n", x * (data->bits_per_pixel / 8));
// 	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
// 	return(*(unsigned int *)dst);
// }


// void my_mlx_pixel(t_data *data, int x, int y, int color)
// {
// 	int *dst;
// 	// printf("@@@ %d\n", x * (data->bits_per_pixel / 8));
// 	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
// 	*(unsigned int *)dst = color;
// }


// int	main(void)
// {
// 	// t_img	img;
// 	t_image	image;
// 	void	*mlx;
// 	// char	*relative_path = "./textures/kyle-edmonds-stone-path-texture.xpm";
// 	// void	*addr;
// 	void	*mlx_win;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
//     // image.img = mlx_new_image(mlx, 650, 650);
// 	img.img = mlx_xpm_file_to_image(mlx, relative_path, &img.x, &img.y);
// 	// mlx_put_image_to_window(mlx, mlx_win, img.img, x, y);
// 	mlx_xpm_to_image(mlx, relative_path, &img_width, &img_height);
// 	// image.addr = mlx_get_data_addr(image.img, &image.bpp, &image.line_len, &image.endien);
// 	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endien);
// 	printf(">>>>>>> %d\n", img.x);
// 	printf(">>>>>>> %d\n", my_get_color(&img, 45, 2));
// 	// int	color = 0;
	
	// int i = 0;
	// int j = 0;
	// int x = 0;
	// int y = 0;
	// while (i < 17)
	// {
	// 	j = 0;
	// 	x = 0;
	// 	while (j < 30)
	// 	{
	// 		put_image_wall(x, y, &img, mlx_win, mlx);
	// 		// put_imag_wall();
	// 		x += 64;
	// 		j++;
	// 	}
	// 	y += 64;
	// 	i++;
	// }
	


/**************************************************************/

// void	put_image_wall(int x, int y, t_img *img, void *win, void *mlx)
// {
// 	int	img_width;
// 	int	img_height;
// 	img->img = mlx_xpm_file_to_image(mlx, "./textures/bricks.xpm", &img_width, &img_height);
// 	mlx
// 	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endien);
// }

typedef struct	s_txt {
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_txt;


typedef struct	s_img {
	t_txt	txt;
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;


// void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = (int *)data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }


int	my_get_color(t_txt *data, int x, int y)
{
	int *dst;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return(*(unsigned int *)dst);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	// t_img image;
	char	*relative_path = "./textures/walkstone.xpm";
	int img_height;
	int img_width;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = (int *)mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	img.txt.img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	img.txt.addr = mlx_get_data_addr(img.txt.img, &img.txt.bits_per_pixel, &img.txt.line_length, &img.txt.endian);
	
	fprintf(stderr, "w: %d\n", img_width);
	fprintf(stderr, "h: %d\n", img_height);
	// img.img =  mlx_xpm_to_image(mlx, &relative_path, &img_height, &img_width);
	// printf("h %d\n", img_height);
	// printf("w %d\n", img_width);
	int i = 0;
	int j = 0;
	while(i < 64)
	{
		j = 0;
		while (j < 64)
		{
			printf("%d>>>>>>> %d\n", j, my_get_color(&img.txt, j, i));
			img.addr[1920 * i + j] = my_get_color(&img.txt, j, i);
			// my_mlx_pixel_put(&img, j, i, my_get_color(&img.txt, j, i));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}


/**************************************************************/

