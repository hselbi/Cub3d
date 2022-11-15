/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hselbi <hselbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:45:28 by adbaich           #+#    #+#             */
/*   Updated: 2022/11/15 15:16:09 by hselbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include "cub3d_pars.h"

void	ft_error(void)
{
	write(2, "Error\nInvalid Map !\n", ft_strlen("Error\nInvalid Map !\n"));
	exit(1);
}

size_t	max_len(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s1_len > s2_len)
		return (s1_len);
	return (s2_len);
}

int	check_ext(char *file)
{
	char	*str;
	str = ft_strrchr(file, '.');
	if (str && !ft_strncmp(str, ".cub", max_len(str, ".cub")))
		return (0);
	return (1);
}

void	fill_id(char *id, char *str, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		id[i] = str[i];
		i++;
	}
	id[len - 1] = '\0';
}

int	check_id_helper2(int **txt_index, char *id, char *str)
{
	fill_id(id, str, 3);
	if (!ft_strncmp(id, "NO", 3))
	{
		if (txt_index[0][NO])
		{
			printf("here is 1 because index == %d\n", txt_index[0][NO]);
			ft_error();
		}
		txt_index[0][NO] = 1;
		return (0);
	}
	else if (!ft_strncmp(id, "SO", 3))
	{
		if (txt_index[0][SO])
		{
			printf("here is 2\n");
			ft_error();
		}
		txt_index[0][SO] = 1;
		return (1);
	}
	else if (!ft_strncmp(id, "WE", 3))
	{
		if (txt_index[0][WE])
		{
			printf("here is 3\n");
			ft_error();
		}
		txt_index[0][WE] = 1;
		return (2);
	}
	else if (!ft_strncmp(id, "EA", 3))
	{
		if (txt_index[0][EA])
		{
			printf("here is 4\n");
			ft_error();
		}
		txt_index[0][EA] = 1;
		return (3);
	}
	return (-1);
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
	int	i;
	char	id[3];

	i = 0;
	// printf("str to test \'  %s  \'\n", str);
	while (str[i] && str[i] != ' ' && str[i] != '\t')
		i++;
	// printf("i ==  %d\n", i);
	if (i == 1)
		return (check_id_helper1(txt_index, id, str));
	else if (i == 2)
		return (check_id_helper2(txt_index, id, str));
	return (-1);
}

void	fill_path(char *str, char *path, int i)
{
	int	j;

	j = 0;
	while (str[i])
	{
		path[j] = str[i];
		j++;
		i++;
	}
	path[j] = '\0';
}

char	*get_path(char *str)
{
	int		i;
	int		len;
	char	*path;

	i = 0;
	while (str[i] != ' ' && str[i] != '\t')
		i++;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	len = ft_strlen(str) - i;
	path = malloc(sizeof(char) * len + 1);
	if (!path)
		return (NULL);
	fill_path(str, path, i);
	return (path);
}

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

void	valid_members(char *path)
{
	int	i;

	i = 0;
	while (path[i] && ((path[i] >= '0' && path[i] <= '9') || path[i] == ','))
		i++;
	if (path[i])
		ft_error();
}

void	before_after_comma(char *path)
{
	int	i;

	i = 0;
	if (path[i] == ',' || path[ft_strlen(path) - 1] == ',')
		ft_error();
	while (path[i])
	{
		if (path[i] == ',' && (!ft_isdigit(path[i-1]) || !ft_isdigit(path[i+1])))
			ft_error();
		i++;
	}
}

void	num_of_commas(char *path)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (path[i])
	{
		if (path[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		ft_error();
}

void	valid_path_rgb(char *path)
{
	valid_members(path);
	num_of_commas(path);
	before_after_comma(path);
}

void	len_of_num(char *num)
{
	int		i;

	i = 0;
	while(num[i])
	{
		if (num[i] != '0')
			break;
		i++;
	}
	if (ft_strlen(num) - i > 3)
		ft_error();
}

void	valid_color_range(int *arr)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (arr[i] < 0 || arr[i] > 255)
			ft_error();
		i++;
	}
}

void	get_color(char *path, t_txt *toto, int id_index)
{
	char	**colors;
	int		i;

	colors = ft_split(path, ',');
	i = 0;
	while (colors[i])
		len_of_num(colors[i++]);
	i = -1;
	if (id_index == 4)
	{
		while (colors[++i])
			toto->color[0][i] = ft_atoi(colors[i]);
		valid_color_range(toto->color[0]);
	}
	else if (id_index == 5)
	{
		while (colors[++i])
			toto->color[1][i] = ft_atoi(colors[i]);
		valid_color_range(toto->color[1]);
	}
}

void	fill_RGB(char *str, t_txt *toto, int id_index)
{
	char	*rgb_txt;

	rgb_txt = get_path(str);
	valid_path_rgb(rgb_txt);
	get_color(rgb_txt, toto, id_index);
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

void	fill_map(char *line, t_txt *toto)
{
	static int	empty_line_in_map;
	char		*tmp;
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
			|| line[i] == '\t') || player_position(line[i], toto) || line[i] == '\n'))
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
		{
			empty_line_in_map++;
			count++;
		}
		i++;
	}
	if (line[i] || !count)
		ft_error();
	if (count)
	{
		tmp = toto->mini_map;
		toto->mini_map = ft_strjoin(toto->mini_map, line);
		free(tmp);
	}
}

size_t	ft_strlen_2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	first_last_line(char *str)
{
	int	i;

	i= 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '1')
			ft_error();
		i++;
	}
}

int	included(char *str, char c)
{
	while(*str) {
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

void	valid_map(char **map)
{
	int	i;
	int	j;

	i = 1;
	first_last_line(map[0]);
	first_last_line(map[ft_strlen_2d(map) - 1]);
	while (i < (int)ft_strlen_2d(map) - 1)
	{
		j = 0;
		while (map[i][j])
		{
			if (included("NSWE0", map[i][j]))
			{
				// printf("i am here\n");
				if (j)
				{
					if (map[i][j + 1] == ' ' || map[i][j + 1] == '\t')
						ft_error();
					else if (map[i][j - 1] == ' ' || map[i][j - 1] == '\t')
						ft_error();
				}
				if (i)
				{
					if (map[i + 1][j] == ' ' || map[i + 1][j] == '\t')
						ft_error();
					else if (map[i - 1][j] == ' ' || map[i - 1][j] == '\t')
						ft_error();
				}
			}
			j++;
		}
		i++;
	}
}

t_txt	fill_struct(int fd)
{
	t_txt	toto;
	char	*line;
	int		*txt_index;
	int		id_index;

	txt_index = malloc(sizeof(int) * 6);
	toto.mini_map = malloc(sizeof(char) * 1);
	toto.mini_map[0] = '\0';
	toto.position = 0;
	ft_bzero(txt_index, (6 * sizeof(int)));
	toto.map = malloc(sizeof(char *) * 2);
	line = get_next_line(fd);
	while (line)
	{
		if (!strat_map(txt_index))
		{
			if (line[ft_strlen(line) - 1] == '\n')
				line[ft_strlen(line) - 1] = '\0';
			id_index = check_id(line, &txt_index);
			if (id_index >= 0 && id_index <= 3)
			{
				if (!check_path(line))
					toto.text[id_index] = get_path(line);
				else
					ft_error();
			}
			else if (id_index >= 4)
			{
				if (!check_path(line))
					fill_RGB(line, &toto, id_index);
			}
		}
		else
			fill_map(line, &toto);
		free(line);
		line = get_next_line(fd);
	}
	if (!toto.position)
		ft_error();
	toto.map = ft_split(toto.mini_map, '\n');
	valid_map(toto.map);
	return (toto);
}

int	open_fd(char *file)
{
	int	fd;

	if (check_ext(file))
		ft_error();
	fd = open(file, O_RDONLY, 0422);
	if (fd == -1)
		ft_error();
	return (fd);
}		

void	print_infos(t_txt toto)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
		printf("==>  %s\n", toto.text[i]);
	i = -1;
	while (++i < 2)
	{
		j = -1;
		while (++j < 3)
			printf(" %d ", toto.color[i][j]);
		printf("\n");
	}
	i = -1;
	while (toto.map[++i])
		printf("map ==> %s\n", toto.map[i]);
}

// int	main(int ac, char **av)
// {
// 	if (ac == 2)
// 	{
// 		int		fd;
// 		t_txt	toto;

// 		fd = open_fd(av[1]);
// 		toto = fill_struct(fd);
// 		print_infos(toto);
// 	}
// 	return (0);
// }