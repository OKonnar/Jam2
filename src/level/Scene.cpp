/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Workspace)
** File description:
** Scene
*/

#include "Scene.hpp"

using namespace std;

Scene::Scene() {}
Scene::~Scene() {}

void Scene::startLevel(string configFile, shared_ptr<SFML> sfml)
{
    _sfml = sfml;
    Parsing parser;
    parser.parseFile(configFile);
    _levelMusic = parser.getFileName();
    _bpm = parser.getBPM();
    //create all sprites of the background

}

void Scene::loop(void)
{
    bool running = true;
    _sfml->playSound(_levelMusic);
    float yByBeat = TILESIZE * _bpm / 60;

    while (running) {
        //handle events, remove tiles that have been catched
        //read config file and add new tiles
        //remove tiles that are off screen
        _sfml->clear();
        for (vector<sf::Sprite>::iterator it = _sprites.begin(); it != _sprites.end(); it++)
            _sfml->updateSprite(*it);
        for (vector<sf::RectangleShape>::iterator it = _rectangles.begin(); it != _rectangles.end(); it++)
            _sfml->updateSprite(*it, sf::Vector2f(it->getSize().x, it->getSize().y + yByBeat));
        _sfml->display();
    }
}

int Scene::endLevel(void)
{

}
