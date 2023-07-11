/*
** EPITECH PROJECT, 2021
** sdl
** File description:
** sdl
*/

#include "SDL.hpp"
#include <iostream>
#include <cmath>

EXTERN_CLASS_IN_C(SDL, graphic)

static void printSdlError(std::string const &e)
{
    std::cerr << "sdl2: " << e << SDL_GetError() << std::endl;
}

SDL::SDL() noexcept : IGraphic(), _windowSize(0, 0), _aspectRatio(0, 0), _win(nullptr), _rend(nullptr), _surface(nullptr)
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_TIMER) < 0) {
        printSdlError("could not initialize -> ");
        exit(84);
    }
    if (!(_win = SDL_CreateWindow(WINDOW_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, RESOLUTION_X, RESOLUTION_Y, SDL_WINDOW_SHOWN))) {
        printSdlError("failed to create window -> ");
        exit(84);
    }
    if (!(_rend = SDL_CreateRenderer(_win, -1, SDL_RENDERER_SOFTWARE))) {
        printSdlError("failed to create render -> ");
        exit(84);
    }
    if (!(_surface = SDL_CreateRGBSurface(0, 100, 100, 32, 0x00, 0x00, 0x00, 0x00))) {
        printSdlError("failed to create surface -> ");
        exit(84);
    }
    SDL_GetWindowSize(_win, &_windowSize.x, &_windowSize.y);
    _aspectRatio.x = _windowSize.x > _windowSize.y ? ((float)_windowSize.x / _windowSize.y) : 1;
    _aspectRatio.y = _windowSize.y > _windowSize.x ? ((float)_windowSize.y / _windowSize.x) : 1;
}

SDL::~SDL() noexcept
{
    SDL_Quit();
    if (_win)
        SDL_DestroyWindow(_win);
    if (_rend)
        SDL_DestroyRenderer(_rend);
    if (_surface)
        SDL_FreeSurface(_surface);
}

void SDL::drawRect(Rect const &rect)
{

    SDL_Rect rect_{
        .x = (int)((int)rect.pos.x * _windowSize.x / 100 / _aspectRatio.x),
        .y = (int)((int)rect.pos.y * _windowSize.y / 100 / _aspectRatio.y),
        .w = (int)((int)rect.size.x * _windowSize.x / 100 / _aspectRatio.x) + 2,
        .h = (int)((int)rect.size.y * _windowSize.y / 100 / _aspectRatio.y) + 2
    };

    SDL_SetRenderDrawColor(_rend, rect.color.red, rect.color.green, rect.color.blue, rect.color.alpha);
    SDL_RenderFillRect (_rend, &rect_);
    SDL_RenderDrawRect(_rend, &rect_);
}

void SDL::drawCircle(Circle const &circle)
{
    Position pos (circle.pos.x * _windowSize.x / 100 / _aspectRatio.x, circle.pos.y * _windowSize.y / 100 / _aspectRatio.y);

    SDL_SetRenderDrawColor(_rend, circle.color.red, circle.color.green, circle.color.blue, circle.color.alpha);
    for (int x = pos.x - circle.radius * _windowSize.x / 100; x < pos.x + circle.radius * _windowSize.x / 100; ++x) {
        for (int y = pos.y- circle.radius * _windowSize.x / 100; y < pos.y + circle.radius * _windowSize.x / 100; ++y) {
            if (DISTANCE(pos.x, pos.y, x, y) < circle.radius * _windowSize.x / 100)
                SDL_RenderDrawPoint(_rend, x, y);
        }
    }
}

void SDL::drawSprite(Sprite const &sprite)
{

}

void SDL::drawText(Text const &text)
{

}

void SDL::refreshScreen()
{
    SDL_RenderPresent(_rend);
}

void SDL::clearScreen()
{
    SDL_SetRenderDrawColor(_rend, 0, 0, 0, 0);
    SDL_RenderClear(_rend);
}

bool SDL::isOperational()
{
    return true;
}

Event SDL::handleEvent()
{
    while(SDL_PollEvent(&_event)) {
        if (_event.type == SDL_QUIT)
            return Event::quit;
        else if (_event.type == SDL_KEYDOWN)
            switch(_event.key.keysym.sym) {
            case SDLK_z: return Event::up;
            case SDLK_d: return Event::right;
            case SDLK_q: return Event::left;
            case SDLK_s: return Event::down;
            case SDLK_RETURN: return Event::enter;
            case SDLK_ESCAPE: return Event::menu;
            case SDLK_F1: return Event::quit;
            case SDLK_F2: return Event::prev_game;
            case SDLK_F3: return Event::next_game;
            case SDLK_F5: return Event::prev_graphic;
            case SDLK_F6: return Event::next_graphic;
            case SDLK_r: return Event::restart;
            default: return Event::unknown;
            }
    }
    return Event::unknown;
}
