/*
** EPITECH PROJECT, 2023
** Arcade-Interface
** File description:
** game2
*/

#include "../Module Interface/IGameModule.hpp"
#include "../Module Interface/IDisplayModule.hpp"
#include "../Module Interface/UserModule.hpp"
#include <iostream>

class Game2 : public arcade::IGameModule
{
    public:
        Game2() = default;

        size_t update(std::shared_ptr<arcade::IDisplayModule> display,
        arcade::User_data &user,
        std::vector<std::string> &_gameLibs,
        std::vector<std::string> &_graphLibs, 
        std::vector<std::string> &_menuLibs,
        size_t &_pathToGraphLib,
        size_t &_pathtoGameLib,
        size_t &_pathToMenuLib) 
        {
            display->clearWindow();
            if (display->isKeyPressed(arcade::KeyCode::Q))
                player->move(-1, 0);
            if (display->isKeyPressed(arcade::KeyCode::S))
                player->move(1, 0);
            if (display->isKeyPressed(arcade::KeyCode::Z))
                player->move(0, -1);
            if (display->isKeyPressed(arcade::KeyCode::D))
                player->move(0, 1);
            
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
            // INPUT FOR MANAGEMENT OF LIBS

        
            
            display->draw(player);
            display->draw(title);
            display->fetchInputs();            
            display->displayWindow();
            return 0;
        }
        
        std::string getName() const
        {
            return "Game 2";
        }

    private:
        bool Initialisation(std::shared_ptr<arcade::IDisplayModule> display)
        {
            display->fetchInputs();
            player = display.get()->createSprite();
            player->setSprite("assets/test.png");
            player->setPosition(100, 100);

            title = display->createText();
            title->setText("Game 2");
            title->setPosition(100, 10);
            title->setColor(255, 255, 255);
            title->setFontSize(50);
            return true;
        }

    private:
        std::shared_ptr<arcade::ISpriteModule> player;
        std::shared_ptr<arcade::ITextModule> title;
};
