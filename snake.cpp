#include<iostream>
#include<Windows.h>
#include<conio.h>
#include"console.h"
#include"snake.h"
using namespace std ;
Moto buffer [height][(width/2)+1];
void VeMoto(int dong ,int cot ,int kitu ,int mau =7)
{

	buffer[dong][cot].kitu = kitu;
	buffer[dong][cot].mau = mau ;

}


void Creat (Snake &snake ,food &hq)
{
    //khoi tao gia tri ban dau ;

    snake.tickSpeed = 70;
    snake.score = 0;
    //khoi tao ran
    snake.n = 3;
    snake.dot[0].x = 8;
    snake.dot[0].y = 6;
    snake.dot[1].x = 7;
    snake.dot[1].y = 6;
    snake.dot[2].x = 6;
    snake.dot[2].y = 6;
    snake.tt = rights ;
    //khoi tao hoa qua
    hq.x = 7;
    hq.y = 4;
    //khoi tao buffer
    for (int i = 0;i < height ;i++)
    {
    	for (int j = 0;j < width/2;j++)
    	{
    		VeMoto(i,j,' ');
	}
    }


}

void Display(Snake snake ,food hq)
{
    for(int i = 0;i < height ;i++)
    {
	 VeMoto(i,0,176);
	 VeMoto(i,width/2,176);
    }
    for (int j = 0;j < width/2;j++)
    {
	 VeMoto(0,j,176);
         VeMoto(height-1,j,176);
    }

    //in ra dau ran

    VeMoto(snake.dot[0].y,snake.dot[0].x,178,14);
    //in ra than ra than ran
    for (int i = 1;i < snake.n;i++)
    {
    	 VeMoto(snake.dot[i].y,snake.dot[i].x,178,14);
    }
    //in ra hoa qua
    VeMoto(hq.y,hq.x,4,15);
    //diem so
    gotoXY((width/2)+15,23 );

    TextColor(12);

    cout<<"Score :"<<snake.score;
    //in buffer ra man hinh
    gotoXY(0,0);
    for (int i = 0;i < height ;i++)
    {
    	for (int j = 0;j <= width/2;j++)
    	{
    		TextColor(buffer[i][j].mau);
    		cout<<buffer[i][j].kitu;
    		 buffer[i][j].kitu = ' ';
	}
	if (i < height -1)
		cout<<"\n";
    }
}
void Move_1 (Snake &snake )
{
    //cap nhat vi tri con ran
    for (int i = snake.n-1;i > 0;i--)
        snake.dot[i] = snake.dot[i-1];
    //di chuyen ran
    if ( GetAsyncKeyState(VK_UP))
	if (snake.tt != down )
                snake.tt = up;
    if ( GetAsyncKeyState(VK_DOWN))
	if (snake.tt != up)
        	snake.tt = down;
    if ( GetAsyncKeyState(VK_LEFT))
	if (snake.tt != rights)
        	snake.tt = lefts;
    if ( GetAsyncKeyState(VK_RIGHT))
	if (snake.tt != lefts)
        	snake.tt = rights ;
    if ( snake.tt == up )
        snake.dot[0].y--;
    if ( snake.tt == down )
        snake.dot[0].y++;
    if ( snake.tt == rights )
        snake.dot[0].x++;
    if ( snake.tt == lefts )
        snake.dot[0].x--;
}
int Process (Snake & snake ,food &hq )
{

    //xu li ran cham bien
    if ( snake.dot[0].x >= (width/2 )||snake.dot[0].x <= 0 ||snake.dot[0].y <= 0 ||snake.dot[0].y >=(height -1) )
        return -1;
    //xu li ran can chinh no
    for (int i = 1; i < snake.n;i++)

        if( snake.dot[0].x == snake.dot[i].x && snake.dot[0].y == snake.dot[i].y)
            return -1;
    //xu li ran an hoa qua
    if ( snake.dot[0].x == hq.x && snake.dot[0].y == hq.y)
    {
        for (int i = snake.n ; i > 0; i --)
            snake.dot[i] = snake.dot[i-1];
        snake.n++;
        snake.score++;
        // khoi tao lai vi tri hoa qua
        hq.x = 2 + rand () %( (width/2)-6);
        hq.y = 2 + rand () %( height-6);
        if ( snake.tickSpeed >= 7 )
            snake.tickSpeed -= 4;

    }
    return 0 ;

}
void Main_Move (Snake &snake ,food &hq)
{
    int ma =0;
    Creat (snake,hq);
    do
    {
        Display(snake,hq);
        Move_1 (snake);
        ma = Process (snake ,hq);

        if (ma == -1)
        {
            TextColor(11);
            gotoXY((width/2)+5,6);
            cout<<"\t\t ====        ==== \n\n\n\n\n";
            gotoXY((width/2)+5,10);
            cout<<"\t\t     GAME OVER \n\n";
            gotoXY((width/2)+5,13);
            cout<<"\t\t  *Your score : "<<snake.score<<endl<<endl;
            gotoXY((width/2)+5,16);
            cout<<"\t\t  *See you again !\n\n\n\n";
            gotoXY((width/2)+5,20);
            cout<<"\t\t *****************";
            _getch();
	    clrscr();
            break;

        }

            Sleep(50);
    }
    while (1);

}

