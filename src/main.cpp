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
#include "Scene.hpp"

using namespace std;

int main()
{
    std::shared_ptr<SFML> sfml = std::make_shared<SFML>();
    //std::map<std::string, std::shared_ptr<SFML::Sounds>> sounds;
    //sounds = sfml->getSounds();
    Scene scene("./songs/crazyfrog", sfml);
    // Scene scene("./songs/Unravel _Tokyo_Ghoul_OP_Piano", sfml);
    scene.loop();

    //! TESTS FOR AUDIO

    // for (auto& sound : sounds) {
    //     cout << "playing: " << sound.first << endl;
    //     sfml.playSound(sound.first);
    // }

    // for (auto &line : lines) {
    //     cout << line << endl;
    //     if (line.find('1') != std::string::npos) {
    //         sfml.playSound("fa");
    //     } else sfml.playSound("si");
    // }

    // sfml.loadMusic("eterna-cancao-wav-12569.wav");
    // sfml.playMusic("eterna-cancao-wav-12569.wav");

    //sfml.loop();

    return 0;
}
