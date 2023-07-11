/*
** EPITECH PROJECT, 2021
** Pacman
** File description:
** Pacman
*/

#include "./Nibbler.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

EXTERN_CLASS_IN_C(Nibbler, game)

static void drawPlayer(std::vector<Rect> const *player, IGraphicRender &renderer)
{
    for (Rect const &it : *player) {
        renderer.drawRect(it);
    }
}

static void playerInit(std::vector<Rect> *player, Position pos)
{
    for (int i = 0; i != 4; i++) {
        player->push_back(Rect(Position(pos.x - (1 * i) + 0.1, pos.y + 0.1), Size(80, 80), Color::Red()));
    }
}

static std::vector<std::string> readfile(std::string const &path)
{
    std::ifstream file(path);

    if (!file || !file.is_open())
        return std::vector<std::string>();
    std::vector<std::string> content;
    std::string line;
    while(getline(file, line))
        content.push_back(line);
    file.close();
    return content;
}

static std::vector<std::string> getMapFromPath(std::string const &path)
{
    size_t dot = path.find_last_of('.');

    if (dot != std::string::npos && !path.compare(dot, std::string::npos, ".map"))
        return readfile(path);
    return std::vector<std::string>();
}

Nibbler::Nibbler() : IGame(), _map(getMapFromPath("./maps/Nibbler/map1.map"))
{

    if (_map.empty())
        exit(84);
    for (unsigned int y = 0; y < _map.size(); ++y) {
        for (unsigned int x = 0; _map[y][x]; ++x) {
            switch(_map[y][x]) {
            case '\n': ++y; break;
            case 'o':
                if (!_player.empty()) {
                    std::cerr << "Error: Pacman map must contain only one player" << std::endl;
                    exit(84);
                }
                playerInit(&_player, Position(x, y));
                break;
            }
        }
    }
}

void Nibbler::event(Event const Event)
{

}

void Nibbler::update(int elapsedTime)
{

}

void Nibbler::drawMap(IGraphicRender &renderer) const noexcept
{
    Rect rect(Position(0, 0), Size(100, 100), Color::Blue());

    for (; rect.pos.y < _map.size(); ++rect.pos.y) {
        for (rect.pos.x = 0; _map[rect.pos.y][rect.pos.x]; ++rect.pos.x) {
            switch(_map[rect.pos.y][rect.pos.x]) {
            case '#':
                renderer.drawRect(rect);
                break;
            case '.': renderer.drawCircle(Circle(rect.pos, 10, Color::White())); break;
            case ' ': break;
            }
        }
    }
}

void Nibbler::render(IGraphicRender &renderer) const
{
    drawMap(renderer);
    drawPlayer(&_player, renderer);
}

const std::string Nibbler::getScore()
{

}
