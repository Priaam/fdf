/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserre-s <priaserre@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 20:01:18 by pserre-s          #+#    #+#             */
/*   Updated: 2025/12/17 19:01:00 by pserre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	fdf_count_map_width(char *line)
{
	char	**splitted_line;
	int		width;

	if (!line || !*line || fdf_is_line_empty(line))
		fdf_error_exit("Erreur: Ligne vide dans la map.");
	splitted_line = ft_split(line, ' ');
	width = 0;
	while (splitted_line[width])
		width++;
	ft_free_split(splitted_line);
	return (width);
}

static void	fdf_check_map_width(t_var *vars, int width, int line_count)
{
	if (line_count == 0)
		vars->map.width = width;
	else if (width != vars->map.width)
		fdf_error_exit("Erreur: La map n'est pas rectangulaire.");
}

static void	fdf_get_map_dimension(t_var *vars, int fd)
{
	char	*line;
	int		line_count;
	int		width;

	line_count = 0;
	line = get_next_line(fd);
	while (line)
	{
		width = fdf_count_map_width(line);
		fdf_check_map_width(vars, width, line_count);
		free(line);
		line = get_next_line(fd);
		line_count++;
	}
	if (line_count == 0)
		fdf_error_exit("Erreur: map vide.");
	vars->map.height = line_count;
}

// void	fill_map_matrix(const char *map_file, t_var *vars)
// {
// 	int	y;
// 	int	fd;

// 	vars->map.altitude_matrix = (int **)malloc(vars->map.height
// 			* sizeof(int *));
// 	if (!vars->map.altitude_matrix)
// 		return ;
// 	y = 0;
// 	while (y < vars->map.height)
// 	{
// 		vars->map.altitude_matrix[y] = (int *)malloc(vars->map.width
// 				* sizeof(int));
// 		if (!vars->map.width)
// 		{
// 			return ;
// 		}
// 		y++;
// 	}
// }

void	fdf_fill_map_matrix(t_var *vars, int fd)
{
	fdf_allocate_matrix(vars);
	fdf_get_map_value(vars, fd);
}

void	parsing_map(const char *map, t_var *vars)
{
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		fdf_error_exit("L'ouverture de la map a echoué.");
	fdf_get_map_dimension(vars, fd);
	close(fd);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		fdf_error_exit("La réouverture de la map a échoué.");
	fdf_fill_map_matrix(vars, fd);
	close(fd);
	ft_printf("%d : %d", vars->map.width, vars->map.height);
}
