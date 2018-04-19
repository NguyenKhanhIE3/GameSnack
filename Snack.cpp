#include<iostream>
#include<windows.h>
#include<conio.h>
#include<ctime>
using namespace std ;
# define width 45
# define height 25

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

int tickSpeed ;
int score;
struct Snack {
    Toado dot[100];
    int n ;
    Trangthai tt;

};
struct food {


    int x,y;
};





void khoitao(Snack &snack,food &hq){
	//khoi tao gia tri ban dau ;

	tickSpeed=70;
	score=0;
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
    TextColor(12);
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
    TextColor(14);
    gotoXY(snack.dot[0].x,snack.dot[0].y);
    cout<<char (2);
    //in ra than ra than ran

    for (int i =1;i<snack.n;i++){
        gotoXY(snack.dot[i].x,snack.dot[i].y);
        cout<<"*";
    }
    //in ra hoa qua
    TextColor(15);
    gotoXY(hq.x,hq.y);
    cout<<char (4);
    //diemso
    gotoXY(width+15,25 );
    TextColor(2);
    cout<<"Score :"<<score;
}
void chuyendong(Snack &snack){
    //cap nhat vi tri con ran
    for (int i =snack.n-1;i>0;i--)
        snack.dot[i]=snack.dot[i-1];
    if(_kbhit())//neu nguoi dung dang nhap vao 1 phim no do
    {
        int  c=_getch();
        if (c=='w'||c=='W')snack.tt=up;
        else if (c=='s'||c=='S')snack.tt=down;
        else if (c=='A'||c=='a')snack.tt=lefts;
        else if (c=='d'||c=='D')snack.tt=rights ;


    }
    if (snack.tt==up)snack.dot[0].y--;
    else if (snack.tt==down)snack.dot[0].y++;
    else if (snack.tt==rights)snack.dot[0].x++;
    else if (snack.tt==lefts )snack.dot[0].x--;
}
int xuli(Snack &snack,food &hq ){
	
    //xu li ran cham bien
 if (snack.dot[0].x>=width ||snack.dot[0].x<=0 ||snack.dot[0].y<=0||snack.dot[0].y>=height)
      return -1;
    //xu li ran can chinh no
 for (int i=1;i<snack.n;i++){
     if (snack.dot[i].x==snack.dot[0].x&& snack.dot[i].y==snack.dot[0].y)
    return -1 ;
    }



 //xu li ran an hoa qua
 if (snack.dot[0].x==hq.x&&snack.dot[0].y==hq.y){
        for (int i=snack.n;i>0;i--)
    snack.dot[i]=snack.dot[i-1];
    snack.n++;
    score++;
    if (snack.tt==up)snack.dot[0].y--;
    else if (snack.tt==down)snack.dot[0].y++;
    else if (snack.tt==rights)snack.dot[0].x++;
    else if (snack.tt==lefts )snack.dot[0].x--;

    srand(time(NULL));
    hq.x=2+rand ()%(width-4);
    hq.y=2+rand()%(height-4);
    if (tickSpeed>=7)
        tickSpeed-=8;

 }
 return 0 ;

}


int main  ()
{ 
     Snack snack;
     food hq;
     int ma =0;
    khoitao(snack,hq);
 
    while (1){
    hienthi(snack,hq);
    chuyendong(snack);
    ma =xuli(snack,hq);
	
  if (ma==-1){
   TextColor(14);
    gotoXY(width+5,6);
    cout<<"\t\t\t ====        === \n\n\n\n\n";
    gotoXY(width+5,10);
    cout<<"\t\t\t    GAME OVER \n\n";
    gotoXY(width+5,13);
    cout<<"\t\t\t  *Your score : "<<score<<endl<<endl;
        gotoXY(width+5,16);
    cout<<"\t\t\t  *See you again !\n\n\n\n";
    gotoXY(width+5,20);
    cout<<"\t\t\t *****************";
       while (_getch()!=13);
       break;
       

    

  }
  Sleep(100);}
