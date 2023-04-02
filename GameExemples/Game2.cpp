/*
** EPITECH PROJECT, 2023
** Arcade-Interface
** File description:
** Game2
*/

#include "Game2.hpp"
#include <memory>

extern "C"
{
    std::shared_ptr<arcade::IGameModule> createGame()
    {
        return std::make_shared<Game2>();
    }

    std::string getName(void)
    {
        return ("game");
    }
}