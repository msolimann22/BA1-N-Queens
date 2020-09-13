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
    int getsize()
    {
        return boardSize;
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
class Queens
{
private:
    int RowPos, ColPos;
    int BoardSize;
public:
    Board Ava;
    Queens()
    {
        BoardSize = Ava.getsize();


    }
    bool Availability(int board[])
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





bool checkSpaces(Queens* queens, int numQueens, int a, int b, int N) {

	for (int k = 0; k < numQueens; k++) {

		int x = queens[k].RowPos;
		int y = queens[k].ColPos;

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