#include <iostream>
#include <string.h>

using namespace std;

class Board {
private:
    int boardSize;
    char** board;
public:
    //Constructors
    Board() {
        board = new char* [boardSize];
        for (int i = 0; i < boardSize; i++)
            board[i] = new char[boardSize];
        for (int i = 0; i < this->boardSize; i++) {
            for (int j = 0; j < boardSize; j++)
                board[i][j] = '-';
        }
    }
    Board(int boardSize) {
        this->boardSize = boardSize;
        board = new char* [boardSize];
        for (int i = 0; i < boardSize; i++)
            board[i] = new char[boardSize];
        for (int i = 0; i < boardSize; i++) {
            for (int j = 0; j < boardSize; j++)
                this->board[i][j] = '-';
        }
    }
    //Destructor
    ~Board() {
        for (int i = 0; i < boardSize; i++)
            delete[] board[i];
        delete[] board;
    }
    void print_board() {
        for (int i = 0; i < boardSize; i++) {
            for (int j = 0; j < boardSize; j++) {
                std::cout << board[i][j] << "|";
            }
            std::cout << "\n";
        }
    }
};

int main()
{
    int N;
    cout << "Please enter size of board: ";
    cin >> N;

    Board playing_board(N);
    playing_board.print_board();

    /*  for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if ()
        }

    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)

            cout << [i][j];
    }

    for (int i = 0; i < N; i++)
        delete[] * (board + i);
    delete[] board

    return 0; */

}