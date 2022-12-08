/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:19:10 by adbaich           #+#    #+#             */
/*   Updated: 2022/12/05 19:19:51 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include "cub3d_pars.h"

void	fill_struct_init(t_txt *toto)
{
	toto->txt_index = malloc(sizeof(int) * 6);
	toto->mini_map = malloc(sizeof(char) * 1);
	toto->mini_map[0] = '\0';
	toto->position = 0;
	ft_bzero(toto->txt_index, (6 * sizeof(int)));
}

t_txt	fill_struct(int fd)
{
	t_txt	toto;

	fill_struct_init(&toto);
	fill_struct_body(&toto, fd);
	fill_struct_end(&toto);
	return (toto);
}
