/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Workspace)
** File description:
** Scene
*/

#include "../include/Scene.hpp"

Scene::Scene() {}
Scene::~Scene() {}

void Scene::startLevel(std::string configFile)
{
    Parser parser;
    parser.parseFile(configFile);
    
}

void Scene::loop(void)
{

}

int Scene::endLevel(void)
{

}
