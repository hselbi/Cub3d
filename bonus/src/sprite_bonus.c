/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hselbi <hselbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 01:11:41 by hselbi            #+#    #+#             */
/*   Updated: 2022/12/09 20:32:15 by hselbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	sprite_frames(t_cub *cub)
{
	cub->sprite.farme_one = mlx_xpm_file_to_image(cub->mlx, \
	"./bonus/gun/1.xpm", &cub->sprite.width_one, &cub->sprite.height_one);
	cub->sprite.farme_two = mlx_xpm_file_to_image(cub->mlx, \
	"./bonus/gun/2.xpm", &cub->sprite.width_two, &cub->sprite.height_two);
	cub->sprite.farme_three = mlx_xpm_file_to_image(cub->mlx, \
	"./bonus/gun/3.xpm", &cub->sprite.width_three, &cub->sprite.height_three);
	cub->sprite.farme_four = mlx_xpm_file_to_image(cub->mlx, \
	"./bonus/gun/4.xpm", &cub->sprite.width_four, &cub->sprite.height_four);
	cub->sprite.farme_five = mlx_xpm_file_to_image(cub->mlx, \
	"./bonus/gun/5.xpm", &cub->sprite.width_five, &cub->sprite.height_five);
}
