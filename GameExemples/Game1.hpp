/*
** EPITECH PROJECT, 2023
** Arcade-Interface
** File description:
** Game1
*/

#include "../Module Interface/IGameModule.hpp"
#include "../Module Interface/IDisplayModule.hpp"
#include "../Module Interface/UserModule.hpp"
#include <iostream>



class Game1 : public arcade::IGameModule
{
    public:
        Game1() = default;

        size_t update(
            std::shared_ptr<arcade::IDisplayModule> display,
            arcade::User_data &user,
            std::vector<std::string> &_gameLibs,
            std::vector<std::string> &_graphLibs, 
            std::vector<std::string> &_menuLibs,
            size_t &_pathToGraphLib,
            size_t &_pathtoGameLib,
            size_t &_pathToMenuLib) 
        {
            std::cout << _graphLibs[_pathToGraphLib] << _gameLibs[_pathtoGameLib] << _menuLibs[_pathToMenuLib] << user.getName() <<std::endl;
            if (firstTime && _graphLibs[_pathToGraphLib] != _my_graphLib) {
                _my_graphLib = _graphLibs[_pathToGraphLib];
                init_game(display);
                firstTime = false;
            }
            
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
            // 
            display->draw(player);
            display->draw(title);
            display->fetchInputs();            
            display->displayWindow();
            return 0;
        }
        
        std::string getName() const
        {
            return "Game 1";
        }

    private:
        int init_game(std::shared_ptr<arcade::IDisplayModule> display)
        {
            display.get()->fetchInputs();
            player = display.get()->createSprite();
            player->setSprite("assets/test.png");
            player->setPosition(100, 100);

            title = display.get()->createText();
            title->setText("Game 1");
            title->setPosition(100, 10);
            title->setColor(255, 255, 255);
            title->setFontSize(50);
            return 0;
        }
        
        
        
        std::shared_ptr<arcade::ISpriteModule> player;
        std::shared_ptr<arcade::ITextModule> title;
        
    private:
        bool firstTime = true;
        std::string _my_graphLib = ""; 

};
