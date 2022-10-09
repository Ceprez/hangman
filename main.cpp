#include <iostream>
#include <vector>

void menu();
void userInput();
void secondMenu();
void guess();
std::string userWord;
int lives = 10;

int main() {

    menu();
    userInput();
    secondMenu();

    return 0;
}

void menu(){
    std::cout << "=================" << std::endl;
    std::cout << "=====HANGMAN=====" << std::endl;
    std::cout << "=================" << std::endl;
    std::cout << std::endl;
    std::cout << "Welcome to Hangman!" << std::endl;
    std::cout << std::endl;
}


void userInput(){
    std::cout << "Enter a word: ";
    std::cin >> userWord;
    system("clear");
}

std::vector<char> result;

void secondMenu(){
    int userChoice;
    std::cout << std::endl;
    std::cout << "1. Guess the word" << std::endl;
    std::cout << "2. Exit" << std::endl;
    std::cout << "Your Choice: ";
    std::cin >> userChoice;

    for(int i = 0; i < userWord.size(); i++){
        result.push_back('_');
    }

    switch (userChoice) {
        case 1:{
            guess();
            break;
        }
        case 2:{
            exit(0);
        }
        default:{
            std::cout << "Enter number 1-2" << std::endl;
            secondMenu();
        }
    }
}


void guess(){

    int check = 0;
    int finish = 0;
    int correct = 0;

    for(int i = 0; i < userWord.size(); i++){
        std::cout << result[i];
    }
    std::cout << std::endl;

    char userGuess;
    std::cout << "Enter a letter: ";
    std::cin >> userGuess;

    if (lives == 0){
        std::cout << "You lost!" << std::endl;
        std::cout << "Word: " << userWord << std::endl;
        exit(0);
    }

    for(int i = 0; i < userWord.size(); i++){
        if (userGuess == userWord[i]){
            correct = 1;
            result[i] = userGuess;
            check = 1;
        }
    }

    if (correct == 1){
        std::cout << std::endl;
        std::cout << "Correct!" << std::endl;
        std::cout << std::endl;
    }

    if (check != 1) {
        std::cout << std::endl;
        std::cout << "Incorrect!" << std::endl;
        lives--;
        std::cout << "You have " << lives << " lives left!" << std::endl;
        std::cout << std::endl;
        guess();
    }

    for(int i = 0; i < result.size(); i++){
        if (result[i] == '_'){
            finish = 0;
            break;
        }
        else{
            finish = 1;
        }
    }
    if (finish == 1){
        std::cout << std::endl;
        for(int i = 0; i < userWord.size(); i++){
            std::cout << result[i];
        }
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "YOU WON!" << std::endl;
        std::cout << std::endl;
        exit(0);
    }

    guess();

}