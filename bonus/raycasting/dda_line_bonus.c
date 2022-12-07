/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_line_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hselbi <hselbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 01:00:53 by hselbi            #+#    #+#             */
/*   Updated: 2022/12/07 01:00:54 by hselbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	mini_dda_line(int end_x, int end_y, t_cub *cub)
{
	t_dda	dda;
	int		start_x;
	int		start_y;

	start_x = cub->mini_w / 2;
	start_y = cub->mini_h / 2;
	dda.dx = end_x - start_x;
	dda.dy = end_y - start_y;
	if (abs(dda.dx) > abs(dda.dy))
		dda.step = abs(dda.dx);
	else
		dda.step = abs(dda.dy);
	dda.xinc = dda.dx / (float)dda.step;
	dda.yinc = dda.dy / (float)dda.step;
	dda.x = (float)start_x;
	dda.y = (float)start_y;
	dda.i = 0;
	while (dda.i <= dda.step)
	{
		cub->mmap.add[cub->mini_w * (int)dda.y + (int)dda.x] = 0x00FF00;
		dda.x += dda.xinc;
		dda.y += dda.yinc;
		dda.i++;
	}
}
