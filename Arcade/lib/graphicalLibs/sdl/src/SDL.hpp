/*
** EPITECH PROJECT, 2021
** sdl
** File description:
** sdl
*/

#ifndef __SDL__
#define __SDL__

#include "../../../../include/IGraphics.hpp"

#include <SDL2/SDL.h>

#define DISTANCE(x1, y1, x2, y2) (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)))

class SDL : public IGraphic {
public:
    explicit SDL() noexcept;
    ~SDL() noexcept;
    void drawRect(const Rect &rect) final override;
    void drawCircle(const Circle &circle) final override;
    void drawSprite(const Sprite &sprite) final override;
    void drawText(const Text &text) final override;
    void refreshScreen() final override;
    void clearScreen() final override;
    bool isOperational() final override;
    Event handleEvent() final override;

private:
    Vector2i _windowSize;
    Vector2f _aspectRatio;
    SDL_Window *_win;
    Uint32 _renderFlags;
    SDL_Renderer* _rend;
    SDL_Event _event;
    SDL_Surface *_surface;
};

#endif /* __SDL__ */
