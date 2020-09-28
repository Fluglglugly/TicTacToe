

#include <iostream>
#include <string>

//Defines what string-value should be used fro the different players, and the string values that I change when making a move
std::string Player[2] = { " X "," O " };
std::string A[3] = { "   ","   ","   " };
std::string B[3] = { "   ","   ","   " };
std::string C[3] = { "   ","   ","   " };
//Counter is just a counter that alternates between 1 and 0, exept for when the game is over, when it goes above 1, thereby breaking the loop
int Counter = 0;
int TurnTimer = 0;


void func_Board() {
        std::cout << "   A   B   C\n";
        std::cout << "1|" << A[0] << "|" << B[0] << "|" << C[0] << "|\n";
        std::cout << "2|" << A[1] << "|" << B[1] << "|" << C[1] << "|\n";
        std::cout << "3|" << A[2] << "|" << B[2] << "|" << C[2] << "|\n";
}

void func_Turn() {
    char Letter = 'E';
    int Number = 0;
    std::cout << "Player"<<Player[Counter]<<"make a move\n"; //this is where Counter decides which players turn it is
    std::cin >> Letter >> Number;
    if (Letter == 'A') {
        A[Number - 1] = Player[Counter];
    }
    else if (Letter == 'B') {
        B[Number - 1] = Player[Counter];
    }
    else if (Letter == 'C') {
        C[Number - 1] = Player[Counter];
    }
    TurnTimer += 1; //Is used to decide if all tiles should be filled in and the game should end. I know there are better ways, but I'm lazy and it works
    func_Board();

}


void func_Win() {
    std::cout << "Player " << Player[Counter] << "won!";
    Counter += 4;

}


//Wanted to loop through the variables as well as the numbers, but wasn't sure how to do it without making the variable names into a string, meaning they won't call the value I've assigned them
//Is there a good way of looping thorugh different defined variables?

void func_WinCondition() {
    int D = 0;
    while (D < 3) {
        if (A[D] != "   " & A[D] == B[D] & A[D] == C[D]) {
            func_Win();
        }
        D += 1;
    }
    //I'm supposed to write comments here, but not sure what to write other than the fact that I'm defining what the winconditions are and what to do if they are met...
    //Includes the statement above this comment
    if (A[0] != "   " & A[0] == A[1] & A[1] == A[2]) {
        func_Win();

    }
    else if (B[0] != "   " & B[0] == B[1] & B[1] == B[2]) {
        func_Win();
    }
    else if (C[0] != "   " & C[0] == C[1] & C[1] == C[2]) {
        func_Win();
    }
    else if (A[0] != "   " & A[0] == B[1] & B[1] == C[2]) {
        func_Win();
    }
    else if (A[2] != "   " & A[2] == B[1] & B[1] == C[0]) {
        func_Win();
    }
    else if (TurnTimer == 9) {
        std::cout << "It's a draw!";
        Counter += 4;
    }
    
}



int main()
{
    func_Board();
    while (Counter < 2) //runs the game
    {
        func_Turn(); //runs a single turn
        func_WinCondition(); //checks if anyone won
        if (Counter == 0){ //decides whos turn it is
            Counter += 1;
        }
        else if (Counter == 1) {
            Counter -= 1;
        }
        //I'm too lazy to loop the game, if you want to play again, relauch the game
    }
    
}

