/*
** EPITECH PROJECT, 2023
** jam2
** File description:
** Parsing
*/

#include "Parsing.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

Parsing::Parsing() : _BPM(0), _length(0) {}

Parsing::~Parsing() {}

void Parsing::parseFile(const std::string& fileConfig) {
    std::ifstream inputFile(fileConfig);
    if (!inputFile.is_open()) {
        throw std::runtime_error("Failed to open config file: " + fileConfig);
    }

    std::string line;
    if (std::getline(inputFile, line))
        _fileName = line;
    if (std::getline(inputFile, line))
        _BPM = std::stoi(line);
    if (std::getline(inputFile, line))
        _length = std::stoi(line);
    while (std::getline(inputFile, line))
        _lines.push_back(line);
    inputFile.close();
}

std::vector<int> Parsing::getLine(unsigned int index)
{
    std::vector<int> result;
    if (index < _lines.size()) {
        std::istringstream iss(_lines[index]);
        int value;
        while (iss >> value) {
            result.push_back(value);
        }
    }
    return result;
}
