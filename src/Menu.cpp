#include "Menu.hpp"



static int generate_random_number(int lower_limit, int upper_limit) {
    std::random_device rd; // Obtain a random number from hardware
    std::mt19937 gen(rd()); // Seed the generator
    std::uniform_int_distribution<> distr(lower_limit, upper_limit); // Define the range

    return distr(gen); // Generate the random number
}

void menu::moveAllButtons(sf::Vector2f delta)
{
    sf::Vector2f pos;

    for (auto &button : songsButton) {
        pos = button.sprite->getPosition();
        button.sprite->setPosition(sf::Vector2f(pos.x + delta.x, pos.y + delta.y));
    }
}

menu::menu()
{
    int i = 0;
    DIR* dir = opendir("./songs/");
    if (dir != nullptr) {
        struct dirent* entry;
        while ((entry = readdir(dir)) != nullptr) {
            std::string file_name = entry->d_name;
            if (file_name.length() >= 4 && file_name.substr(file_name.length() - 4) == ".txt") {
                button newButton;
                auto txt = std::make_unique<sf::Texture>();
                auto spt = std::make_unique<sf::Sprite>();
                newButton.name = file_name.substr(0, file_name.length() - 4);
                newButton.hover = false;
                newButton.pressed = false;
                txt->loadFromFile("./assets/box" + std::to_string(generate_random_number(1, 6)) + ".png");
                spt->setTexture(*txt);
                spt->setTextureRect(sf::Rect(0, 0, 700, 200));
                spt->setPosition(sf::Vector2f(1420, i * 200));
                newButton.texture = std::move(txt);  // Assign the unique_ptr to newButton
                newButton.sprite = std::move(spt);  // Assign the unique_ptr to newButton

                songsButton.push_back(std::move(newButton));  // Don't forget to store the button
                i++;
            }
        }
        closedir(dir);
    }
    auto txt1 = std::make_unique<sf::Texture>();
    auto spt1 = std::make_unique<sf::Sprite>();
    auto txt2 = std::make_unique<sf::Texture>();
    auto spt2 = std::make_unique<sf::Sprite>();
    txt1->loadFromFile("./assets/tileB");
    txt2->loadFromFile("./assets/tileW");
    spt1->setOrigin(sf::Vector2f(spt1->getTextureRect().width / 2, spt1->getTextureRect().height / 2));
    spt1->setTexture(*txt1);
    spt1->setPosition(sf::Vector2f(1920 / 2, 1080 / 2));
    spt2->setOrigin(sf::Vector2f(spt2->getTextureRect().width / 2, spt2->getTextureRect().height / 2));
    spt2->setTexture(*txt2);
    spt2->setPosition(sf::Vector2f(1920 / 2, 1080 / 2));
}

static void checkForCollisionBox()
{

}

void menu::update()
{
    for (auto &button : songsButton) {

    }
}