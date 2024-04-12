#include "header.h"
#include "printboard.h"
#include "menu.h"
#include "swipeup.h"
#include "swipedown.h"
#include "swipeleft.h"
#include "swiperight.h"
#include "newgame.h"
#include "number.h"
#include "fillboard.h"
#include "check.h"
#include "score.h"
#include "winPredictor.h"

void printboard();
void menu();
void swipeup();
void swipedown();
void swipeleft();
void swiperight();
void newgame();
int number();
void fillboard();
int check();
void score(char option);
void winPredictor();


int main()
{
    read.open("highscore.txt");
    read >> highscore;
    read.close();

    int won = 0;
    newgame();
    char func;

    while (true)
    {
        system("cls");
        cout << endl << endl;

       // if (::nofill != 0)
            fillboard();
        //::nofill = 0;

        printboard();
        score('?');
        winPredictor();
        menu();

    incaseofinvalid:cin >> func;
        switch (func)
        {
        case 'n':
        {
            newgame();
            fillboard();
            score('n');
            break;
        }

        case 'u':
        {
            swipeup();
            break;
        }

        case 'd':
        {
            swipedown();
            break;
        }

        case 'l':
        {
            swipeleft();
            break;
        }

        case 'r':
        {
            swiperight();
            break;
        }

        case 'q':
        {
            cout << "Thank you for playing! \n";
            return 0;
        }

        default:
        {
            cout << "Invalid input!" << endl << "Input again:";
            goto incaseofinvalid;
            break;
        }
        }

        won = check();
        if (won == 1)
        {
            cout << "Congrats you have won the game :) \n";
            break;
        }

        if (won == 2)
        {
            cout << "You have failed this game (reference: green arrow) \n";
            break;
        }
    }
    return 0;
}


void menu()
{
    cout << "\nInstructions:\n\nn: New Game\nl: Swipe Left\nr: Swipe Right\nu: Swipe Up\nd: Swipe Down\nq: Quit Game\n\nEnter your move: ";
}


void newgame()
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            board[i][j] = 0;
}


void printboard()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int i = 0; i < 4; i++)
    {
        if (i == 0)
            cout << "\t \t-------------------------" << endl;

        cout << "\t\t" << "|";
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == 0)
                cout << setw(5) << " ";

            else if (board[i][j] == 1)
            {
                SetConsoleTextAttribute(h, 142);
                cout << setw(3) << board[i][j] << "  ";
                
            }


            else if (board[i][j] == 2)
            {
                SetConsoleTextAttribute(h, 63);
                cout << setw(3) << board[i][j] << "  ";
                
       
            }

            else if (board[i][j] == 4)
            {
                SetConsoleTextAttribute(h, 233);
                cout << setw(3)  << "  ";
                
            }


            else if (board[i][j] == 8)
            {
                SetConsoleTextAttribute(h, 207);
                cout << setw(3) << board[i][j] << "  ";
            }


            else if (board[i][j] == 16)
            {
                SetConsoleTextAttribute(h, 46);
                cout << setw(3) << board[i][j] << "  ";
            }


            else if (board[i][j] == 32)
            {
                SetConsoleTextAttribute(h, 222);
                cout << setw(3) << board[i][j] << "  ";
            }


            else if (board[i][j] == 64)
            {
                SetConsoleTextAttribute(h, 74);
                cout << setw(3) << board[i][j] << "  ";
            }


            else if (board[i][j] == 128)
            {
                SetConsoleTextAttribute(h, 158);
                cout << setw(4) << board[i][j] << ' ';
            }


            else if (board[i][j] == 256)
            {
                SetConsoleTextAttribute(h, 11);
                cout << setw(4) << board[i][j] << ' ';
            }


            else if (board[i][j] == 512)
            {
                SetConsoleTextAttribute(h, 181);
                cout << setw(4) << board[i][j] << ' ';
            }

            else if (board[i][j] == 1024)
            {
                SetConsoleTextAttribute(h, 110);
                cout << setw(4) << board[i][j] << ' ';
            }

            SetConsoleTextAttribute(h, 15);

            cout << "|";
        }
        cout << endl << "\t \t-------------------------" << endl;
    }
}


void swipeleft() {
    // for shifting
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == 0)
            {
                for (int k = j; k < 3; k++)
                {
                    if (board[i][k + 1] != 0)
                    {
                        board[i][j] = board[i][k + 1];
                        board[i][k + 1] = 0;
                        ::nofill++;
                        break;
                    }
                }
            }
        }
    }

    // for adding
    for (int q = 0; q < 4; q++)
    {
        for (int p = 0; p < 3; p++)
        {
            if (board[q][p] == board[q][p + 1] && board[q][p] != 0 && board[q][p + 1] != 0)
            {
                ::nofill++;
                userscore = userscore + board[q][p] + board[q][p + 1];
                board[q][p] += board[q][p + 1];
                board[q][p + 1] = 0;
                for (int t = p + 1; t < 3; t++)
                {
                    board[q][t] = board[q][t + 1];
                    board[q][t + 1] = 0;
                }
            }
        }
    }
}


