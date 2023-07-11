/*
** EPITECH PROJECT, 2021
** ncurses
** File description:
** ncurses
*/

#include "NCurses.hpp"

#include <curses.h>
#include <unistd.h>
#include <math.h>

#define RED 1
#define GREEN 2
#define BLUE 3
#define YELLOW 4
#define WHITE 5
#define BLACK 6
#define ORANGE 7
#define PINK 8
#define GREY 9

EXTERN_CLASS_IN_C(NCurses, graphic)

char getColorPairFromColorClass(Color const &color)
{
    if (color == Color::Red()) return RED;
    if (color == Color::Green()) return GREEN;
    if (color == Color::Blue()) return BLUE;
    if (color == Color::White()) return WHITE;
    if (color == Color::Black()) return BLACK;
    if (color == Color::Yellow()) return YELLOW;
    if (color == Color::Orange()) return ORANGE;
    if (color == Color::Pink()) return PINK;
    if (color == Color::Grey()) return GREY;
    return -1;
}

NCurses::NCurses() noexcept : IGraphic(), _aspectRatio(0, 0), _windowSize(0, 0)
{
    initscr();
    noecho();
    curs_set(false);
    nodelay(stdscr, true);
    cbreak();
    keypad(stdscr, true);
    if (!has_colors()) {
        endwin();
        exit(84);
    }
    start_color();
    init_color(ORANGE, 0xFF, 0x87, 0x00);
    init_color(PINK, 0xFF, 0x00, 0xAF);
    init_color(GREY, 0x30, 0x30, 0x30);
    init_pair(RED, COLOR_RED, COLOR_RED);
    init_pair(GREEN, COLOR_GREEN, COLOR_GREEN);
    init_pair(BLUE, COLOR_BLUE, COLOR_BLUE);
    init_pair(YELLOW, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(WHITE, COLOR_WHITE, COLOR_WHITE);
    init_pair(BLACK, COLOR_BLACK, COLOR_BLACK);
    init_pair(ORANGE, ORANGE, ORANGE);
    init_pair(PINK, PINK, PINK);
    init_pair(GREY, GREY, GREY);
    getmaxyx(stdscr, _windowSize.y, _windowSize.x);
    _aspectRatio.x = _windowSize.x > _windowSize.y ? ((float)_windowSize.x / _windowSize.y / 2) : 1;
    _aspectRatio.y = _windowSize.y > _windowSize.x ? ((float)_windowSize.y / _windowSize.x) : 1;
}

NCurses::~NCurses() noexcept
{
    clear();
    endwin();
}

void NCurses::drawRect(Rect const &rect)
{
    float const positionY = rect.pos.y * _windowSize.y / 100 / _aspectRatio.y;
    float const positionX = rect.pos.x * _windowSize.x / 100 / _aspectRatio.x;
    char const color = getColorPairFromColorClass(rect.color);
    Size size((int)(rect.size.x * _windowSize.x / 100 / _aspectRatio.x), (int)(rect.size.y * _windowSize.y / 100 / _aspectRatio.y));
    Position position((int)(positionX), (int)(positionY));

    if ((float)positionY > (int)positionY)
        size.y++;
    if ((float)positionX > (int)positionX)
        size.x++;
    size.y = size.y ? size.y : 1;
    size.x = size.x ? size.x : 1;
    attron(COLOR_PAIR(color));
    for (unsigned int i = 0; i < size.y; i++) {
        for (unsigned int j = 0; j < size.x; j++)
            mvaddch(i + position.y, j + position.x, 'o');
    }
    attroff(COLOR_PAIR(color));
}

void NCurses::drawCircle(Circle const &circle)
{
    float const positionY = circle.pos.y * _windowSize.y / 100 / _aspectRatio.y - 1;
    float const positionX = circle.pos.x * _windowSize.x / 100 / _aspectRatio.x - 2;
    char const color = getColorPairFromColorClass(circle.color);
    Size size((int)(circle.radius * _windowSize.x / 100 / _aspectRatio.x) / 10, (int)(circle.radius * _windowSize.y / 100 / _aspectRatio.y));
    Position position((int)(positionX), (int)(positionY));

    if ((float)positionY > (int)positionY)
        size.y++;
    if ((float)positionX > (int)positionX)
        size.x++;
    size.y = size.y ? size.y : 1;
    size.x = size.x ? size.x : 1;
    attron(COLOR_PAIR(color));
    for (unsigned int i = 0; i < size.y; i++) {
        for (unsigned int j = 0; j < size.x; j++)
            mvaddch(i + position.y, j + position.x, 'o');
    }
    attroff(COLOR_PAIR(color));
}

void NCurses::drawSprite(Sprite const &sprite)
{

}

void NCurses::drawText(Text const &text)
{
}

void NCurses::refreshScreen()
{
    refresh();
    usleep(1500);
}

void NCurses::clearScreen()
{
    clear();
}

bool NCurses::isOperational()
{
    return true;
}

void NCurses::updateWindowInfos() noexcept
{

}

Event NCurses::handleEvent()
{
    switch(getch()) {
    case 'z': return Event::up;
    case 'Z': return Event::up;
    case 'd': return Event::right;
    case 'D': return Event::right;
    case 'q': return Event::left;
    case 'Q': return Event::left;
    case 's': return Event::down;
    case 'S': return Event::down;
    case KEY_ENTER: return Event::enter;
    case 27: return Event::menu;
    case KEY_F(1): return Event::quit;
    case KEY_F(2): return Event::next_game;
    case KEY_F(3): return Event::prev_game;
    case KEY_F(5): return Event::prev_graphic;
    case KEY_F(6): return Event::next_graphic;
    case 'r': return Event::restart;
    case 'R': return Event::restart;
    }
    return Event::unknown;
}
