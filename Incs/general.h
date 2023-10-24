/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:49:01 by tgellon           #+#    #+#             */
/*   Updated: 2023/10/11 16:49:01 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_H
# define GENERAL_H

// Keycodes
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define E 101
# define PLUS 65451
# define MINUS 65453
# define LEFT 65361
# define RIGHT 65363
# define Z 122
# define X 120
# define RED_CROSS 33

// Colors
# define GREEN 0x0000FF00
# define RED 0x00FF0000
# define BLUE 0x000000FF
# define BLACK 0x00000000
# define WHITE 0x00FFFFFF
# define TRANS 0xFF000000
# define BROWN 0x000F4A460
# define LICORICE 0x001B1212
# define GREYB 0x00373737
# define GREYW 0x009c9c9c

// data info
# define VIEW_DIST 400
# define SQUARE_SIZE 15
# define DOOR_OPEN_DST 1500
# define SQ_NUM 12
# define WIN_WIDTH 1440
# define WIN_HEIGHT 720
# define FOV 60
# define RAY_NUMBER WIN_WIDTH
# define MOVE_SPEED 0.4
# define ANGLE_MOVE 0.01

// strings
# define COLOR_CHAR "ErrorWrong char in array (%c b), must be only digits\n"
# define COLOR_NBR "Error\nWrong color numbers, must be 3 colors x,y,z\n"
# define COLOR_VAL "Error\nWrong color value (%d), must be between 0 and 255 \
included\n"
# define LESS_ELEM "Error\nNot all configuration elements are present before \
the map\nYou must have NO, SO, EA, WE, F and C\n"
# define MORE_ELEM "Error\nToo much elements before the map, must be only NO, \
SO, EA, WE, F and C, one of each\n"
# define WALLS_ERR "Error\nThe map must be surrounded by walls\n"
# define WALLS_ALONE "Error\nThere is a wall outside the map\n"
# define WRONG_CHAR "Error\nWrong char in map, must be 0, 1, N, S, E, W, \
or a whitespace\n"
# define MORE_DIRECTION "Error\nThere must be only one player direction\n"
# define LESS_DIRECTION "Error\nThere must be a player direction (N,S,E or W)\n"
# define DIRECTION_OUT "Error\nThe player is not inside the map\n"
# define XPM_OPEN_ERR "Error\nProblem opening the xpm texture\n"
# define INVALID_DOOR "Error\nDoor must be places between two walls\n"

#endif