void swiperight()
{
    // for shifting
    for (int i = 3; i >= 0; i--)
    {
        for (int j = 3; j >= 0; j--)
        {
            if (board[i][j] == 0)
            {
                for (int k = j; k > 0; k--)
                {
                    if (board[i][k - 1] != 0)
                    {
                        board[i][j] = board[i][k - 1];
                        board[i][k - 1] = 0;
                        ::nofill++;
                        break;
                    }
                }
            }
        }
    }

    //  for adding the same numbers
    for (int q = 3; q >= 0; q--)
    {
        for (int p = 3; p > 0; p--)
        {
            if (board[q][p] == board[q][p - 1] && board[q][p] != 0 && board[q][p - 1] != 0)
            {
                ::nofill++;
                userscore = userscore + board[q][p] + board[q][p - 1];
                board[q][p] += board[q][p - 1];
                board[q][p - 1] = 0;
                for (int t = p - 1; t > 0; t--)
                {
                    board[q][t] = board[q][t - 1];
                    board[q][t - 1] = 0;
                }
            }
        }
    }
}


void swipedown()
{
    // for shifting
    for (int j = 3; j >= 0; j--)
    {
        for (int i = 3; i >= 0; i--)
        {
            if (board[i][j] == 0)
            {
                for (int k = i; k > 0; k--)
                {
                    if (board[k - 1][j] != 0)
                    {
                        board[i][j] = board[k - 1][j];
                        board[k - 1][j] = 0;
                        ::nofill++;
                        break;
                    }

                }
            }
        }
    }


    // for adding
    for (int q = 3; q >= 0; q--)
    {
        for (int p = 3; p >= 0; p--)
        {
            if (board[p][q] == board[p - 1][q] && board[p][q] != 0 && board[p - 1][q] != 0)
            {
                ::nofill++;
                userscore = userscore + board[p][q] + board[p - 1][q];
                board[p][q] += board[p - 1][q];
                board[p - 1][q] = 0;
                for (int t = p - 1; t > 0; t--)
                {
                    board[t][q] = board[t - 1][q];
                    board[t - 1][q] = 0;
                }
            }
        }
    }
}


void swipeup()
{
    // for shifting
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            if (board[i][j] == 0)
            {
                for (int k = i; k < 3; k++)
                {
                    if (board[k + 1][j] != 0)
                    {
                        board[i][j] = board[k + 1][j];
                        board[k + 1][j] = 0;
                        ::nofill++;
                        break;
                    }
                }
            }
        }
    }

    // for adding
    for (int q = 0; q < 4; q++)
    {
        for (int p = 0; p < 4; p++)
        {
            if (board[p][q] == board[p + 1][q] && board[p][q] != 0 && board[p + 1][q] != 0)
            {
                ::nofill++;
                userscore = userscore + board[p][q] + board[p + 1][q];
                board[p][q] += board[p + 1][q];
                board[p + 1][q] = 0;
                for (int t = p + 1; t < 3; t++)
                {
                    board[t][q] = board[t + 1][q];
                    board[t + 1][q] = 0;
                }
            }
        }
    }
}


void fillboard()
{
    srand(time(0));
    int n = number(), row, col;

    while (true)
    {
        row = rand() % 4;
        col = rand() % 4;

        if (board[row][col] == 0)
        {
            board[row][col] = n;
            break;
        }
    }
}


int number()
{
    srand(time(0));
    return rand() % 2 + 1;
}


int check()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == 1024)
                return 1;
        }
    }

    for (int k = 0; k < 4; k++)
    {
        for (int l = 0; l < 4; l++)
        {
            if (board[k][l] == 0)
                return 0;
        }
    }
    return 2;
}


void score(char option)
{
    if (option == 'n')
        userscore = 0;

    else
    {
        cout << "\nScore = " << userscore << endl;
        if (userscore > highscore)
        {
            highscore = userscore;
            write.open("highscore.txt");
            write << highscore;
            write.close();
        }
        cout << "High Score = " << highscore << endl;
    }
}


void winPredictor()
{
    double ratio, max = 1039, maxuser = 0, empty = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] > maxuser)maxuser = board[i][j];
            if (board[i][j] == 0)empty++;
        }
    }
    ratio = (maxuser + static_cast<double>(empty)) / max;
    cout << "Winning Chances: " << ratio * 100 << "%" << endl;
}
