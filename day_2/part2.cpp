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
std::string ArraytoString(int *ptr, int len){

    std:: string s = "[";

    for(int i=0; i<len; i++){
        s += std::to_string(*(ptr + i)) + ',';
    }

    s[s.length()-1] = ']'; //replace the last coma by a ']'

    return s;
}

//multiplication of all the elements in the array
int power(int *ptr, int len){

    int power = 1;

    for(int i=0; i<len; i++){
        power *= *(ptr + i);
    }

    return power;
}


int main(int argc, char *argv[]){

    std::ifstream input;
    input.open(argv[1]);

    int cubes[3] = {0,0,0}; //r,g,b
    int mult = 0;
    int sum = 0;

    std::string line;

    while (std::getline(input, line)){

        std::cout << line << std::endl;
        std::stringstream s_line(line);
        std::string word;
        int number = 0;
        int gameID = 0;

        s_line >> word; //skipping "game" word

        while(s_line >> word){

            //std::cout << word << std::endl;


            if(word[word.length()-1] == ':') { //if it's a game id
                word = word.erase(word.length()-1);
                gameID = std::stoi(word);
                clearArray(cubes,3);
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


    mult = power(cubes,3);
    sum += mult;

    std::cout << "game ID : " << gameID << std::endl;
    std::cout << "minimum number of cube by color (r,g,b) : " << ArraytoString(cubes,3) << std::endl;
    std::cout << "power of the cube set : " << mult << std:: endl << std::endl;

    }
    std::cout << "sum of all the cube set : " << sum;
}