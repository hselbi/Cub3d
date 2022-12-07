/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hselbi <hselbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 02:22:43 by hselbi            #+#    #+#             */
/*   Updated: 2022/12/07 17:27:02 by hselbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_wind(t_cub *cub)
{
	cub->win_x = 960;
	cub->win_y = 720;
	cub->mini_h = 180;
	cub->mini_w = 180;
}

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
	cub->gun_shot = FALSE;
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
		ft_perror("Failed Created image\n");
	cub->addr = (int *)mlx_get_data_addr(cub->img, &cub->bits_per_pixel, \
		&cub->line_length, &cub->endian);
	cub->mmap.img = mlx_new_image(cub->mlx, cub->mini_w, cub->mini_h);
	if (!cub->img)
		ft_perror("Failed Created image for minimap\n");
	cub->mmap.add = (int *)mlx_get_data_addr(cub->mmap.img, \
		&cub->bits_per_pixel, &cub->line_length, &cub->endian);
	sprite_frames(cub);
}
