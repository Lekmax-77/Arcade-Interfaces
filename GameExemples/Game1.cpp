/*
** EPITECH PROJECT, 2023
** Arcade-Interface
** File description:
** Game1
*/

#include "Game1.hpp"

extern "C"
{
    std::shared_ptr<arcade::IGameModule> createGame()
    {
        return std::make_shared<Game1>();
    }

    std::string getName(void)
    {
        return ("game");
    }
}