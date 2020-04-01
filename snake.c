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
    int hx=0,hy=0;
    int tx=0,ty=0;
    int fx=1,fy=0;
    map[0][0]=key='d';
    printf("#");
    while(1){
        while(kbhit())key=getch();
        map[hy][hx]=key;
        move(&hx,&hy,map[hy][hx]);
        gotoxy(hx,hy);putchar('#');
        if(hx==fx&&hy==fy){
            fx=rand()%10;
            fy=rand()%10;
            gotoxy(fx,fy);putchar('*');
        }else{
            gotoxy(tx,ty);putchar(' ');
            move(&tx,&ty,map[ty][tx]);
        }
        gotoxy(0,10);putchar('\n');
        Sleep(500);
    }
}
