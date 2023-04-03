/*
** EPITECH PROJECT, 2023
** Arcade-Interface
** File description:
** Menu
*/

#include "../Module Interface/IGameModule.hpp"
#include "../Module Interface/IDisplayModule.hpp"
#include "../Module Interface/UserModule.hpp"
#include <iostream>

class Menu1 : public arcade::IGameModule
{
    public:
        Menu1() = default;

        size_t update(std::shared_ptr<arcade::IDisplayModule> display, arcade::User_data &user, std::vector<std::string> &_gameLibs,  std::vector<std::string> &_graphLibs, 
        std::vector<std::string> &_menuLibs, size_t &_pathToGraphLib, size_t &_pathtoGameLib, size_t &_pathToMenuLib) 
        {
            display->clearWindow();
            // INPUT FOR MANAGEMENT OF LIBS
            if (display->isKeyPressed(arcade::KeyCode::Escape))
                return 69;
            if (display->isKeyPressed(arcade::KeyCode::Up))
                return 1;
            if (display->isKeyPressed(arcade::KeyCode::Down))
                return -1;
            if (display->isKeyPressed(arcade::KeyCode::Left))
                return 2;
            if (display->isKeyPressed(arcade::KeyCode::Right))
                return -2;
            if (display->isKeyPressed(arcade::KeyCode::Enter))
                return 69;
            if (display->isKeyPressed(arcade::KeyCode::Space))
                return 69;
            if (display->isKeyPressed(arcade::KeyCode::A))
                return 3;
            if (display->isKeyPressed(arcade::KeyCode::E))
                return -3;
            // INPUT FOR MANAGEMENT OF LIBS    
            display->draw(title);
            display->fetchInputs();            
            display->displayWindow();
            return 0;
        }
        
        std::string getName() const
        {
            return "Menu 1";
        }

    private:
        bool Initialisation(std::shared_ptr<arcade::IDisplayModule> display)
        {
            display->fetchInputs();
            title = display->createText();
            title->setText("Menu");
            title->setPosition(100, 10);
            title->setColor(255, 255, 255);
            title->setFontSize(50);
            return true;
        }

    private:
        std::shared_ptr<arcade::ITextModule> title; 

};
