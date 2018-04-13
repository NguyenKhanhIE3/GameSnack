#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std ;
# define width 85
#define height 20

void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = {0,0};
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut,' ',csbiInfo.dwSize.X * csbiInfo.dwSize.Y,Home,&dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut,csbiInfo.dwCursorPosition);
}


//screen: goto [x,y]
void gotoXY (int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}




enum Trangthai{up,down,lefts,rights};


void TextColor (int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , color);
}
struct Toado{
    int x,y;
};
struct Snack {
    Toado dot[100];
    int n ;
    Trangthai tt;

};
struct food {


    int x,y;
};


void khoitao(Snack &snack,food &hq){

 //khoi tao ran
 snack.n=3;
 snack.dot[0].x=8;
 snack.dot[0].y=6;
 snack.dot[1].x=7;
 snack.dot[1].y=6;
 snack.dot[2].x=6;
 snack.dot[2].y=6;
 snack.tt=rights ;
 //khoi tao hoa qua
 hq.x=7;
 hq.y=4;

}
void hienthi(Snack snack ,food hq){

    clrscr();
    for (int i=0;i<width;i++){
        gotoXY(i,0);
        cout<<char (3);}
        for (int i=0;i<width;i++){
        gotoXY(i,height);
        cout<<char (4);
    }
    for (int j=0;j<height;j++){
        gotoXY(0,j);
        cout<<char (5);}
        for (int j =0;j<height;j++){
        gotoXY(width,j);
        cout<<char (6);

    }


    //in ra dau ran
    gotoXY(snack.dot[0].x,snack.dot[0].y);
    cout<<char (2);
    //in ra than ran
    for (int i =1;i<snack.n;i++){
        gotoXY(snack.dot[i].x,snack.dot[i].y);
        cout<<"*";
    }
    //in ra hoa qua
    gotoXY(hq.x,hq.y);
    cout<<char (4);
}
void chuyendong(Snack &snack){
    //cap nhat vi tri con ran
    for (int i =snack.n-1;i>0;i--)
        snack.dot[i]=snack.dot[i-1];
    if(kbhit())//neu nguoi dung dang nhap vao 1 phim no do
    {
        char c=_getch();
        if (c=='w'||c=='W')snack.tt=up;
        else if (c=='x'||c=='X')snack.tt=down;
        else if (c=='A'||c=='a')snack.tt=lefts;
        else if (c=='d'||c=='D')snack.tt=rights ;


    }
    if (snack.tt==up)snack.dot[0].y--;
    else if (snack.tt==down)snack.dot[0].y++;
    else if (snack.tt==rights)snack.dot[0].x++;
    else if (snack.tt==lefts )snack.dot[0].x--;
}
int main  ()
{

    Snack snack;
    food hq;

    khoitao(snack,hq);
    while (1){

        hienthi(snack,hq);
        chuyendong(snack);
        Sleep(100);

    }
}
