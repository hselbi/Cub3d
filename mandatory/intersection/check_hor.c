/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_hor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hselbi <hselbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 00:08:29 by hselbi            #+#    #+#             */
/*   Updated: 2022/12/09 20:58:15 by hselbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	pl_pos(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == '0')
		return (1);
	return (0);
}

void	coord_hwall(t_hor *hor, t_cub *cub, float ra)
{
	while (1)
	{
		hor->mx = (int)(hor->rx) / 64;
		hor->my = (int)(hor->ry) / 64;
		if (ra > PI && ra < 2 * PI)
			hor->my = (int)(hor->ry - 1) / 64;
		hor->mp = hor->my * cub->col + hor->mx;
		if (hor->my < 0 || hor->my >= cub->col \
			|| hor->mx < 0 || hor->mx >= cub->row)
			break ;
		if (hor->mp > 0 && hor->mp < cub->row * cub->col \
			&& !pl_pos(cub->par.map[hor->my][hor->mx]))
		{
			cub->p.f_hor = 1;
			break ;
		}
		else
		{
			hor->rx += hor->xo;
			hor->ry += hor->yo;
			hor->dof += 1;
		}
	}
}

void	init_hor(t_cub *cub, t_hor *hor, float ra)
{
	if (ra > PI && ra < PI * 2)
	{
		hor->ry = (int)(cub->p.y / 64) * 64 - 0.0001;
		hor->rx = (cub->p.y - hor->ry) * hor->atan + cub->p.x;
		hor->yo = -64;
		hor->xo = -hor->yo * hor->atan;
	}
	else if (ra && ra < PI)
	{
		hor->ry = (int)(cub->p.y / 64) * 64 + 64;
		hor->rx = (cub->p.y - hor->ry) * hor->atan + cub->p.x;
		hor->yo = 64;
		hor->xo = -hor->yo * hor->atan;
	}
	else if (ra == 0.0 || ra == PI)
	{
		hor->ry = cub->p.y;
		hor->rx = cub->p.x;
		if (ra == 0.0)
			hor->xo = 64;
		else
			hor->xo = -64;
		hor->yo = 0.0;
		hor->dof = 18;
	}
}

void	hor_ray(t_cub *cub, float ra)
{
	t_hor	hor;

	cub->p.f_hor = 0;
	if (ra >= PI * 2)
		ra -= PI * 2;
	else if (ra <= 0)
		ra += PI * 2;
	hor.dof = 0;
	hor.atan = -1 / tan(ra);
	hor.xo = 0.0;
	hor.yo = 0.0;
	hor.rx = 0.0;
	hor.ry = 0.0;
	init_hor(cub, &hor, ra);
	coord_hwall(&hor, cub, ra);
	cub->p.hx = hor.rx;
	cub->p.hy = hor.ry;
}
