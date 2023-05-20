/*
** EPITECH PROJECT, 2022
** Jam2
** File description:
** main.cpp
*/

#include <map>

#include "Object.hpp"
#include "SFML.hpp"
#include "Parsing.hpp"

using namespace std;

int main()
{
    SFML sfml;
    Parsing parser;

    parser.parseFile("assets/exampleconfig");
    std::vector<std::string> lines = parser.getLines();

    std::map<std::string, std::shared_ptr<SFML::Sounds>> sounds;
    sfml.loadSounds();
    sounds = sfml.getSounds();

    // for (auto& sound : sounds) {
    //     cout << "playing: " << sound.first << endl;
    //     sfml.playSound(sound.first);
    // }



    for (auto &line : lines) {
        cout << line << endl;
        if (line.find('1') != std::string::npos) {
            sfml.playSound("do");
        }
    }

    sfml.loop();

    return 0;
}
