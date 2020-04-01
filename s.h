// #include <conio.h>
// #include <stdio.h>
// #include <stdlib.h>
#include <windows.h>
void t(char x,char y,char c){
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y});
    putchar(c);
}
