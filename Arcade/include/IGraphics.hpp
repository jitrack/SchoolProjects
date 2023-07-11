/*
** EPITECH PROJECT, 2021
** IGraphics
** File description:
** IGraphics
*/

#ifndef __IGRAPHICS__
#define __IGRAPHICS__

#include "Drawables.hpp"
#include <ctime>

#define RESOLUTION_X 1920
#define RESOLUTION_Y 1080

#define HALF_RESOLUTION_X = RESOLUTION_X / 2
#define HALF_RESOLUTION_y = RESOLUTION_Y / 2

#define WINDOW_NAME "arcade"

#define randBetween(min, max) ((rand() % (max - min)) + min)

typedef enum Event_e { unknown = -1, up, down, right, left, menu, enter, next_game, prev_game, next_graphic, prev_graphic, restart, quit } Event;

class IGraphicRender {
    public:
        virtual ~IGraphicRender() = default;

        virtual void drawRect(const Rect &rect) = 0;
        virtual void drawCircle(const Circle &circle) = 0;
        virtual void drawSprite(const Sprite &sprite) = 0;
        virtual void drawText(const Text &text) = 0;
        virtual void refreshScreen() = 0;
        virtual void clearScreen() = 0;
};

class IGraphic: public IGraphicRender {
    public:
        IGraphic() = default;
        IGraphic(const IGraphic &) = delete;
        virtual ~IGraphic() noexcept = default;
        virtual bool isOperational() = 0;
        virtual Event handleEvent() = 0;
};

enum class Lib {unknown = -1, game, graphic};

#define EXTERN_CLASS_IN_C(class__, lib)  \
extern "C" {                             \
    class__ *entry()                     \
    {                                    \
        return new class__;              \
    }                                    \
    Lib getType()                        \
    {                                    \
        return Lib::lib;                 \
    }                                    \
}                                        \

#endif /* __IGRAPHICS__ */
