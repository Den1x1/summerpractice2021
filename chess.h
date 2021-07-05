#ifndef chess

#define chess


#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ask 10
#define row 9
#define col 9 

int kinL[row][col];                  //co-ords of K
unsigned char filltheboard[row][col]; //coloring
int doska[row][col];      //board coordinate
int x1, cnt = 0, y1, tp = 0,score=0;             
//sum up how many possibilities king has
int cntofmoves(int turn) {
    printf("Steps %d/%d\n", tp, turn);
    if (x1 >= 2 && x1 <= 7 && y1 == 1 || x1 >= 2 && x1 <= 7 && y1 == 8 || y1 >= 2 && y1 <= 7 && x1 == 1 || y1 >= 2 && y1 <= 7 && x1 == 8) {
        cnt += 5;
    }
    if (x1 == 1 && y1 == 1 || x1 == 1 && y1 == 8 || x1 == 8 && y1 == 1 || x1 == 8 && y1 == 8) {
        cnt += 3;
    }
    if (y1 >= 2 && x1 >= 2 && y1 <= 7 && x1 <= 7)
    {
        cnt += 8;
    }
    printf("Moves = %d\n", cnt);
    return cnt;
}
//Make a boards and coloring
void start() {
    int k1 = 1, cnt = 0;
    // color board
    for (int g = 1; g < col; g++)
    {
        for (int f = 1; f < row; f++)
        {
            //give each squere the number(from 1 to 64)
            doska[f][g] = ++cnt;
            if (k1 == 1)
                filltheboard[f][g] = '\xDB';  //white
            else if (k1 == -1)
                filltheboard[f][g] = '\xB0';  //black
            k1 *= -1;
        }
        k1 *= -1;
    }
}
//showing movement of king
void showthedesk() {
    char line = 'a';
    printf(" ");
    while (line <= 'h') {
        printf(" %c", line);
        line++;
    }
    printf("\n");
    for (int g = 1; g < col; g++)
    {
        printf("%d ", g);
        for (int f = 1; f < row; f++)
        {
            if (filltheboard[f][g] == 'k')
            {
                switch ((f + g) % 2)
                {
                case 0: filltheboard[f][g] = '\xDB';
                    break;
                case 1: filltheboard[f][g] = '\xB0';
                    break;
                }
            }
            if (kinL[x1][y1] == doska[f][g])
                filltheboard[f][g] = 'k';
            printf("%1c ", filltheboard[f][g]);
        }
        printf("\n");
    }
    printf("\n");
}

//put king in random place in board
void Randomize() {
    srand((unsigned)time(NULL));
    //for Y coor
    y1 = rand() % 10;
    if (y1 >= 9)
        y1 = y1 - 2;
    else if (y1 == 0)
        y1++;
    //for X coor
    x1 = rand() % 10;
    if (x1 >= 9)
        x1 = x1 - 2;
    else if (x1 == 0)
        x1++;
}



