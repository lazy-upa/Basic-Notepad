#ifndef FILE_H
#define FILE_H


#include <string>

class file{
    private:
        std::string line;
        int numLine = 0;

    public:
        void writeFile(const std::string &filename);

        void displayFile(const std::string &filename);

        void editFile(const std::string &filename, int editLine, std::string &newLine);

        void optionFile(int opt);

        int retLine(const std::string &filename);
};

#endif