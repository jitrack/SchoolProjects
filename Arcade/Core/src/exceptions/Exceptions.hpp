/*
** EPITECH PROJECT, 2021
** Exceptions
** File description:
** Exceptions
*/

#ifndef __EXCEPTIONS__
#define __EXCEPTIONS__

#include <exception>
#include <string>

class CoreError : public std::exception {
public:
    explicit CoreError(std::string const &msg) noexcept;
    ~CoreError() = default;

    char const *what() const noexcept;
private:
    std::string const _msg;
};


class GraphicalError : public std::exception {
public:
    explicit GraphicalError(std::string const &msg) noexcept;
    ~GraphicalError() = default;

    char const *what() const noexcept;
private:
    std::string const _msg;
};

#endif /* __EXCEPTIONS__ */
