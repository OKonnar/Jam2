/*
** EPITECH PROJECT, 2023
** jam2
** File description:
** Parsing
*/

#ifndef PARSING_HPP_
#define PARSING_HPP_

#include <vector>
#include <string>

class Parsing {
    public:
        Parsing();
        ~Parsing();

        void parseFile(const std::string& fileConfig);
        int getBPM() {return _BPM;};
        int getLength() {return _length;};
        std::string getFileName() {return _fileName;};
        std::vector<int> getLine(unsigned int index);
        std::vector<std::string> getLines() {return _lines;};

    private:
        int _BPM;
        int _length;
        std::string _fileName;
        std::vector<std::string> _lines;
};

#endif /* !PARSING_HPP_ */
