/*
** EPITECH PROJECT, 2021
** Core
** File description:
** Core
*/

#include "Core.hpp"
#include "include.hpp"
#include "Exceptions.hpp"

#include <iostream>
#include <cstdlib>
#include <signal.h>
#include <unistd.h>
#include <algorithm>
#include <filesystem>
#include <dirent.h>

Core::Core() noexcept : _scene(Scene::Game),
                        _gamesPath(std::make_pair(std::vector<std::string>(), 0)),
                        _libsPath(std::make_pair(std::vector<std::string>(), 0))
{
    getLibsFromFolder("./lib/");
}

void Core::displayGame(Event const event) noexcept
{
    _game.methods->event(event);
    _game.methods->update(1);
    _game.methods->render(*_lib.methods);
}

void Core::displayMenu(Event const event) noexcept
{
    static Text menu_title("Menu", Position(50, 50), Size(3, 3), Color::White());

    _lib.methods->drawText(menu_title);
}

void Core::run()
{
    Event event = Event::unknown;
    void (Core::*scenes[2])(Event const) = {&Core::displayMenu, &Core::displayGame};

    while (event != Event::quit) {
        _lib.methods->clearScreen();
        (this->*scenes[_scene])(event);
        _lib.methods->refreshScreen();
        event = _lib.methods->handleEvent();
        switch(event) {
        case Event::next_game:
            if (_gamesPath.second + 1 < (int)_gamesPath.first.size())
                ++_gamesPath.second;
            else
                _gamesPath.second = 0;
            _game.reset();
            _game.loadFromPath(_gamesPath.first[_gamesPath.second], Lib::game);
            break;
        case Event::prev_game:
            if (_gamesPath.second - 1 < 0)
                _gamesPath.second = _gamesPath.first.size() - 1;
            else
                --_gamesPath.second;
            _game.reset();
            _game.loadFromPath(_gamesPath.first[_gamesPath.second], Lib::game);
            break;
        case Event::next_graphic:
            if (_libsPath.second + 1 < (int)_libsPath.first.size())
                ++_libsPath.second;
            else
                _libsPath.second = 0;
            _lib.reset();
            _lib.loadFromPath(_libsPath.first[_libsPath.second], Lib::graphic);
            break;
        case Event::prev_graphic:
            if (_libsPath.second - 1 < 0)
                _libsPath.second = _libsPath.first.size() - 1;
            else
                --_libsPath.second;
            _lib.reset();
            _lib.loadFromPath(_libsPath.first[_libsPath.second], Lib::graphic);
            break;
        }
    }
}

bool Core::loadGameFromPath(std::string const &path) noexcept
{
    std::string const path_ = path.substr(path.find_last_of('/') + 1);

    auto const it = std::find_if(_gamesPath.first.begin(), _gamesPath.first.end(), [&path_](std::string const gamePath) {
        return (path_ == gamePath.substr(gamePath.find_last_of('/') + 1));
    });
    _gamesPath.second = (it != _gamesPath.first.end() ? (std::distance(_gamesPath.first.begin(), it)) : 0);
    return _game.loadFromPath(path, Lib::game);
}

bool Core::loadLibFromPath(std::string const &path) noexcept
{
    std::string const path_ = path.substr(path.find_last_of('/') + 1);

    auto const it = std::find_if(_libsPath.first.begin(), _libsPath.first.end(), [&path_](std::string const libPath) {
        return (path_ == libPath.substr(libPath.find_last_of('/') + 1));
    });
    _libsPath.second = (it != _libsPath.first.end() ? (std::distance(_libsPath.first.begin(), it)) : 0);
    return _lib.loadFromPath(path, Lib::graphic);
}

bool Core::getLibsFromFolder(std::string const &path) noexcept {
    DIR *dir = opendir(path.c_str());
    struct dirent *file;

    if (!dir) {
        std::cerr << "getFilesFromFolder: failed to open " + std::string(path) << std::endl;
        return true;
    }
    std::string filePath("");
    size_t begin = 0;
    size_t ext = 0;
    SharedLib<void *> lib;
    Lib type = Lib::unknown;
    std::function<Lib()> getType = nullptr;

    while ((file = readdir(dir))) {
        filePath = file->d_name;
        ext = filePath.find_last_of('.');
        begin = filePath.find_last_of('/') != std::string::npos ? filePath.find_last_of('/') : 0;
        if (ext != std::string::npos &&
            !filePath.compare(begin, 6, "arcade") &&
            !filePath.compare(ext, -1, ".so")) {
            if (!lib.openLibFromPath(path + filePath) || !(getType = lib.getSym<Lib (*)()>("getType")))
                continue;
            type = getType();
            lib.reset();
            if (type == Lib::graphic)
                _libsPath.first.push_back(path + file->d_name);
            else if (type == Lib::game)
                _gamesPath.first.push_back(path + file->d_name);
        }
    }
    closedir (dir);
    return false;
}
