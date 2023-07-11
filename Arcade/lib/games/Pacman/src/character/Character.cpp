/*
** EPITECH PROJECT, 2021
** Character
** File description:
** Character
*/

#include "Character.hpp"
#include <iostream>

static Color getNextColor()
{
    static int id = 0;

    ++id;
    if (id > 3)
        id = 0;
    switch(id) {
    case 0: return Color::Red();
    case 1: return Color::Blue();
    case 2: return Color::Pink();
    case 3: return Color::Orange();
    }
    return Color::Orange();
}

static Direction comeFrom(Direction const direction)
{
    switch(direction) {
    case Direction::up: return Direction::down;
    case Direction::down: return Direction::up;
    case Direction::right: return Direction::left;
    case Direction::left: return Direction::right;
    }
    return Direction::unknown;
}

void Character::move(Map const &map, float const speed) noexcept
{
    if (direction != Direction::unknown && !map.checkCollision(pos, offset, direction))
        switch(direction) {
        case Direction::up:
            if (offset.y > -map.cellSize) {
                offset.y -= speed;
            } else {
                offset.y = 0;
                if (pos.y > 0)
                    --pos.y;
                else
                    pos.y = map.size.y - 1;
            }
            break;
        case Direction::down:
            if (offset.y < map.cellSize - 1) {
                offset.y += speed;
            } else {
                offset.y = 0;
                if (pos.y < map.size.y - 1)
                    ++pos.y;
                else
                    pos.y = 0;
            }
            break;
        case Direction::left:
            if (offset.x > -map.cellSize + 1) {
                offset.x -= speed;
            } else {
                offset.x = 0;
                if (pos.x > 0)
                    --pos.x;
                else
                    pos.x = map.size.x - 1;
            }
            break;
        case Direction::right:
            if (offset.x < map.cellSize - 1) {
                offset.x += speed;
            } else {
                offset.x = 0;
                if (pos.x < map.size.x - 1)
                    ++pos.x;
                else
                    pos.x = 0;
            }
            break;
        }
}

Mob::Mob(unsigned char const id, Position pos) noexcept : Character(pos), _initialPos(pos), _initialPosPercent(0, 0), _vector(0, 0), _id(id), _color(getNextColor()), _state(State::Spawning)
{
    _start = std::chrono::system_clock::now();
}

void Mob::setDirection(Map const &map) noexcept
{
    Direction const comeFrom_ = comeFrom(direction);
    char i = 0;
    bool a = 0;

    while (++i < 8) {
        direction = (Direction)randBetween(0, 3);
        if (direction != comeFrom_ && !map.checkCollision(pos, offset, direction))
            return;
        if (direction == Direction::right)
            a = true;
    }
    if (a == false && !map.checkCollision(pos, offset, Direction::right))
        direction = Direction::right;
    else if (Direction::right != comeFrom_ && !map.checkCollision(pos, offset, Direction::right))
        direction = Direction::right;
    else if (Direction::up != comeFrom_ && !map.checkCollision(pos, offset, Direction::up))
        direction = Direction::up;
    else if (Direction::down != comeFrom_ && !map.checkCollision(pos, offset, Direction::down))
        direction = Direction::down;
    else if (Direction::left != comeFrom_ && !map.checkCollision(pos, offset, Direction::left))
        direction = Direction::left;
}

void Mob::setFrightened() noexcept
{
    _frightened = true;
    _startFrightened = std::chrono::system_clock::now();
}

bool Mob::isFrightened() const noexcept
{
    return _frightened;
}

bool Mob::isDead() const noexcept
{
    return _state == State::Dead;
}

void Mob::update(Map const &map) noexcept
{
    if (_frightened) {
        _endFrightened = std::chrono::system_clock::now();
        _duration = _endFrightened - _startFrightened;
        if (_duration.count() > 10)
            _frightened = false;
    }
    switch (_state) {
    case State::Spawning:
        _end = std::chrono::system_clock::now();
        _duration = _end - _start;
        if (_duration.count() > 10)
            _state = State::Normal;
        break;
    case State::Normal:
        setDirection(map);
        move(map, _frightened ? 0.25 : 0.4);
        break;
    case State::Dead:
        if ((pos.x < _initialPos.x && offset.x > _initialPosPercent.x) || (pos.x > _initialPos.x && offset.x < _initialPosPercent.x)) {
            _vector.x = 0;
            offset.x = _initialPosPercent.x;
        }
        if ((pos.y < _initialPos.y && offset.y > _initialPosPercent.y) || (pos.y > _initialPos.y && offset.y < _initialPosPercent.y)) {
            _vector.y = 0;
            offset.y = _initialPosPercent.y;
        }
        offset.x += _vector.x;
        offset.y += _vector.y;
        if (!_vector.y && !_vector.x) {
            _start = std::chrono::system_clock::now();
            _state = State::Spawning;
            pos = _initialPos;
            offset = Position(0, 0);
        }
        break;
    }
}

void Mob::draw(IGraphicRender &renderer, Map const &map) const noexcept
{
    switch(_state) {
    case State::Dead:
        renderer.drawRect(Rect(Position(offset.x + map.halfCellSize - 2, offset.y + map.halfCellSize), Size(map.cellSize / 4, map.cellSize / 4), Color::Grey()));
        renderer.drawRect(Rect(Position(offset.x + map.halfCellSize + 2, offset.y + map.halfCellSize), Size(map.cellSize / 4, map.cellSize / 4), Color::Grey()));
        break;
    default:
        renderer.drawCircle(Circle( Position(pos.x * map.cellSize + (float)map.halfCellSize + offset.x, pos.y * map.cellSize + (float)map.halfCellSize + offset.y), 1, _frightened ? Color::Grey() : _color));
        break;
    }
}

void Mob::eated(Map const &map) noexcept
{
    _state = State::Dead;
    _initialPosPercent = Position(_initialPos.x * map.cellSize, _initialPos.y * map.cellSize);
    _vector = Vector2f(pos.x == _initialPos.x ? 0 : pos.x < _initialPos.x ? 0.4 : -0.4, pos.y == _initialPos.y ? 0 : pos.y < _initialPos.y ? 0.4 : -0.4);
    offset = Position(pos.x * map.cellSize, pos.y * map.cellSize);
}

Player::Player(Position pos) noexcept : Character(pos)
{}

void Player::update(Map const &map) noexcept
{
    move(map);
}
