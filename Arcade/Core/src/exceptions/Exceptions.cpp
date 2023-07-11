/*
** EPITECH PROJECT, 2021
** Exceptions
** File description:
** Exceptions
*/

#include "Exceptions.hpp"

CoreError::CoreError(std::string const &e) noexcept : _msg("CoreError: " + e) {}

char const *CoreError::what() const noexcept
{
    return _msg.c_str();
}

GraphicalError::GraphicalError(std::string const &e) noexcept : _msg("GraphicalError: " + e) {}

char const *GraphicalError::what() const noexcept
{
    return _msg.c_str();
}
