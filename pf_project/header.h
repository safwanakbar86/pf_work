#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>
#include <Windows.h>

using namespace std;

int board[4][4];
int userscore;
int highscore;
int nofill = 1;

ifstream read;
ofstream write;
