/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "../../include/IGame.hpp"
#include "Core.hpp"
#include "Exceptions.hpp"

#include <iostream>
#include <ctime>

static void printUsage()
{
    std::cout << "Usage: arcade <lib.so>" << std::endl;
}

int main(int const argc, char const * const *argv)
{
    if (argc < 2 || argc > 2) {
        printUsage();
        return 84;
    }
    try {
        Core core;
        srand(time(NULL));
        if (!core.loadLibFromPath(argv[1]) || !core.loadGameFromPath(core.getGamePath(0)))
            return 84;
        core.run();
    } catch (CoreError const &e) {
        e.what();
        return 84;
    }
    return 0;
}
