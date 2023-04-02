/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** ISpriteModule
*/

#ifndef ISPRITEMODULE_HPP_
    #define ISPRITEMODULE_HPP_
    #include <string>

namespace arcade {

    class ISpriteModule {
            public:
                /**
                 * @brief Destroy the ISpriteModule object
                 * 
                 */
                virtual ~ISpriteModule() = default;

                /**
                 * @brief Get the Sprite object
                 * 
                 * USED ONLY IN WRAPPER
                 * MUST : return the object sprite or texture to draw
                 * 
                 * @return void* is the sprite
                 */
                virtual void *getSprite() const = 0;


                /**
                 * @brief Set the Sprite object
                 * 
                 * ALL FILE TYPES MUST BE AT THE PATH SPECIFIED
                 * MUST: set a sprite (ex: w a texture then a sprite from it in SFML)
                 * ex SFML: assetPath = ./Assets/Pacman/enemy/goblin/enemy
                 * assetPath = ./Assets/Pacman/enemy/goblin/enemy
                 * real path (inside sfml implementation) =./Assets/Pacman/enmey/goblin/enemy.png  or .jpeg

                 * @param filePath is the path to the sprite
                 */
                virtual void setSprite(std::string filePath) = 0;


                /**
                 * @brief Set the Position object
                 * 
                 * @param x x is the abscissa of the position
                 * @param y y is the ordinate of the position
                 */
                virtual void setPosition(float x, float y) = 0;

                /**
                 * @brief Move the sprite
                 * 
                 * @param x move x position
                 * @param y move y position
                 */
                virtual void move(float x, float y) = 0;

                
                /**
                 * @brief Set the Crop object
                 * 
                 * set texture crop to the sprite (does maybe nothing based on lib)
                 * 
                 * @param x x position of the crop
                 * @param y y position of the crop
                 * @param width width of the crop
                 * @param height height of the crop
                 */
                virtual void setCrop(int x, int y, int width, int height) = 0;

                /**
                 * @brief Set the Color object
                 * 
                 * @param r red
                 * @param g green
                 * @param b blue
                 */
                virtual void setColor(unsigned char r, unsigned char g, unsigned char b) = 0;
    };
}


#endif /* !ISPRITEMODULE_HPP_ */