//vertical and diagonal movement
int MovementToDown()
{
    if (y1 < 8 && y1 != 0 && y1 > 0) {
        y1 = y1 + 1;
        kinL[x1][y1] = doska[x1][y1];
    }
    else {
        return 0;
    }
    return 1;
}
int MovementToLeft() {
    if (x1 > 1 && x1 != 0 && x1 <= 8) {
        x1 = x1 - 1;
        kinL[x1][y1] = doska[x1][y1];
    }
    else {
        return 0;
    }
    return 1;
}
int MovementToRight() {
    if (x1 < 8 && x1 != 0 && x1 > 0) {
        x1 = x1 + 1;
        kinL[x1][y1] = doska[x1][y1];
    }
    else {
        return 0;
    }
    return 1;
}
int MovementToUp()
{
   
    if (y1 > 1 && y1 != 0 && y1 <= 8) {
        y1 = y1 - 1;
        kinL[x1][y1] = doska[x1][y1];
    }
    else {
         return 0;
    }
    return 1;
}
//diagonal movement 
int MovementToLeft_Down() {
    if (x1 > 1 && x1 != 0 && x1 <= 8) {
        x1 = x1 - 1;
        y1 = y1 + 1;
        kinL[x1][y1] = doska[x1][y1];
    }
    else {
        return 0;
    }
    return 1;
}
int MovementToLeft_Up() {
    if (x1 > 1 && x1 != 0 && x1 <= 8 && y1 >= 1 && y1 <= 8 && y1 != 0) {
        x1 = x1 - 1;
        y1 = y1 - 1;
        kinL[x1][y1] = doska[x1][y1];
    }
    else {
        return 0;
    }
    return 1;
}
int MovementToRightDown() {
    if (x1 > 1 && x1 != 0 && x1 < 8) {
        x1 = x1 + 1;
        y1 = y1 + 1;
        kinL[x1][y1] = doska[x1][y1];
    }
    else {
        return 0;
    }
    return 1;
}
int MovementToRightUp() {
    if (x1 > 1 && x1 != 0 && x1 < 8) {
        y1 = y1 - 1;
        x1 = x1 + 1;
        kinL[x1][y1] = doska[x1][y1];
    }
    else {
        return 0;
    }
    return 1;
}
//uses all functions from above to make king move
void mooving(int turn) {
    printf("--------\nMove setting:\nup\ndown\nright\nleft\nupleft\ndownleft\nupright\ndownright\n");
    showthedesk();
    char AskingForMt[ask]; //console command
    for (int turnNow = 0; turnNow < turn;) {
        printf("------\n");       
        fixedFgets(AskingForMt, 10); //in the cmnd 

         if (strncmp(AskingForMt, "down", 5) == 0) // down move
        {
             score++;
        tp = turnNow += MovementToDown();
        if (tp == score) {
            showthedesk();      // showing  desk
            cntofmoves(turn);    // upd the psble K moves
        }
        else score = tp;
        }
        else if (strncmp(AskingForMt, "up", 3) == 0) // up move
        {
             score++;
            tp = turnNow += MovementToUp(); // showing how many steps king made
            if (tp == score) {
                showthedesk();      // showing  desk
                cntofmoves(turn);    // upd the psble K moves
            }
            else score = tp;
        }
        
        else if (strncmp(AskingForMt, "upleft", 7) == 0) // up and left move
        {
             score++;
            tp = turnNow += MovementToLeft_Up();
            if (tp == score) {
                showthedesk();      // showing  desk
                cntofmoves(turn);    // upd the psble K moves
            }
            else score = tp;
        }
        else if (strncmp(AskingForMt, "right", 6) == 0) // right move
        {
             score++;
            tp = turnNow += MovementToRight();
            if (tp == score) {
                showthedesk();      // showing  desk
                cntofmoves(turn);    // upd the psble K moves
            }
            else score = tp;
        }
        else if (strncmp(AskingForMt, "downleft", 9) == 0) // down and left move
        {
             score++;
            tp = turnNow += MovementToLeft_Down();
            if (tp == score) {
                showthedesk();      // showing  desk
                cntofmoves(turn);    // upd the psble K moves
            }
            else score = tp;
        }
        else if (strncmp(AskingForMt, "left", 5) == 0) // left move
        {
             score++;
            tp = turnNow += MovementToLeft();
            if (tp == score) {
                showthedesk();      // showing  desk
                cntofmoves(turn);    // upd the psble K moves
            }
            else score = tp;
        }
        else if (strncmp(AskingForMt, "downright", 10) == 0) // down and right move
        {
             score++;
            tp = turnNow += MovementToRightDown();
            if (tp == score) {
                showthedesk();      // showing  desk
                cntofmoves(turn);    // upd the psble K moves
            }
            else score = tp;
        }
        else if (strncmp(AskingForMt, "upright", 8) == 0) // up and right move
        {
             score++;
            tp = turnNow += MovementToRightUp();
            if (tp == score) {
                showthedesk();      // showing  desk
                cntofmoves(turn);    // upd the psble K moves
            }
            else score = tp;
        }
    }
}
//Fix function fgets
int fixedFgets(char str[], int n)
{
    int success = 1;

    // Check that fgets worked
    if (fgets(str, n, stdin) != NULL)
    {
        str[strcspn(str, "\n")] = 0;
    }
    else
    {
        success = 0;
    }

    return success;
}
#endif 