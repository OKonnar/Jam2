#ifndef D8FD8845_5CBB_4256_96AF_3918578291E0
#define D8FD8845_5CBB_4256_96AF_3918578291E0

#include <vector>
#include <string>
#include <cstring>
#include <dirent.h>
#include <memory>
#include <random>
#include <SFML/Graphics.hpp>

struct button
{
    std::string name;
    std::unique_ptr<sf::Sprite> sprite;
    std::unique_ptr<sf::Texture> texture;
    bool hover;
    bool pressed;
};

struct sprite
{
    std::unique_ptr<sf::Sprite> sprite;
    std::unique_ptr<sf::Texture> texture;
};

class menu
{
    private:
        std::vector<button> songsButton;
        void moveAllButtons(sf::Vector2f delta);
        sprite background1;
        sprite background2;

    public:
        menu();
        void update();
};

#endif /* D8FD8845_5CBB_4256_96AF_3918578291E0 */
