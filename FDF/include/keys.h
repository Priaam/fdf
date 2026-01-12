/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserre-s <priaserre@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:48:40 by pserre-s          #+#    #+#             */
/*   Updated: 2026/01/12 01:54:56 by pserre-s         ###   ########.fr       */
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
#  define K_W		XK_w
#  define K_S		XK_s
#  define K_Q		XK_q
#  define K_E		XK_e
#  define K_8		65431
#  define K_2		65433

# else

#  define K_ESC		53
#  define K_LEFT	123
#  define K_RIGHT	124
#  define K_UP		126
#  define K_DOWN	125
#  define K_A		0
#  define K_D		2
#  define K_W		13
#  define K_S		1
#  define K_Q		12
#  define K_E		14
#  define K_8		91
#  define K_2		84

# endif

#endif