#include "file.h"
#include <iostream>
#include <string>
#include <fstream>

int file::retLine(const std::string &filename){
    std::ifstream i(filename);
    if(!i){
        std::cerr << "Error reading lines!";
    }
    int numLine = 0;
    std::string temp;
    while(std::getline(i, temp)){
        numLine++;
    }
    i.close();
    return numLine;
}

void file::writeFile(const std::string &filename){
    std::fstream f(filename, std::ios::app);
    if(!f){
        std::cerr << "Error while opening the file!\n";
        return;
    }
    std::cout << "Start typing your text!\n";
    std::cout << "Type 'EXIT' to stop!\n";
    while(1){
        std::cout << ">>";
        std::getline(std::cin, line);

        if(line == "EXIT"){
            std::cout << "Exiting write mode!\n";
            break;
        }
        else{
            f << line << "\n";
        }
    }
    f.close();
}

void file::displayFile(const std::string &filename){
    std::ifstream i(filename);
    if(!i){
        std::cerr << "Error while displaying the file!\n";
        return;
    }
    std::cout << "Current file content!\n";
    std::string temp;
    while(std::getline(i, temp)){
        std::cout << temp << "\n";
    }
    i.close();
}

void file::editFile(const std::string &filename, int editLine, std::string &newLine){
    std::string temp;
    int curr = 1;
    int totalLines = retLine(filename);

    if(editLine < 1 || editLine > totalLines){
        std::cerr << "The line " << editLine << " doesn't exist in the file!\n";
        return;
    }

    std::ifstream i(filename);
    std::ofstream o("temp.txt");

    if(!i || !o){
        std::cerr << "Error while editing the line!\n";
        return;
    }

    while(std::getline(i, temp)){
        if(curr == editLine){
            o << newLine << "\n";
        }
        else{
            o << temp << "\n";
        }
        curr++;
    }
    i.close();
    o.close();

    std::remove(filename.c_str());
    std::rename("temp.txt", filename.c_str());

    std::cout << "Successfully edited line number " << editLine << " with the new line \"" << newLine <<"\"" << std::endl;
}

void file::optionFile(int opt){
    std::string filename, newLine;
    int editLine;
    switch (opt){
        case 1:
            std::cout << "Enter the filename: ";
            std::cin.ignore();
            std::getline(std::cin, filename);
            writeFile(filename);
            break;

        case 2:
            std::cout << "Enter the filename: ";
            std::cin.ignore();
            std::getline(std::cin, filename);
            displayFile(filename);
            break; 

        case 3:
            std::cout << "Enter the filename: ";
            std::cin.ignore();
            std::getline(std::cin, filename);
            std::cout << "Enter the line which you want to edit: ";
            std::cin >> editLine;

            if (editLine < 1 || editLine > retLine(filename)) {
                std::cerr << "The line " << editLine << " doesn't exist in the file!\n";
                break;
            }
            std::cin.ignore();
            std::cout << "Enter the content to replace the line with: ";
            std::getline(std::cin, newLine);
            editFile(filename, editLine, newLine);
            break;

        case 4:
            std::cout << "Thanks for using this program!\n";
            break;

        default:
            std::cout << "Invalid option. Please try again!\n";
            break;
    }
}
