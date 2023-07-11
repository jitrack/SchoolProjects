/*
** EPITECH PROJECT, 2021
** Pacman
** File description:
** Pacman
*/

#ifndef __NIBBLER__
#define __NIBBLER__

#include "../../../../include/IGame.hpp"
#include "../../../../include/IGraphics.hpp"

#include <vector>

class Character {
public:
    explicit Character(Position &pos) noexcept : pos(pos) {}
    ~Character() noexcept = default;

    Position pos;
};

class Player : Character {
public:
    explicit Player(Position pos) noexcept : Character(pos) {}
    ~Player() noexcept;
};

class Mob : Character {
public:
    explicit Mob(unsigned char const id, Position pos, Color const color) noexcept : Character(pos), _id(id), _color(color) {}
    ~Mob() noexcept;
    unsigned char getId() const noexcept { return _id; }
    Color const &getColor() const noexcept { return _color; }
private:
    unsigned char const _id;
    Color const _color;
};

class Nibbler : public IGame {
public:
    explicit Nibbler();
    void event(Event const Event) final override;
    void update(int elapsedTime) final override;
    void render(IGraphicRender &renderer) const final override;
    const std::string getScore() final override;

    void drawMap(IGraphicRender &renderer) const noexcept;
private:
    std::vector<Rect> _player;
    std::vector<std::string> _map;
};

#endif /* __PACMAN__ */
