#include <iostream>
#include <string.h>

using namespace std;

class Queens
{
private:
    int RowPos, ColPos;
    int BoardSize;
public:
    //Constructor
    Queens(){
        //Board Ava;
       // BoardSize = Ava.getsize();
    }
    //Destructor
    ~Queens() {
    }
    //Modifiers
    void setRow(int row) {
        RowPos = row;
    }
    void setColumn(int col) {
        ColPos = col;
    }

    //Getters
    int getRow() {
        return RowPos;
    }
    int getCol() {
        return ColPos;
    }

    //functions
    
    /* bool Availability(int board[])
    {
        for (int i = 0; i < BoardSize; i++)
        {
            RowPos = board[i];
            if (RowPos)
            {
                return false;
            }

        }
        for (int i = 0; i < BoardSize; i++)
        {
            for (int j = 0; j < BoardSize; j++)
            {
                ColPos = board[i][j];
                if (ColPos)
                {

                }
            }
        }
    } */

};
class Board {
private:
    int boardSize;
    char** board;
    Queens queen;
public:
    //Constructors
    Board() {
        board = new char* [boardSize];
        for (int i = 0; i < boardSize; i++)
            board[i] = new char[boardSize];
        for (int i = 0; i < boardSize; i++) {
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
                board[i][j] = '-';
        }
    }
    //Destructor
    ~Board() {
        for (int i = 0; i < boardSize; i++)
            delete[] board[i];
        delete[] board;
    }
    //Getters
    int getsize()
    {
        return boardSize;
    }
    //Functions
    void print_board() {
        for (int i = 0; i < boardSize; i++) {
            for (int j = 0; j < boardSize; j++) {
                std::cout << board[i][j] << "|";
            }
            std::cout << "\n";
        }
    }
    void input_queen(int row, int col) {
        board[row][col] = 'Q';
    }
};

//functions to check if the space is available or not
//pass array of queens and their number and the position in the board =  a,b and size of the board = N
bool checkSpaces(Queens* queens, int numQueens, int a, int b, int N);

//function to check number of spaces that will be taken, pass position of queen = x,y and size of board N.
int findSpaces(int x, int y, int N);


int main()
{
    int N;
    cout << "Please enter size of board: ";
    cin >> N;

    Queens queen;
    Board playing_board(N);

    playing_board.input_queen(3, 3);
    playing_board.input_queen(6, 6);

    playing_board.print_board();


    return 0;

}

bool checkSpaces(Queens* queens, int numQueens, int a, int b, int N) {

    for (int k = 0; k < numQueens; k++) {

        int x = queens[k].getRow();
        int y = queens[k].getCol();

        if (a == x || b == y) {
            return false;
        }

        for (int i = 1; i < N + 1; i++) {
            if (((x + i) < N) && ((y + i) < N)) {
                if (((x + i) == a) && ((y + i) == b)) {
                    return false;
                }
            }
            else
                break;
        }

        for (int i = 1; i < N + 1; i++) {
            if (((x - i) >= 0) && ((y - i) >= 0)) {
                if (((x - i) == a) && ((y - i) == b)) {
                    return false;
                }
            }
            else
                break;
        }


        for (int i = 1; i < N + 1; i++) {
            if (((x + i) < N) && ((y - i) >= 0)) {
                if (((x + i) == a) && ((y - i) == b)) {
                    return false;
                }
            }
            else
                break;
        }


        for (int i = 1; i < N + 1; i++) {
            if (((x - i) >= 0) && ((y + i) < N)) {
                if (((x - i) == a) && ((y + i) == b)) {
                    return false;
                }
            }
            else
                break;
        }
    }


    return true;
}



int findSpaces(int x, int y, int N) {
    int spaces = 0;
    spaces += (2 * N);
    spaces--;

    for (int i = 1; i < N + 1; i++) {
        if (((x + i) < N) && ((y + i) < N))
            spaces++;
        else
            break;
    }

    for (int i = 1; i < N + 1; i++) {
        if (((x - i) >= 0) && ((y - i) >= 0))
            spaces++;
        else
            break;
    }


    for (int i = 1; i < N + 1; i++) {
        if (((x + i) < N) && ((y - i) >= 0))
            spaces++;
        else
            break;
    }


    for (int i = 1; i < N + 1; i++) {
        if (((x - i) >= 0) && ((y + i) < N))
            spaces++;
        else
            break;
    }


    return spaces;
}
// I approve this code - Youssef Ezzeldin