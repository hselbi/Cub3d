/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision_field.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hselbi <hselbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 00:47:47 by hselbi            #+#    #+#             */
/*   Updated: 2022/12/07 00:48:29 by hselbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	texel_coor(t_cub *cub, t_field *v_field)
{
	v_field->dist = v_field->i + (v_field->dist_plan / 2) - (cub->height / 2);
	v_field->ty = v_field->dist * (v_field->width_text / v_field->dist_plan);
	v_field->texel = 0;
	if (v_field->ty > v_field->width_text)
		v_field->ty = v_field->width_text;
	if (v_field->h == 1)
	{
		if (v_field->flag_h == 2)
			v_field->texel = cub->no[(v_field->width_text * \
				v_field->ty) + v_field->tx];
		else
			v_field->texel = cub->so[(v_field->width_text * \
				v_field->ty) + v_field->tx];
	}
	else
	{
		if (v_field->flag_v == 1)
			v_field->texel = cub->we[(v_field->width_text * \
				v_field->ty) + v_field->tx];
		else
			v_field->texel = cub->ea[(v_field->width_text * \
				v_field->ty) + v_field->tx];
	}
}

void	init_vfield(t_cub *cub, t_field *v_field, float ra)
{
	cub->p.dist = cub->p.dist * cos(ra - cub->p.p_angle);
	v_field->dist_plan = 64 * cub->height / cub->p.dist;
	cub->c_plan = cub->height / 2 - v_field->dist_plan / 2;
	cub->b_wall = cub->c_plan + v_field->dist_plan;
	cub->t_wall = cub->c_plan;
	if (cub->b_wall >= cub->height)
		cub->b_wall = cub->height;
	if (cub->t_wall < 0)
		cub->t_wall = 0;
	v_field->h = 0;
	v_field->width_text = 0;
	v_field->flag_v = -1;
	v_field->flag_h = -1;
}

void	h_vfield(t_cub *cub, t_field *v_field, float ra)
{
	v_field->h = 1;
	if (ra > PI && ra < 2 * PI)
	{
		v_field->width_text = cub->no_width;
		v_field->flag_h = 2;
	}
	else
	{
		v_field->width_text = cub->so_width;
		v_field->flag_h = 1;
	}
	v_field->tx = ((int)cub->p.hx % 64) * (v_field->width_text / 64);
}

void	v_vfield(t_cub *cub, t_field *v_field, float ra)
{
	if (ra > PI / 2 && ra < (3 * PI) / 2)
	{
		v_field->flag_v = 1;
		v_field->width_text = cub->we_width;
	}
	else
	{
		v_field->flag_v = 2;
		v_field->width_text = cub->ea_width;
	}
	v_field->tx = ((int)cub->p.vy % 64) * (v_field->width_text / 64);
}

void	v_field(t_cub *cub, int x, float ra)
{
	t_field	v_field;

	init_vfield(cub, &v_field, ra);
	if ((cub->p.f_hor == 1 && cub->p.hx == cub->p.rx))
	{
		h_vfield(cub, &v_field, ra);
	}
	else if ((cub->p.f_ver == 1 && cub->p.vy == cub->p.ry))
	{
		v_vfield(cub, &v_field, ra);
	}
	v_field.i = (int)cub->t_wall;
	v_field.j = (int)cub->b_wall;
	while (v_field.i < v_field.j)
	{
		if (v_field.tx > v_field.width_text)
			v_field.tx = v_field.width_text;
		texel_coor(cub, &v_field);
		cub->addr[cub->width * v_field.i + x] = v_field.texel;
		v_field.i++;
	}
}
