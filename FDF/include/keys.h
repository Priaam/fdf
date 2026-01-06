/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserre-s <priaserre@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:48:40 by pserre-s          #+#    #+#             */
/*   Updated: 2026/01/06 15:51:47 by pserre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# ifdef __linux__
#  include <X11/keysym.h>

#  define K_ESC		XK_Escape
#  define K_LEFT	XK_Left
#  define K_RIGHT	XK_Right
#  define K_UP		XK_Up
#  define K_DOWN	XK_Down
#  define K_A		XK_a
#  define K_D		XK_d

# else

#  define K_ESC		53
#  define K_LEFT	123
#  define K_RIGHT	124
#  define K_UP		126
#  define K_DOWN	125

# endif

#endif