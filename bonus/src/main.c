/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 01:15:21 by hselbi            #+#    #+#             */
/*   Updated: 2022/12/09 13:16:49 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	main(int ac, char **av)
{
	t_cub	cub;
	int		fd;

	init_wind(&cub);
	if (ac > 1)
	{
		fd = open_fd(av[1]);
		cub.par = fill_struct(fd);
		cub.mlx = mlx_init();
		cub.win = mlx_new_window(cub.mlx, cub.win_x, cub.win_y, "CUB3D");
		if (!cub.win)
			printf("failed!!!\n");
		init_img_win(&cub);
		mlx_mouse_get_pos(cub.win, &cub.mouse_x, &cub.mouse_y);
		init_player(&cub);
		init_texture(&cub);
		mlx_loop_hook(cub.mlx, mlx_windows, &cub);
		mlx_mouse_hide();
		mlx_mouse_hook(cub.win, mouse_hook, &cub);
		mlx_hook(cub.win, 6, 0, func, &cub);
		mlx_hook(cub.win, 2, 0, advance_keys, &cub);
		mlx_hook(cub.win, 17, 0, ft_close, &cub);
		mlx_loop(cub.mlx);
	}
	return (0);
}
