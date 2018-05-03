#include<iostream>
#include"console.h"
#include"snake.h"
#include"Menu.h"
#include<conio.h>
using namespace std ;

void CheckMenu (Snake & snake ,food &hq )
{
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

bool Rules ()
{
    char button;
    gotoXY(12,8);
    cout<<"_________________________QUY TAC____________________________________";
    gotoXY(12,10);
    cout<<"Nguoi choi su dung cac phim mui ten tren ban phim de di chuyen ran \n";
    gotoXY(12,12);
    cout<<"Tro choi ket thuc khi ran tu can chinh no hoac dam vao tuong       \n";
    gotoXY(12,14);
    cout<<"Ban co muon quay tro lai menu ?\n"
          "\t\t\t y/Y:co\n"
          "\t\t\t n/N:khong";
    button =_getch();
    if ( button == 'n' || button == 'N')
        return false ;
    if ( button == 'y' || button == 'Y')
    {
        clrscr();
        return true ;
    }
}
