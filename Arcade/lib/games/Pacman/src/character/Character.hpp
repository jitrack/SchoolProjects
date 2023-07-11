/*
** EPITECH PROJECT, 2021
** Character
** File description:
** Character
*/

#ifndef __CHARACTER__
#define __CHARACTER__

#include "../../../../../include/IGraphics.hpp"
#include "../../include/Include.hpp"
#include "../map/Map.hpp"
#include <chrono>

class Character {
public:
    explicit Character(Position &pos) noexcept : pos(pos), direction(Direction::unknown), offset(0, 0) {}
    virtual ~Character() noexcept = default;

    virtual void update(Map const &map) noexcept = 0;
    void move(Map const &map, float const speed = 0.4) noexcept;

    Position pos;
    Direction direction;
    Position offset;
};

class Player : public Character {
public:
    explicit Player(Position pos) noexcept;
    ~Player() noexcept = default;

    void update(Map const &map) noexcept final override;
};

class Mob : public Character {
public:
    explicit Mob(unsigned char const id, Position pos) noexcept;
    ~Mob() noexcept = default;
    enum class State{Spawning, Dead, Normal};

    void eated(Map const &map) noexcept;
    void collideWithPlayer() noexcept;
    void setFrightened() noexcept;
    bool isFrightened() const noexcept;
    bool isDead() const noexcept;
    void draw(IGraphicRender &renderer, Map const &map) const noexcept;
    void setDirection(Map const &map) noexcept;
    void update(Map const &map) noexcept final override;
    unsigned char getId() const noexcept { return _id; }
    Color const &getColor() const noexcept { return _color; }
private:

    Position _initialPos;
    Position _initialPosPercent;
    Vector2f _vector;
    std::chrono::time_point<std::chrono::system_clock> _startFrightened, _endFrightened;
    std::chrono::time_point<std::chrono::system_clock> _start, _end;
    std::chrono::duration<float> _duration;
    unsigned char const _id;
    Color const _color;
    State _state;
    bool _frightened;
};

#endif /* __CHARACTER__ */
