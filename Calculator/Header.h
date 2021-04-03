#pragma warning(disable : 6054)

#include <stdio.h> // printf, scanf_s, fgets, stdin, FILE
#include <stdlib.h> // system
#include <string.h> // strcmp
#include <stdbool.h> // bool
#include <Windows.h> // GetStdHandle, SetConsoleTextAttribute
#include <errno.h> // errno_t

#define STR_LEN 50
#define BLACK 0
#define RED 4
#define WHITE 15
#define SETCOLOR(COLOR) SetConsoleTextAttribute(hConsole, (WORD)((WHITE << 4) | COLOR));

void sign_up();
void log_in();
void authorization();