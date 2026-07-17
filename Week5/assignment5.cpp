#include <iostream>
#include <string>
#include <cstdlib>

void welcomeMessage();
std::string getPlayerChoice();
std::string getBotChoice();
void playRound(std::string playerMove, std::string botMove,
    int &playerScore, int &botScore);
void displayWinner(int playerScore, int botScore);

int main(){

    // start game (declare variables)
    int playerScore = 0;
    int botScore = 0;

    welcomeMessage();

    // game loop
    for (int rounds = 0; rounds < 3; rounds++){

        // check for early winner 
        if (playerScore >= 2 || botScore >= 2){
            break;
        }

        std::string playerMove = getPlayerChoice();
        std::string botMove = getBotChoice();

        playRound(playerMove, botMove, playerScore, botScore);

        if (playerMove == botMove) {
            rounds--;
        }
    }

    displayWinner(playerScore, botScore);

    return 0;
}

// display welcome message
void welcomeMessage() {
    std::cout << "Welcome to the Rock Paper Scissors Game!" << std::endl;
}

std::string getPlayerChoice() {
    std::string playerMove;

    while (true) {
        // ask for user input 
        std::cout << "Choose rock, paper or scissor: ";
        std::cin >> playerMove;

         if (playerMove == "rock" || playerMove == "paper" || playerMove == "scissor") {
            return playerMove;
         }
         
         std::cout << "Invalid move! Choose rock, paper, or scissor." << std::endl;
    }
}

std::string getBotChoice() {
    // generate bot input 
    int botMove = rand() % 3;

    if (botMove == 0){
        return "rock";
    }
    else if (botMove == 1){
        return "paper";
    }
    else {
        return "scissor";
    }
}

void playRound(std::string playerMove, std::string botMove, int &playerScore, int &botScore) {
    std::cout << "Bot picked: " << botMove << std::endl;
    
    // figure out the score 
    if (playerMove == botMove) {
    std::cout << "Tie. Let's try again!" << std::endl;
    }

    else if (playerMove == "rock" && botMove == "scissor"){
        playerScore++;
        std::cout << "You win this round!" << std::endl;
    }
    else if (playerMove == "paper" && botMove == "rock"){
        playerScore++;
        std::cout << "You win this round!" << std::endl;
    }
    else if (playerMove == "scissor" && botMove == "paper"){
        playerScore++;
        std::cout << "You win this round!" << std::endl;
    }
    else {
        botScore++;
        std::cout << "Oops, you lost this round!" << std::endl;
    }
    
    std::cout << "Score: " << playerScore << "-" << botScore << std::endl;
}

// Declare winner or tie
void displayWinner(int playerScore, int botScore) {
    if (playerScore > botScore){
        std::cout << "Player wins!" << std::endl;
    }
    else if (botScore > playerScore){
        std::cout << "Bot wins!" << std::endl;
    }
    else {
        std::cout << "Tie!" << std::endl;
    }
}