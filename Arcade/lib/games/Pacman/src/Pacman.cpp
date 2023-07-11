/*
** EPITECH PROJECT, 2021
** Pacman
** File description:
** Pacman
*/

#include "./Pacman.hpp"
#include "../include/Include.hpp"

#include <iostream>
#include <chrono>

EXTERN_CLASS_IN_C(Pacman, game)

#define SET_PLAYER_DIRECTION(dir) setPlayerDirection(*_player, _map, dir)
#define MAP1 "./maps/Pacman/map1.map"

static void setPlayerDirection(Player &player, Map const &map, Direction const direction)
{
    player.direction = map.checkCollision(player.pos, player.offset, direction) ? player.direction : direction;
}

void Pacman::loadMap(std::string const &path) noexcept
{
    _start = std::chrono::system_clock::now();
    if (_player)
        delete _player;
    _player = nullptr;
    _mobs.clear();
    _pacgums.clear();
    _map.loadMapFromPath(MAP1);
    _map.nbPacgums = 0;
    _totalPacgums = 0;
    _score = 0;
    if (_map.isEmpty())
        exit(84);
    unsigned char nb_mobs = 0;

    for (unsigned int y = 0; y < _map.size.y; ++y) {
        for (unsigned int x = 0; _map[y][x]; ++x) {
            switch(_map[y][x]) {
            case '\n': ++y; break;
            case MOB:
                _mobs.push_back(Mob(nb_mobs, Position(x, y)));
                ++nb_mobs;
                _map[y][x] = ' ';
                break;
            case PLAYER:
                if (_player) {
                    std::cerr << "Error: Pacman map must contain only one player" << std::endl;
                    exit(84);
                }
                _player = new Player(Position(x, y));
                _map[y][x] = ' ';
                break;
            case PACGUM:
                ++_totalPacgums;
                _pacgums.push_back(Pacgum(Position(x, y)));
                ++_map.nbPacgums;
                break;
            case POINT:
                ++_map.nbPacgums;
                break;
            }
        }
    }
}

Pacman::Pacman() : IGame(), _player(nullptr)
{
    loadMap(MAP1);
}

Pacman::~Pacman() noexcept
{
    if (_player)
        delete _player;
}

void Pacman::event(Event const event)
{
    switch(event) {
    case Event::up: SET_PLAYER_DIRECTION(Direction::up); break;
    case Event::left: SET_PLAYER_DIRECTION(Direction::left); break;
    case Event::right: SET_PLAYER_DIRECTION(Direction::right); break;
    case Event::down: SET_PLAYER_DIRECTION(Direction::down); break;
    }
}

void Pacman::update(int elapsedTime)
{
    _end = std::chrono::system_clock::now();
    _duration = _end - _start;
    if (_duration.count() > 0.02) {
        _start = std::chrono::system_clock::now();

        //update player
        _player->update(_map);
        if (_map[_player->pos.y][_player->pos.x] == PACGUM) {
            for (Mob &mob : _mobs)
                mob.setFrightened();
        }
        if (_map[_player->pos.y][_player->pos.x] == POINT || _map[_player->pos.y][_player->pos.x] == PACGUM)
            --_map.nbPacgums;
        if (!_map.nbPacgums)
            loadMap(MAP1);
        _map[_player->pos.y][_player->pos.x] = ' ';

        //update all mobs
        for (Mob &mob : _mobs) {
            mob.update(_map);
            if (_player->pos.x == mob.pos.x && _player->pos.y == mob.pos.y && !mob.isDead()) {
                if (mob.isFrightened()) {
                    _score += 100;
                    mob.eated(_map);
                } else {
                    loadMap(MAP1);
                }
            }
        }
    }
}

void Pacman::render(IGraphicRender &renderer) const
{
    Rect rect(Position(0, 0), Size(_map.cellSize, _map.cellSize), Color::White());

    for (unsigned int y = 0; y < _map.size.y; ++y) {
        rect.pos.x = 0;
        for (unsigned int x = 0; _map[y][x]; ++x) {
            switch(_map[y][x]) {
            case WALL:
                rect.color = Color::Blue();
                renderer.drawRect(rect);
                break;
            case POINT:
                renderer.drawCircle(Circle(Position(rect.pos.x + _map.halfCellSize, rect.pos.y + _map.halfCellSize), 0.5, Color::White()));
                break;
            case EMPTY: break;
            case PACGUM:
                renderer.drawCircle(Circle(Position(rect.pos.x + _map.halfCellSize, rect.pos.y + _map.halfCellSize), 1.2, Color::White()));
                break;
            }
            rect.pos.x += _map.cellSize;
        }
        rect.pos.y += _map.cellSize;
    }
    for (Mob const &mob : _mobs) {
        mob.draw(renderer, _map);
    }
    renderer.drawCircle(Circle(GET_CICRLE_CENTER(_player->pos, _player->offset), 2, Color::Yellow()));
}

const std::string Pacman::getScore()
{
    return std::to_string(_score + (_totalPacgums - _pacgums.size()) * 10);
}
