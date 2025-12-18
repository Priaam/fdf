/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserre-s <priaserre@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 02:43:45 by pserre-s          #+#    #+#             */
/*   Updated: 2025/12/18 13:12:27 by pserre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <fcntl.h>
# include <mlx.h>
# include "keys.h"
# include <stdio.h>
# include <math.h>

# define X_LEN 1920
# define Y_LEN 1080

# define DEFAULT_COLOR 0xFFFFFF
# define DEFAULT_ZOOM 100

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_point
{
	int		x;
	int		y;
	int		z;

	int		color;

	double	x_proj;
	double	y_proj;
}	t_point;

typedef struct s_map
{
	t_point	**points_matrix;
	int		width;
	int		height;
}	t_map;

typedef struct s_var
{
	void	*mlx;
	void	*window;

	double	zoom;
	int		x_offset;
	int		y_offset;

	double	z_scale;
	double	angle_x;
	double	angle_y;

	t_img	img;
	t_map	map;
}	t_var;

// Fonctions MLX
void	my_pixel_put(t_img *data, int x, int y, int color);
int		close_window(t_var *vars);
int		fun(int key, t_var *data);
void	setup_hooks(t_var *vars);

// Parsing de la map
void	parsing_map(const char *map, t_var *vars);
void	fdf_allocate_matrix(t_var *vars);
void	fdf_get_map_value(t_var *vars, int fd);

// Fonctions utiles
void	fdf_error_exit(char *msg);
int		fdf_is_line_empty(char *line);
int		fdf_get_color(char *s);
int		fdf_check_extension(const char *filename);

// Dessiner la map
void	init_variables(t_var *vars);

#endif