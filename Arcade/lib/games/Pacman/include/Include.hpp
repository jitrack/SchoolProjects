/*
** EPITECH PROJECT, 2021
** Include
** File description:
** Include
*/

#ifndef __INCLUDE__
#define __INCLUDE__

enum class Direction {unknown = -1, up, down, left, right};

#define WALL '#'
#define POINT '.'
#define MOB 'm'
#define PLAYER 'o'
#define EMPTY ' '
#define PACGUM 'p'

#define GET_CICRLE_CENTER(pos, offset) Position(pos.x * _map.cellSize + (float)_map.halfCellSize + offset.x, pos.y * _map.cellSize + (float)_map.halfCellSize + offset.y)

#endif /* __INCLUDE__ */
