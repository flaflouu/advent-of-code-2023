#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

//clear an array
void clearArray(int *ptr,int len){
    for(int i=0; i<len; i++){
        *(ptr + i) = 0;
    }
}

//print an array
void printArray(int *ptr, int len){
    for(int i=0; i<len; i++){
        std::cout << *(ptr + i) << ',';
    }
    std::cout << std::endl;
}

//verify the game conditions based on the number of cubes by color
bool isGamePossible(int *ptr){

    if(*ptr > 12 || *(ptr+1) > 13 || *(ptr+2) > 14) return false; 

    return true;
}

int main(int argc, char *argv[]){

    std::ifstream input;
    input.open(argv[1]);

    int cubes[3] = {0,0,0}; //r,g,b
    int sumId = 0;

    std::string line;

    while (std::getline(input, line)){

        std::cout << line << std::endl;
        std::stringstream s_line(line);
        std::string word;
        int number = 0;
        int gameID = 0;

        s_line >> word; //skipping "game" word

        while(s_line >> word){

            std::cout << word << std::endl;


            if(word[word.length()-1] == ':') { //if it's a game id
                word = word.erase(word.length()-1);
                gameID = std::stoi(word);
                clearArray(cubes,3);
                std::cout << gameID << std::endl;
            }
            else if (word[0] >= '0' && word[0] <= '9'){ //if it's a number

                number = std::stoi(word);
            }
            else{ //if it's a color and which one

                if(word[0] == 'r' && cubes[0] < number){
                    cubes[0] = number;
                }
                else if (word[0] == 'g' && cubes[1] < number){
                    cubes[1] = number;
                }
                else if (word[0] == 'b' && cubes[2] < number){
                    cubes[2] = number;
                }
            }

            
        }

        
    if(isGamePossible(cubes)){
        sumId += gameID;
    }
    printArray(cubes,3);

    }
    std::cout << sumId;
}