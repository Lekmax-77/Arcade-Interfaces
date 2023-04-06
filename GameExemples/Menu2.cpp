/*
** EPITECH PROJECT, 2023
** Arcade-Interface
** File description:
** Menu2
*/

#include "Menu2.hpp"
#include <memory>

extern "C"
{
    std::shared_ptr<arcade::interface::IGameModule> createGame()
    {
        return std::make_shared<Menu2>();
    }

    std::string getType(void)
    {
        return ("menu");
    }
}