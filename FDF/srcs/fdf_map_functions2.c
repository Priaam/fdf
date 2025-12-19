/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_functions2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserre-s <priaserre@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:15:56 by pserre-s          #+#    #+#             */
/*   Updated: 2025/12/19 20:27:36 by pserre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_allocate_matrix(t_var *vars)
{
	int		y;
	t_point	*data;

	vars->map.points_matrix = malloc(vars->map.height * sizeof(t_point *));
	if (!vars->map.points_matrix)
		exit(EXIT_FAILURE);
	data = malloc(vars->map.height * vars->map.width * sizeof(t_point));
	if (!data)
	{
		free(vars->map.points_matrix);
		exit(EXIT_FAILURE);
	}
	y = 0;
	while (y < vars->map.height)
	{
		vars->map.points_matrix[y] = data + y * vars->map.width;
		y++;
	}
}

void	fdf_get_map_value(t_var *vars, int fd)
{
	int		y;
	int		x;
	char	*line;
	char	**values;

	y = 0;
	while (y < vars->map.height)
	{
		line = get_next_line(fd);
		if (!line)
			fdf_error_exit("Erreur: Probleme lors de la deuxieme lecture.");
		values = ft_split(line, ' ');
		x = 0;
		while (values[x] && x < vars->map.width)
		{
			vars->map.points_matrix[y][x].color = fdf_get_color(values[x]);
			vars->map.points_matrix[y][x].x = x;
			vars->map.points_matrix[y][x].y = y;
			vars->map.points_matrix[y][x].z = ft_atoi(values[x]);
			x++;
		}
		ft_free_split(values);
		free(line);
		y++;
	}
}

