//Assignment 2

#include <iostream>
#include <string>
#include <cstdlib>

int main(){

    // start game (declare variables)
    int player_score = 0;
    int bot_score = 0;
    std::string player_move = "";
    int bot_move = 0;
    std::string bot_pick = ""; 

    std::cout << "Welcome to the Rock Paper Scissors Game!" << std::endl;

    // game loop
    for (int rounds = 0; rounds < 3; rounds++){

        // check for early winner 
        if (player_score >= 2 || bot_score >= 2){
            break;
        }

        // ask for user input 
        std::cout << "Choose rock, paper or scissor: ";
        std::cin >> player_move;

        if (player_move != "rock" && player_move != "paper" && player_move != "scissor") {
            std::cout << "Invalid move! Choose rock, paper, or scissor." << std::endl;
            rounds--;
            continue;
        }

        // generate bot input 
        bot_move = rand() % 3;

        if (bot_move == 0){
            bot_pick = "rock";
        }
        else if (bot_move == 1){
            bot_pick = "paper";
        }
        else {
            bot_pick = "scissor";
        }

        std::cout << "Bot picked: " << bot_pick << std::endl;

        // figure out the score 
        if (player_move == bot_pick){
            std::cout << "Tie. Let's try again!" << std::endl;
            rounds--;
        }
        else if (player_move == "rock" && bot_pick == "scissor"){
            player_score++;
            std::cout << "You win this round!" << std::endl;
        }
        else if (player_move == "paper" && bot_pick == "rock"){
            player_score++;
            std::cout << "You win this round!" << std::endl;
        }
        else if (player_move == "scissor" && bot_pick == "paper"){
            player_score++;
            std::cout << "You win this round!" << std::endl;
        }
        else {
            bot_score++;
            std::cout << "Oops, you lost this round!" << std::endl;
        }

        std::cout << "Score: " << player_score << "-" << bot_score << std::endl;
    }


    // Declare winner or tie
    if (player_score > bot_score){
        std::cout << "Player wins!" << std::endl;
    }
    else if (bot_score > player_score){
        std::cout << "Bot wins!" << std::endl;
    }
    else {
        std::cout << "Tie!" << std::endl;
    }
}