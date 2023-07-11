/*
** EPITECH PROJECT, 2021
** ncurses
** File description:
** sfml
*/

#include "SFML.hpp"

#include <iostream>

EXTERN_CLASS_IN_C(SFML, graphic)

SFML::SFML() : IGraphic(), _aspectRatio(0, 0)
{
    _window.create(sf::VideoMode(RESOLUTION_X, RESOLUTION_Y), WINDOW_NAME);
    _aspectRatio.x = _window.getSize().x > _window.getSize().y ? ((float)_window.getSize().x / _window.getSize().y) : 1;
    _aspectRatio.y = _window.getSize().y > _window.getSize().x ? ((float)_window.getSize().y / _window.getSize().x) : 1;
}

SFML::~SFML() noexcept
{
    _window.close();
}

void SFML::drawRect(Rect const &rect)
{
    sf::RectangleShape shape(sf::Vector2f((int)((int)rect.size.x * _window.getSize().x / 100 / _aspectRatio.x) + 2,
                                                (int)((int)rect.size.y * _window.getSize().y / 100 / _aspectRatio.y) + 2));

    shape.setFillColor(sf::Color(rect.color.red, rect.color.green, rect.color.blue, rect.color.alpha));
    shape.setPosition((int)((int)rect.pos.x * _window.getSize().x / 100 / _aspectRatio.x),
                      (int)((int)rect.pos.y * _window.getSize().y / 100 / _aspectRatio.y));
    _window.draw(shape);
}

void SFML::drawCircle(Circle const &circle)
{
    float const size = circle.radius * _window.getSize().x / 100;

    sf::CircleShape shape(size);
    shape.setFillColor(sf::Color(circle.color.red, circle.color.green, circle.color.blue, circle.color.alpha));
    shape.setOrigin(sf::Vector2f(size, size));
    shape.setPosition(circle.pos.x * _window.getSize().x / 100 / _aspectRatio.x, circle.pos.y * _window.getSize().y / 100 / _aspectRatio.y);
    _window.draw(shape);
}


void SFML::drawSprite(Sprite const &sprite)
{
    sf::Texture texture;
    sf::Sprite renderSprite;
    if (!texture.loadFromFile(sprite.getTexturePath())) {
        std::cerr << "Texture nor found" << std::endl;
        exit(84);
    }
    renderSprite.setTexture(texture);
    renderSprite.setTextureRect(sf::IntRect(sprite.pos.x, sprite.pos.y, sprite.size.x, sprite.size.y));
    _window.draw(renderSprite);
}

void SFML::drawText(Text const &text)
{
    sf::Text renderText;
    sf::Font font;
    if (!font.loadFromFile("./assets/fonts/Pacman/poxel-font.ttf")) {
        std::cerr << "Font not found" << std::endl;
        exit(84);
    }
    renderText.setFont(font);
    renderText.setString(text.getText());
    renderText.setCharacterSize((text.size.x / 10) * _window.getSize().x / 100);
    renderText.setPosition(text.pos.x * _window.getSize().x / 100, text.pos.y * _window.getSize().y / 100);
    renderText.setFillColor(sf::Color(text.color.red, text.color.green, text.color.blue, text.color.alpha));
    _window.draw(renderText);
}

void SFML::refreshScreen()
{
    _window.display();
}

void SFML::clearScreen()
{
    _window.clear(sf::Color::Black);
}

bool SFML::isOperational()
{
    return true;
}


Event SFML::handleEvent()
{
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)
            return (Event::quit);
        else if (_event.type == sf::Event::KeyPressed) {
            switch (_event.key.code) {
            case sf::Keyboard::Z: return Event::up;
            case sf::Keyboard::D: return Event::right;
            case sf::Keyboard::Q: return Event::left;
            case sf::Keyboard::S: return Event::down;
            case sf::Keyboard::Return: return Event::enter;
            case sf::Keyboard::Escape: return Event::menu;
            case sf::Keyboard::F1: return Event::quit;
            case sf::Keyboard::F2: return Event::prev_game;
            case sf::Keyboard::F3: return Event::next_game;
            case sf::Keyboard::F5: return Event::prev_graphic;
            case sf::Keyboard::F6: return Event::next_graphic;
            case sf::Keyboard::R: return Event::restart;
            default: return Event::unknown;
            }
        }
    }
    return Event::unknown;
}
