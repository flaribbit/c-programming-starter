#include"s.h"
#define m(x,y) m[y][x]
#define n(x,y,c) l=c;y+=(l=='s')-(l=='w');x+=(l=='d')-(l=='a');
char m(20,10);
int main(){
    char k,l;
    int a=0,b=0,c=0,d=0,e=1,f=0;
    m(0,0)=k='d';
    t(0,0,'#');
    for(;;){
        while(kbhit())k=getch();
        m(a,b)=k;
        n(a,b,m(a,b));
        t(a,b,'#');
        if(a==e&&b==f){
            e=rand()%10,f=rand()%10;
            t(e,f,'*');
        }else{
            t(c,d,' ');
            n(c,d,m(c,d));
        }
        t(0,10,'\n');
        Sleep(250);
    }
}
