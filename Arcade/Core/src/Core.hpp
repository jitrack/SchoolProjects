/*
** EPITECH PROJECT, 2021
** Core
** File description:
** Core
*/

#ifndef __CORE__
#define __CORE__

#include "../../include/IGame.hpp"
#include "../../include/IGraphics.hpp"
#include "SharedLib.hpp"

#include <string>
#include <vector>

class Core {
public:
    explicit Core() noexcept;
    ~Core() noexcept = default;

    enum Scene:int{ Menu = 0, Game = 1 };

    void run();
    void displayGame(Event const event) noexcept;
    void displayMenu(Event const event) noexcept;
    bool loadGameFromPath(std::string const &path) noexcept;
    bool loadLibFromPath(std::string const &path) noexcept;
    std::string const &getGamePath(unsigned int const i) const noexcept { return _gamesPath.first[i < _gamesPath.first.size() ? i : 0];};
    bool getLibsFromFolder(std::string const &path) noexcept;
private:
    Scene _scene;
    std::pair<std::vector<std::string>, int> _gamesPath;
    std::pair<std::vector<std::string>, int> _libsPath;
    SharedLib<IGame> _game;
    SharedLib<IGraphic> _lib;
};

#endif /* __CORE__ */
