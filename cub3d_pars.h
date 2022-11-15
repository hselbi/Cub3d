/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_pars.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:40:24 by adbaich           #+#    #+#             */
/*   Updated: 2022/11/05 15:43:15 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PARS_H
# define CUB3D_PARS_H
# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define F 4
# define C 5
# include <fcntl.h>

typedef struct texture
{
	char	*text[4];
	int		position;
	int		color[2][3];
	char	**map;
	char	*mini_map;
}	t_txt;

#endif