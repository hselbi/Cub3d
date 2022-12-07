/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:31:26 by adbaich           #+#    #+#             */
/*   Updated: 2022/11/28 20:34:20 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_pars.h"
#include "libft/libft.h"

int	check_id_helper4(int **txt_index, char *id)
{
	if (!ft_strncmp(id, "WE", 3))
	{
		if (txt_index[0][WE])
			ft_error();
		txt_index[0][WE] = 1;
		return (2);
	}
	else if (!ft_strncmp(id, "EA", 3))
	{
		if (txt_index[0][EA])
			ft_error();
		txt_index[0][EA] = 1;
		return (3);
	}
	return (-1);
}

int	check_id_helper3(int **txt_index, char *id)
{
	if (!ft_strncmp(id, "NO", 3))
	{
		if (txt_index[0][NO])
			ft_error();
		txt_index[0][NO] = 1;
		return (0);
	}
	else if (!ft_strncmp(id, "SO", 3))
	{
		if (txt_index[0][SO])
			ft_error();
		txt_index[0][SO] = 1;
		return (1);
	}
	return (-1);
}

int	check_id_helper2(int **txt_index, char *id, char *str)
{
	int	retrn;

	retrn = -1;
	fill_id(id, str, 3);
	retrn = check_id_helper3(txt_index, id);
	if (retrn != -1)
		return (retrn);
	retrn = check_id_helper4(txt_index, id);
	return (retrn);
}

int	check_id_helper1(int **txt_index, char *id, char *str)
{
	fill_id(id, str, 2);
	if (!ft_strncmp(id, "F", 2))
	{
		if (txt_index[0][F])
			ft_error();
		txt_index[0][F] = 1;
		return (4);
	}
	else if (!ft_strncmp(id, "C", 2))
	{
		if (txt_index[0][C])
			ft_error();
		txt_index[0][C] = 1;
		return (5);
	}
	return (-1);
}

int	check_id(char *str, int **txt_index)
{
	char	id[3];
	int		i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
		i++;
	if (i == 1)
		return (check_id_helper1(txt_index, id, str));
	else if (i == 2)
		return (check_id_helper2(txt_index, id, str));
	return (-1);
}
