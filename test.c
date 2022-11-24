#include "cub3d.h"



#include <mlx.h>

// int	main(void)
// {
// 	void	*mlx;

// 	mlx = mlx_init();
//     mlx_loop(mlx);
// }


typedef struct s_img
{
	int x;
	int y;
	void *addr;
	void *img;
	int		line_len;
	int		endien;
	int bpp;
}t_img;


int	my_get_color(t_img *data, int x, int y)
{
	int *dst;
	// printf("@@@ %d\n", x * (data->bits_per_pixel / 8));
	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	return(*(unsigned int *)dst);
}

int	main(void)
{
	t_img	img;
	void	*mlx;
	char	*relative_path = "./textures/kyle-edmonds-stone-path-texture.xpm";
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    // img = mlx_new_image(mlx, 1920, 1080);
	//img = mlx_xpm_to_image(mlx, relative_path, &img_width, &img_height);
	img.img = mlx_xpm_file_to_image(mlx, relative_path, &img.x, &img.y);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endien);
	printf(">>>>>>> %d\n", img.x);
	printf(">>>>>>> %d\n", my_get_color(&img, 2, 2));

	mlx_loop(mlx);
}
/*
typedef struct s_init
{
    void    *ad
}   t_init;


int		key_event(int key_code, t_init *init)
{
	int img_width;
	int img_height;

	if (key_code == 53)
	{
		printf ("exit game\n");
		exit(0);
	}

	if (key_code == 13)
	{
		if (0 <= init->map->char_pos_y - 1)
			init->map->char_pos_y--;
	}
	if(key_code == 0)
	{
		if (0 <= init->map->char_pos_x - 1)
			init->map->char_pos_x--;
	}
	if (key_code == 1)
	{
		if (init->map->map_y > init->map->char_pos_y + 1)
			init->map->char_pos_y++;
	}
	if (key_code == 2)
	{
		if (init->map->map_x > init->map->char_pos_x + 1)
			init->map->char_pos_x++;
	}
	mlx_destroy_image(init->mlx, init->character);
	init->character = mlx_xpm_file_to_image(init->mlx, "./textures/kyle-edmonds-stone-path-texture.xpm", &img_width, &img_height);
	mlx_put_image_to_window(init->mlx, init->win, init->character, 52 * init->map->char_pos_x, 52 * init->map->char_pos_y);

	return (0);
}

int		main(int argc, char *argv[])
{
	t_init	*init;
	int img_width;
	int img_height;
	int i;
	int j;

	if (argc != 2)
		exit(1);
	if (!(init = (t_init*)malloc(sizeof(t_init))))
		exit(1);
	if (!(init->map = read_map(argv[1])))
	{
		free(init);
		exit(1);
	}
	init->mlx = mlx_init();

	init->win = mlx_new_window(init->mlx, init->map->map_x * (SIZE), init->map->map_y * (SIZE), "mlx_project");
	if (!(init->ptr_arr = (void **)malloc(sizeof(void *) * init->map->max_map)))
	{
		free(init);
		exit(1);
	}
	i = 0;
	while (i < init->map->map_y)
	{
		j = 0;
		while (j < init->map->map_x)
		{
				init->ptr_arr[i * init->map->map_y + j] = mlx_xpm_file_to_image(init->mlx, "./textures/kyle-edmonds-stone-path-texture.xpm", &img_width, &img_height);
			mlx_put_image_to_window(init->mlx, init->win, init->ptr_arr[i * init->map->map_y + j], j * 52,  i * 52);
			j++;
		}
		i++;
	}
	init->character = malloc(sizeof(void *));
	init->character = mlx_xpm_file_to_image(init->mlx, "./textures/kyle-edmonds-stone-path-texture.xpm", &img_width, &img_height);
	mlx_put_image_to_window(init->mlx, init->win, init->character, 52 * init->map->char_pos_x, 52 * init->map->char_pos_y);

	printf ("char pos : [%d][%d]\n", init->map->char_pos_x, init->map->char_pos_y);
	mlx_key_hook(init->win, key_event, init);
	mlx_loop(init->mlx);
	return (0);
}


*/