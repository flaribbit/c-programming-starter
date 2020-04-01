#include <conio.h>
#include <stdio.h>
#include <windows.h>
void gotoxy(int x, int y)
{  
    HANDLE handle;
    COORD coord;
    coord.X = x;
    coord.Y = y;
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(handle, coord);
}
void move(int *x,int *y,char c){
    if(c=='w')--*y;
    if(c=='s')++*y;
    if(c=='a')--*x;
    if(c=='d')++*x;
}
char map[20][20];
int main(){
    char key;
    int hx=1,hy=0;
    int tx=0,ty=0;
    map[0][0]=map[0][1]=key='d';
    printf("##");
    while(1){
        while(kbhit())key=getch();
        gotoxy(tx,ty);putchar(' ');
        move(&tx,&ty,map[ty][tx]);
        map[hy][hx]=key;
        move(&hx,&hy,map[hy][hx]);
        gotoxy(hx,hy);putchar('#');
        gotoxy(0,10);putchar('\n');
        Sleep(500);
    }
}
