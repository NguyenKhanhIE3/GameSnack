#include<iostream>
#include<windows.h>
#include<conio.h>
#include<ctime>
using namespace std ;
# define width  80
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

struct Moto//mot o
{
	char kitu;
	int mau;
};

Moto buffer [height][(width/2)+1];

void VeMoto(int dong ,int cot ,int kitu ,int mau =7)
{

	buffer[dong][cot].kitu = kitu;
	buffer[dong][cot].mau = mau ;

}

struct Toado
{
    int x,y;//x la hoanh do ,y la tung do
};



struct Snake
{
    Toado dot[100];
    Trangthai tt;
    int n ;
    int score;
    int tickSpeed;

};
struct food
{

    int x,y;//x la hoanh do ,y la tung do ;

};

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
		VeMoto(i,0,4);
		VeMoto(i,width/2,4);
	}
	for (int j = 0;j < width/2;j++)
    {
		VeMoto(0,j,4);
		VeMoto(height-1,j,4);
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

    if ( GetAsyncKeyState(VK_UP))
        snake.tt = up;
    if ( GetAsyncKeyState(VK_DOWN))
        snake.tt = down;
    if ( GetAsyncKeyState(VK_LEFT))
        snake.tt = lefts;
    if ( GetAsyncKeyState(VK_RIGHT))
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
    if ( snake.dot[0].x >= (width/2 -1) ||snake.dot[0].x <= 0 ||snake.dot[0].y <= 0 ||snake.dot[0].y >=(height -1) )
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
            while (_getch()!=13);
            break;

        }

            Sleep(100);
    }
    while (1);

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
    if ( button == 'n' || button == 'N')
        return false ;
    if ( button == 'y' || button == 'Y')
        return true ;
}


int main  ()
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
