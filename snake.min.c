#include"s.h"
#define m(x,y) m[y][x]
#define n(x,y,c) if(c=='w')--y;if(c=='s')++y;\
    if(c=='a')--x;if(c=='d')++x;
char m(20,20);
int main(){
    char k;
    int hx=0,hy=0;
    int tx=0,ty=0;
    int fx=1,fy=0;
    m(0,0)=k='d';
    t(0,0,'#');
    while(1){
        while(kbhit())k=getch();
        m(hx,hy)=k;
        n(hx,hy,m(hx,hy));
        t(hx,hy,'#');
        if(hx==fx&&hy==fy){
            fx=rand()%10;
            fy=rand()%10;
            t(fx,fy,'*');
        }else{
            t(tx,ty,' ');
            n(tx,ty,m(tx,ty));
        }
        t(0,10,'\n');
        Sleep(500);
    }
}
