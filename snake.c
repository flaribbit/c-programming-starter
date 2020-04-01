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
char map[10][20];
int main(){
    char key;
    int hx=0,hy=0;//头的坐标
    int tx=0,ty=0;//尾巴的坐标
    int fx=1,fy=0;//食物的坐标
    map[0][0]=key='d';//必要的初始化
    printf("#");
    while(1){
        while(kbhit())key=getch();//获得按键
        map[hy][hx]=key;//把当前按键保存在地图里，决定身子的移动方向
        move(&hx,&hy,map[hy][hx]);//移动身子
        gotoxy(hx,hy);putchar('#');//刷新身子
        if(hx==fx&&hy==fy){//如果吃到了实物
            fx=rand()%20;
            fy=rand()%10;//随机数
            gotoxy(fx,fy);putchar('*');//刷新一个新的食物
        }else{//吃到食物尾巴不移动，没吃到才要移动
            gotoxy(tx,ty);putchar(' ');//刷新身子
            move(&tx,&ty,map[ty][tx]);//移动尾巴
        }
        gotoxy(0,10);putchar('\n');//刷新画面
        Sleep(500);
    }
}
