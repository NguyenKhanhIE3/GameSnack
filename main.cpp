#include<iostream>
#include<ctime>
#include"snake.h"
#include"console.h"
#include "Menu.h"
using namespace std ;

int main ()
{
    srand(time(NULL));
    Snake snake ;
    food hq;
    CheckMenu(snake ,hq);
}
