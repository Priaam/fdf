/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserre-s <priaserre@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 02:02:23 by pserre-s          #+#    #+#             */
/*   Updated: 2026/01/12 02:03:15 by pserre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_key_press(int key, t_var *vars)
{
	if (key < 65536)
		vars->keys[key] = 1;
	return (0);
}

int	fdf_key_release(int key, t_var *vars)
{
	if (key < 65536)
		vars->keys[key] = 0;
	return (0);
}
