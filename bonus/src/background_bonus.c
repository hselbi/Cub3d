/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hselbi <hselbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 01:00:43 by hselbi            #+#    #+#             */
/*   Updated: 2022/12/07 01:00:44 by hselbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	background(t_cub *cub)
{
	int	i;
	int	j;

	j = 0;
	while (j < cub->height - 1)
	{
		i = 0;
		while (i < cub->width - 1)
		{
			cub->addr[(cub->width) * j + i] = 0x6E6259;
			i++;
		}
		j++;
	}
}

void	mini_bg(t_cub *cub)
{
	int	start_y;
	int	start_x;
	int	end_y;
	int	end_x;

	start_x = 0;
	start_y = 0;
	end_y = cub->mini_w;
	end_x = cub->mini_h;
	while (start_y < end_y)
	{
		start_x = 0;
		while (start_x < end_x)
		{
			cub->mmap.add[(cub->mini_w) * start_y + start_x] = 0x6E6259;
			start_x++;
		}
		start_y++;
	}
}
