/*
** EPITECH PROJECT, 2021
** Map
** File description:
** Map
*/

#include "Map.hpp"

#include <fstream>
#include <sstream>

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

Map::Map() noexcept : size(Size(0, 0))
{}

Map::Map(std::string const &path) noexcept : size(Size(0, 0))
{
    loadMapFromPath(path);
}

void Map::loadMapFromPath(std::string const &path) noexcept
{
    size_t dot = path.find_last_of('.');

    _map.clear();
    if (dot != std::string::npos && !path.compare(dot, std::string::npos, ".map")) {
        _map = readfile(path);
        size.x = _map[0].length();
        size.y = _map.size();
    }
    int cellSizeX = 1 / size.x * 100;
    int cellSizeY = 1 / size.y * 100;
    cellSize = cellSizeX > cellSizeY ? cellSizeX : cellSizeY;
    halfCellSize = cellSize / 2;
}

bool Map::isEmpty() const noexcept
{
    return _map.empty();
}


std::string &Map::operator[](int const y) noexcept
{
    return _map[y];
}

std::string const &Map::operator[](int const y) const noexcept
{
    return _map[y];
}

bool Map::checkCollision(Vector2f const &pos, Vector2f const &offset, Direction const direction) const noexcept
{
    switch(direction) {
    case Direction::up: return (pos.y >= 0 && (_map[pos.y - 1][pos.x] == WALL || offset.x != 0));
    case Direction::down: return (pos.y <= size.y - 1 && (_map[pos.y + 1][pos.x] == WALL || offset.x != 0));
    case Direction::left: return (pos.x >= 0 && (_map[pos.y][pos.x - 1] == WALL || offset.y != 0));
    case Direction::right: return (pos.x <= size.x - 1 && (_map[pos.y][pos.x + 1] == WALL || offset.y != 0));
    }
    return true;
}
