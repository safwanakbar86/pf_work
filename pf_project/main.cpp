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

        fillboard();

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
