/*
** EPITECH PROJECT, 2021
** SharedLib
** File description:
** SharedLib
*/

#ifndef __SHAREDLIB__
#define __SHAREDLIB__

#include <dlfcn.h>
#include <iostream>
#include <functional>
#include "../../include/IGraphics.hpp"

template <class T>
class SharedLib {
public:
    explicit SharedLib() noexcept : methods(nullptr), _sharedLibPtr(nullptr) {}
    ~SharedLib() noexcept { reset(); }

    void reset() noexcept
    {
        if (methods)
            delete methods;
        if (_sharedLibPtr)
            dlclose(_sharedLibPtr);
        char *error = dlerror();
        if (error) {
            std::cerr << "SharedLibError: " << error << std::endl;
            exit(84);
        }
        _sharedLibPtr = nullptr;
        methods = nullptr;
    }

    template <typename F>
    F getSym(char const *name) const noexcept
    {
        void *sym = dlsym(_sharedLibPtr, name);
        char *error = dlerror();

        if (error) {
            std::cerr << "SharedLibError: " << error << std::endl;
            return nullptr;
        }
        return (F)sym;
    }

    std::function<T *()> const openLibFromPath(std::string const &str) noexcept
    {
        if (!(_sharedLibPtr = dlopen(str.c_str(), RTLD_LAZY))) {
            std::cerr << "SharedLibError: Can't load library " + str << std::endl;
            return nullptr;
        }
        return getSym<T *(*)()>("entry");
    }

    bool loadFromPath(std::string const &path, Lib const lib) noexcept
    {
        auto const constructor = openLibFromPath(path);

        Lib (*getType)() = getSym<Lib (*)()>("getType");
        if (!getType || getType() != lib)
            return false;
        if (!constructor)
             exit(84);
        if (!(methods = constructor())) {
            std::cerr << "SharedLibError: can't create new class from sharedlib" << std::endl;
            exit(84);
        }
        return true;
    }

    T *methods;
private:
    void *_sharedLibPtr;
};
#endif /* __SHAREDLIB__ */
