/*
** EPITECH PROJECT, 2021
** ncurses
** File description:
** ncurses
*/

#ifndef __NCURSES__
#define __NCURSES__

#include "../../../../include/IGraphics.hpp"

#include <iostream>
#include <ncurses.h>

class NCurses : public IGraphic {
public:
    explicit NCurses() noexcept;
    ~NCurses() noexcept;
    void drawRect(const Rect &rect) final override;
    void drawCircle(const Circle &circle) final override;
    void drawSprite(const Sprite &sprite) final override;
    void drawText(const Text &text) final override;
    void refreshScreen() final override;
    void clearScreen() final override;
    bool isOperational() final override;
    Event handleEvent() final override;
    void updateWindowInfos() noexcept;

private:
    Vector2f _aspectRatio;
    Vector2u _windowSize;
    int _windowSizeX, _windowSizeY;
};

#endif /* __NCURSES__ */
