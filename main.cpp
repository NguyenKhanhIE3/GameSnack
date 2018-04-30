#include <iostream>

#include<ctime>
#include<conio.h>
#include "snake.h"
#include "console.h"

using namespace std;

int main
{
    srand(time(NULL));
    Snake snake ;
    food hq;
    char button;
    do
    {
        TextColor(11);
        gotoXY(10,8);
        cout<<"_________________MAIN MENU________________\n\n";
        gotoXY(12,10);
        cout<<"\t\t"<<char(4)<<"  1 => Play Game \n\n";
        gotoXY(12,12);
        cout<<"\t\t"<<char(4)<<"  2 => Rules \n\n";
        gotoXY(12,14);
        cout<<"\t\t"<<char(4)<<"  3 => Quit \n\n";
        gotoXY(12,16);
        button=_getch();
        if ( button == '1' )
        {
            clrscr();
            Main_Move(snake,hq);
        }
        if ( button == '2' )
        {
            clrscr();
            if (!Rules())
                break;
        }
        if ( button == '3')
        {
             break;
        }


    }
    while(1);
}

