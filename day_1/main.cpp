#include <fstream>
#include <iostream>

bool isIn(std::string s1, std::string s2){
    int len = s2.length();

    if(s1.length() < s2.length()){
        len = s1.length();
    }

    if(len < 1) return false;

    for (int i=0; i<len; i++){
        if (s1[i] != s2[i]){
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[]){

    std::string line;
    std::string number = "";
    std::string text_number = "";
    int values = 0;
    bool isANumber = false;

    std::string numbers[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int numbers_size = 9;

    std::ifstream input;
    input.open(argv[1]);

    while(std::getline(input, line)){

        for(int i = 0; i<line.length(); i++){


            if(line[i] >= '0' && line[i] <='9'){

                number += line[i];

            }
            else{

                text_number += line[i];
                std::cout << text_number << " ";
                for (int j = 0; j<numbers_size; j++){

                    if (text_number.compare(numbers[j]) == 0){

                        number += '0'+j+1;
                        text_number = "";
                    }
                    else{

                        if (isIn(text_number,numbers[j])){
                            std::cout << " yo ";
                            isANumber = true;
                        }
                    }
                }

                if(!isANumber){

                    text_number = line[i];
                    
                }
                isANumber = false;
                
                
            }
        }

        if(number.length() >= 2){
            number.erase(1,(number.length()-2));
        }
        else if (number.length() == 1){
            number += number;
        }
        else{
            number = "0";
        }
        
        std::cout << line << " : " << number << std::endl;
        values += std::stoi(number);
        number = "";
        
    }
    
    std::cout << values << std::endl;
    input.close();
}