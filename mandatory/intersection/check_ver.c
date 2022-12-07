/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hselbi <hselbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 00:08:32 by hselbi            #+#    #+#             */
/*   Updated: 2022/12/07 00:30:34 by hselbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	coor_vwall(t_ver *ver, t_cub *cub, float ra)
{
	while (ver->dof < 18)
	{
		ver->mx = (floor)(ver->rx) / 64;
		if (ra > (PI / 2) && ra < (3 * PI / 2))
			ver->mx = (floor)(ver->rx - 1) / 64;
		ver->my = (floor)(ver->ry) / 64;
		ver->mp = ver->my * cub->col + ver->mx;
		if (ver->my < 0 || ver->my >= cub->col || ver->mx < 0 \
			|| ver->mx >= cub->row)
			ver->dof = 18;
		else if (ver->mp > 0 && ver->mp < cub->row * cub->col \
			&& cub->par.map[ver->my][ver->mx] == '1')
		{
			cub->p.f_ver = 1;
			ver->dof = 18;
		}
		else
		{
			ver->rx += ver->xo;
			ver->ry += ver->yo;
			ver->dof += 1;
		}
	}
}

void	init_ver(t_cub *cub, t_ver *ver, float ra)
{
	if (ra == (PI / 2) || ra == (3 * PI / 2))
	{
		ver->ry = cub->p.y;
		ver->rx = cub->p.x;
		if (ra == (PI / 2))
			ver->yo = -64;
		else
			ver->yo = 64;
		ver->xo = 0.0;
		ver->dof = 18;
	}
	else if (ra > (PI / 2) && ra < (3 * PI / 2))
	{
		ver->rx = (int)(cub->p.x) / 64 * 64 - 0.001;
		ver->ry = (cub->p.x - ver->rx) * ver->atan + cub->p.y;
		ver->xo = -64;
		ver->yo = -ver->xo * ver->atan;
	}
	else if (ra < (PI / 2) || ra > (3 * PI / 2))
	{
		ver->rx = (int)(cub->p.x / 64) * 64 + 64;
		ver->ry = (cub->p.x - ver->rx) * ver->atan + cub->p.y;
		ver->xo = 64;
		ver->yo = -ver->xo * ver->atan;
	}
}

void	ver_ray(t_cub *cub, float ra)
{
	t_ver	ver;

	cub->p.f_ver = 0;
	if (ra >= PI * 2)
		ra -= PI * 2;
	else if (ra <= 0)
		ra += PI * 2;
	ver.dof = 0;
	ver.atan = -tan(ra);
	ver.xo = 0.0;
	ver.yo = 0.0;
	init_ver(cub, &ver, ra);
	coor_vwall(&ver, cub, ra);
	cub->p.vx = ver.rx;
	cub->p.vy = ver.ry;
}
