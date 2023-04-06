/*
** EPITECH PROJECT, 2023
** arcade::interface-Interface
** File description:
** Menu
*/

#include "../Module Interface/IGameModule.hpp"
#include "../Module Interface/IDisplayModule.hpp"
#include "../Module Interface/UserModule.hpp"
#include <iostream>

class Menu2 : public arcade::interface::IGameModule
{
    public:
        Menu2() = default;

        size_t update(std::shared_ptr<arcade::interface::IDisplayModule> display, arcade::User_data &user, std::vector<std::string> &_gameLibs,  std::vector<std::string> &_graphLibs, 
        std::vector<std::string> &_menuLibs, size_t &_pathToGraphLib, size_t &_pathtoGameLib, size_t &_pathToMenuLib) 
        {
            display->clearWindow();
            // INPUT FOR MANAGEMENT OF LIBS
            if (display->isKeyPressed(arcade::interface::KeyCode::Up))
                return 1;
            if (display->isKeyPressed(arcade::interface::KeyCode::Down))
                return -1;
            if (display->isKeyPressed(arcade::interface::KeyCode::Left))
                return 2;
            if (display->isKeyPressed(arcade::interface::KeyCode::Right))
                return -2;
            if (display->isKeyPressed(arcade::interface::KeyCode::Enter))
                return 69;
            if (display->isKeyPressed(arcade::interface::KeyCode::A))
                return 3;
            if (display->isKeyPressed(arcade::interface::KeyCode::E))
                return -3;
            // INPUT FOR MANAGEMENT OF LIBS    
            display->draw(title);
            display->fetchInputs();            
            display->displayWindow();
            return 0;
        }
        
        std::string getName() const
        {
            return "Menu 2";
        }

    private:
        bool Initialisation(std::shared_ptr<arcade::interface::IDisplayModule> display)
        {
            display->fetchInputs();
            title = display->createText();
            title->setText("Menu 2");
            title->setPosition(100, 10);
            title->setColor(arcade::RED);
            title->setFont("assets/SIXTY");
            title->setFontSize(50);
            return true;
        }

    private:
        std::shared_ptr<arcade::interface::ITextModule> title; 

};
