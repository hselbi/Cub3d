/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_pars.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:40:24 by adbaich           #+#    #+#             */
/*   Updated: 2022/12/08 15:45:13 by adbaich          ###   ########.fr       */
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
	int		*txt_index;
	int		position;
	int		color[2][3];
	char	**map;
	char	*mini_map;
}	t_txt;

int		check_id(char *str, int **txt_index);
void	ft_error(void);
void	fill_id(char *id, char *str, int len);
void	valid_path_rgb(char *path);
void	get_color(char *path, t_txt *toto, int id_index);
void	ft_error(void);
size_t	max_len(char *s1, char *s2);
void	fill_id(char *id, char *str, int len);
char	*fill_path(char *str, char *path, int i);
int		check_ext(char *file);
int		check_path(char *str);
int		strat_map(int *txt_index);
int		player_position(char c, t_txt *toto);
void	fill_map_helper(char *line, t_txt *toto, int i, int count);
size_t	ft_strlen_2d(char **str);
void	first_last_line(char *str);
int		included(char *str, char c);
void	fill_struct_end(t_txt *toto);
void	fill_struct_body(t_txt *toto, int fd);
t_txt	fill_struct(int fd);
char	*get_path(char *str);
void	fill_rgb(char *str, t_txt *toto, int id_index);
int		open_fd(char *file);

#endif