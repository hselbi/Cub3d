/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:04:17 by adbaich           #+#    #+#             */
/*   Updated: 2022/12/08 15:15:20 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include "cub3d_pars.h"

int	check_path(char *str)
{
	int	i;

	i = 0;
	while (str[i] != ' ' && str[i] != '\t')
		i++;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] == '\0')
		return (1);
	while (str[i] && (str[i] != ' ' && str[i] != '\t'))
		i++;
	if (str[i])
		return (1);
	return (0);
}

int	strat_map(int *txt_index)
{
	int	i;

	i = 0;
	while (i < 6 && txt_index[i])
		i++;
	if (i == 6)
		return (1);
	return (0);
}

int	player_position(char c, t_txt *toto)
{
	if ((c == 'N' || c == 'S' || c == 'W' || c == 'E') && !toto->position)
	{
		toto->position = 1;
		return (1);
	}
	return (0);
}

void	fill_map_helper(char *line, t_txt *toto, int i, int count)
{
	char	*tmp;

	if (line[i] || !count)
		ft_error();
	tmp = toto->mini_map;
	toto->mini_map = ft_strjoin(toto->mini_map, line);
	free(tmp);
}
