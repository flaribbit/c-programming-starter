#include <conio.h>
#include <stdio.h>
#include <windows.h>
void t(char x,char y,char c){
    HANDLE handle;
    COORD coord;
    coord.X = x;
    coord.Y = y;
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(handle, coord);
    putchar(c);
}
