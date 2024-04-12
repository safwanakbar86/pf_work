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
