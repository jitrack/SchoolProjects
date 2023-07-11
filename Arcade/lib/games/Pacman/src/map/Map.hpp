/*
** EPITECH PROJECT, 2021
** Map
** File description:
** Map
*/

#ifndef __MAP__
#define __MAP__

#include <string>
#include <vector>

#include "../../../../../include/IGraphics.hpp"
#include "../../include/Include.hpp"

struct Map {
public:
    explicit Map() noexcept;
    explicit Map(std::string const &path) noexcept;
    ~Map() noexcept = default;

    bool checkCollision(Vector2f const &pos, Vector2f const &offset, Direction const direction) const noexcept;
    void loadMapFromPath(std::string const &path) noexcept;
    bool isEmpty() const noexcept;
    std::string &operator[](int const y) noexcept;
    std::string const &operator[](int const y) const noexcept;

    Size size;
    float cellSize;
    float halfCellSize;
    unsigned int nbPacgums;
private:
    std::vector<std::string> _map;
};

#endif /* __MAP__ */
