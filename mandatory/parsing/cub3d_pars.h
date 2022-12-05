/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_pars.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hselbi <hselbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:40:24 by adbaich           #+#    #+#             */
/*   Updated: 2022/12/03 19:08:08 by hselbi           ###   ########.fr       */
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

t_txt	fill_struct(int fd);
void	valid_map(char **map);
int		included(char *str, char c);
void	first_last_line(char *str);
size_t	ft_strlen_2d(char **str);
void	fill_map(char *line, t_txt *toto);
int		player_position(char c, t_txt *toto);
int		strat_map(int *txt_index);
void	fill_RGB(char *str, t_txt *toto, int id_index);
void	get_color(char *path, t_txt *toto, int id_index);
void	valid_color_range(int *arr);
void	len_of_num(char *num);
void	valid_path_rgb(char *path);

int		open_fd(char *file);
void	print_infos(t_txt toto);

#endif