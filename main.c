/**
*@file   main.c
*@author Овчаренко Н.Д., гр. 515-I
*@date   01.07.2021
*@brief  summer practice
*
* calculate the number of king moves
*/


#include "chess.h" //inlcude funtion for game

#include <locale.h>
int main(void)
{

    int m;  //turns
    printf("How many turn do you want to make: ");
    scanf_s("%d", &m);
    Randomize();  //Holds the king on a chessboard
    start();      //create the chessboard
    cntofmoves(m);     //count how many option king has`
    kinL[x1][y1] = doska[x1][y1]; // place king 
    mooving(m); //control system
    return 0;
}