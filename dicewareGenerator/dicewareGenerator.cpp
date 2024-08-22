#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <time.h>


std::string pswordGenerator(int length){
    std::string psword = "";
    srand(time(NULL));
    for(int i = 0; i < length; i++){
        std::string input = "";
        for(int i = 0; i < 5; i++){
            input += std::to_string(rand() % 6 + 1);
        }
        std::string line, word;
        std::ifstream file("dicewareSample2.txt");
        while(getline(file, line)){
            std::istringstream iss(line);
            iss >> word;
            if(word == input){
                iss >> word;
                psword += word + " ";
                break;
            }
        }
        file.close();
    }
    return psword;
}




int main(){
    int length;
    while(true){
        do {
            std::cout << "How many words should the password have? (the password should have at least 2 words) ";
            std::cin >> length;
        }while (length < 2);
        std::cout << "Your password is: " << pswordGenerator(length);
        std::cin.ignore();
        getchar();
    }
}