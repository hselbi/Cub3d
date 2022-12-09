/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hselbi <hselbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 23:44:25 by hselbi            #+#    #+#             */
/*   Updated: 2022/12/07 20:31:35 by hselbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	fill_arr(t_cub *cub, int *res)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++j < cub->tx_img.height)
	{
		i = -1;
		while (++i < cub->tx_img.width)
		{
			res[(cub->tx_img.width * j) + i] = \
				cub->tx_img.add[cub->tx_img.width * j + i];
		}
	}
}

int	*fill_texture(t_cub *cub, int red)
{
	int	*res;
	int	i;
	int	j;

	i = -1;
	j = -1;
	cub->tx_img.img = mlx_xpm_file_to_image(cub->mlx, cub->par.text[red], \
		&cub->tx_img.width, &cub->tx_img.height);
	if (!cub->tx_img.img)
		return (NULL);
	cub->tx_img.add = (int *)mlx_get_data_addr(cub->tx_img.img, \
		&cub->bits_per_pixel, &cub->line_length, &cub->endian);
	res = (int *)malloc(sizeof(int) * (cub->tx_img.height * cub->tx_img.width));
	if (!res)
		return (0);
	fill_arr(cub, res);
	mlx_destroy_image(cub->mlx, cub->tx_img.img);
	return (res);
}

void	init_texture(t_cub *cub)
{
	cub->no = fill_texture(cub, 0);
	cub->no_width = cub->tx_img.width;
	cub->so = fill_texture(cub, 1);
	cub->so_width = cub->tx_img.width;
	cub->we = fill_texture(cub, 2);
	cub->we_width = cub->tx_img.width;
	cub->ea = fill_texture(cub, 3);
	cub->ea_width = cub->tx_img.width;
	if (!cub->no || !cub->ea || !cub->so || !cub->we)
		ft_perror("Failed to create texture");
}
