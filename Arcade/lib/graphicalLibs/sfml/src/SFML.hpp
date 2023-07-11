/*
** EPITECH PROJECT, 2021
** ncurses
** File description:
** sfml
*/

#ifndef __SFML__
#define __SFML__

#include <SFML/Graphics.hpp>
#include "../../../../include/IGraphics.hpp"

class SFML : public IGraphic {
public:
        explicit SFML();
        ~SFML() noexcept;
        void drawRect(const Rect &rect) final override;
        void drawCircle(const Circle &circle) final override;
        void drawSprite(const Sprite &sprite) final override;
        void drawText(const Text &text) final override;
        void refreshScreen() final override;
        void clearScreen() final override;
        bool isOperational() final override;
        Event handleEvent() final override;
private:
        Vector2f _aspectRatio;
        sf::RenderWindow _window;
        sf::Event _event;
};

#endif /* __SFML__ */
