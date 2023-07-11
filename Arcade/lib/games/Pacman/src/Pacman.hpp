/*
** EPITECH PROJECT, 2021
** Pacman
** File description:
** Pacman
*/

#ifndef __PACMAN__
#define __PACMAN__

#include "../../../../include/IGame.hpp"
#include "../../../../include/IGraphics.hpp"
#include "./map/Map.hpp"
#include "./character/Character.hpp"

#include <vector>
#include <chrono>

struct Pacgum {
public:
    explicit Pacgum(Position const &pos_) noexcept : pos(pos_) {}
    ~Pacgum() noexcept = default;

    Position const pos;
};

class Pacman : public IGame {
public:
    explicit Pacman();
    ~Pacman() noexcept;

    void loadMap(std::string const &path) noexcept;
    void event(Event const Event) final override;
    void update(int elapsedTime) final override;
    void render(IGraphicRender &renderer) const final override;
    const std::string getScore() final override;
private:
    unsigned int _score;
    Player *_player;
    std::vector<Mob> _mobs;
    std::vector<Pacgum> _pacgums;
    unsigned int _totalPacgums;
    Map _map;
    std::chrono::time_point<std::chrono::system_clock> _start, _end;
    std::chrono::duration<float> _duration;
};

#endif /* __PACMAN__ */
