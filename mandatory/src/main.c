/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 00:01:43 by hselbi            #+#    #+#             */
/*   Updated: 2022/12/09 13:13:58 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	else
		return (0);
}

void	player_side(t_cub *cub, int stop, int i, int j)
{
	cub->p.prev_x = cub->p.x;
	cub->p.prev_y = cub->p.y;
	cub->p.p_angle = (3 * PI) / 2;
	if (stop && cub->par.map[j - 1][i] == 'N')
		cub->p.p_angle = (3 * PI) / 2;
	else if (stop && cub->par.map[j - 1][i] == 'S')
		cub->p.p_angle = PI / 2;
	else if (stop && cub->par.map[j - 1][i] == 'W')
		cub->p.p_angle = PI;
	else if (stop && cub->par.map[j - 1][i] == 'E')
		cub->p.p_angle = 0.0;
	cub->p.dem_x = cos(cub->p.p_angle) * 5;
	cub->p.dem_y = sin(cub->p.p_angle) * 5;
	cub->p.dist_plan = 277;
}

void	init_player(t_cub *cub)
{
	int	i;
	int	j;
	int	stop;

	i = -1;
	j = -1;
	stop = 0;
	while ((++j < cub->col) && cub->par.map[j] && !stop)
	{
		i = -1;
		while (++i < cub->row && cub->par.map[j][i] && !stop)
		{
			if (check_player(cub->par.map[j][i]))
			{
				cub->p.x = i * 64 + (64 / 2);
				cub->p.y = j * 64 + (64 / 2);
				stop = 1;
				break ;
			}
		}
	}
	cub->p.mini_x = (cub->p.x / (16 / 5));
	cub->p.mini_y = (cub->p.y / (16 / 5));
	player_side(cub, stop, i, j);
}

void	init_img_win(t_cub *cub)
{
	int	i;

	i = 0;
	cub->row = 0;
	while (cub->par.map[i])
	{
		cub->len = (int)ft_strlen(cub->par.map[i]);
		if (cub->row < cub->len)
			cub->row = cub->len;
		i++;
	}
	cub->col = i;
	cub->width = cub->win_x;
	cub->height = cub->win_y;
	cub->img = mlx_new_image(cub->mlx, cub->width, cub->height);
	if (!cub->img)
		ft_perror("Failed!!\n");
	cub->addr = (int *)mlx_get_data_addr(cub->img, &cub->bits_per_pixel, \
		&cub->line_length, &cub->endian);
	if (!cub->addr)
		printf("Failed!!\n");
}

int	main(int ac, char **av)
{
	t_cub	cub;
	int		fd;

	cub.win_x = 960;
	cub.win_y = 720;
	if (ac > 1)
	{
		fd = open_fd(av[1]);
		cub.par = fill_struct(fd);
		cub.mlx = mlx_init();
		cub.win = mlx_new_window(cub.mlx, cub.win_x, cub.win_y, "CUB3D");
		if (!cub.win)
			printf("failed!!!\n");
		init_img_win(&cub);
		init_player(&cub);
		init_texture(&cub);
		mlx_loop_hook(cub.mlx, mlx_windows, &cub);
		mlx_hook(cub.win, 2, 0, advance_keys, &cub);
		mlx_hook(cub.win, 17, 0, ft_close, &cub);
		mlx_loop(cub.mlx);
	}
	return (0);
}
