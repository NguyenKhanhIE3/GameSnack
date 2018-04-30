#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED
#include<windows.h>
# define width  80
# define height 25

struct Moto//mot o
{
	char kitu;
	int mau;
};


void VeMoto(int dong ,int cot ,int kitu,int mau );

enum TrangThai{up,down,lefts,rights};

struct Toado
{
    int x,y;//x la hoanh do ,y la tung do
};

struct Snake
{
    Toado dot[100];
    TrangThai tt;
    int n ;
    int score;
    int tickSpeed;

};
struct food
{

    int x,y;//x la hoanh do ,y la tung do ;

};
void Creat (Snake &snake ,food &hq);
void Display (Snake snake ,food hq);
void Move_1 (Snake & snake );
int Process (Snake & snake ,food &hq);
void Main_Move (Snake & snake ,food &hq );
bool Rules();


#endif // SNAKE_H_INCLUDED
