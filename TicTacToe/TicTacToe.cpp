

#include <iostream>
#include <string>
#include <list>
#include <iterator>

std::string Player[2] = { " X "," O " };
std::string A[3] = { "   ","   ","   " };
std::string B[3] = { "   ","   ","   " };
std::string C[3] = { "   ","   ","   " };

int Counter = 0;

void func_Board() {
        std::cout << "   A   B   C\n";
        std::cout << "1|" << A[0] << "|" << B[0] << "|" << C[0] << "|\n";
        std::cout << "2|" << A[1] << "|" << B[1] << "|" << C[1] << "|\n";
        std::cout << "3|" << A[2] << "|" << B[2] << "|" << C[2] << "|\n";
}

void func_Turn() {
    char Letter = 'E';
    int Number = 0;
    std::cout << "Player"<<Player[Counter]<<"make a move\n";
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

}



int main()
{
    func_Board();
    while (Counter < 3) 
    {
        func_Turn();
        func_WinCondition();
        if (Counter == 0){
            Counter += 1;
        }
        else if (Counter == 1) {
            Counter -= 1;
        }

    }
    
}

