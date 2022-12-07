/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct_body.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:15:37 by adbaich           #+#    #+#             */
/*   Updated: 2022/12/05 19:17:50 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include "cub3d_pars.h"

void	fill_map(char *line, t_txt *toto)
{
	static int	empty_line_in_map;
	int			count;
	int			i;

	i = 0;
	count = 0;
	if (line[i] == '\n' && !empty_line_in_map)
	{
		count++;
		i++;
	}
	while (line[i] && ((line[i] == '0' || line[i] == '1' || line[i] == ' '
				|| line[i] == '\t') || player_position(line[i], toto)
			|| line[i] == '\n'))
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
		{
			empty_line_in_map++;
			count++;
		}
		i++;
	}
	fill_map_helper(line, toto, i, count);
}

void	fill_struct_body_helper(t_txt *toto, char *line)
{
	int		id_index;

	id_index = check_id(line, &toto->txt_index);
	if (id_index >= 0 && id_index <= 3)
	{
		if (!check_path(line))
			toto->text[id_index] = get_path(line);
		else
			ft_error();
	}
	else if (id_index >= 4)
	{
		if (check_path(line))
			ft_error();
		fill_rgb(line, toto, id_index);
	}
}

void	fill_struct_body(t_txt *toto, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (!strat_map(toto->txt_index))
		{
			if (line[ft_strlen(line) - 1] == '\n')
				line[ft_strlen(line) - 1] = '\0';
			fill_struct_body_helper(toto, line);
		}
		else
			fill_map(line, toto);
		free(line);
		line = get_next_line(fd);
	}
}
