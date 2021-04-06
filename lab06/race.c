/*
 * Name: Anandsroop Singh
 * Date: 04/01/2021
 * Course: CIS2017
 * Assignment: Lab06 Race
 *
 * The purpose of this program is to simulate and display the race between the tortoise and 
 * the hare using a random number generator and preset move types. The animal positions are 
 * accessed and modified using pointers, and the display is controlled using the sleep() function. 
 * Sometimes it takes a while due to slippage.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// Useful macro functions
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) > (b) ? (b) : (a))

#define INT_MIN 1
#define INT_MAX 10

// Prototypes
int randomNumberGenerator();
void tortMove(int *tPtr);
void hareMove(int *hPtr);
void printRace(int hPos,int tPos);
int min(int hMin, int tMin);

int main(){
    srand((unsigned)time(NULL));

    int hPos = 1;						//hare start position is 1, cannot slip past 1
    int tPos = 1;						//tortoise start position is 1, cannot slip past 1

    puts("\tON YOUR MARK, GET SET");
    puts("\tBANG               !!!!");	//the spacing is modeled after the sample
    puts("\tAND THEY'RE OFF    !!!!");	//the spacing is modeled after the sample

    while(hPos < 70 && tPos < 70){
        sleep(1);						//slows down the race
        hareMove(&hPos);
        tortMove(&tPos);
        printRace(hPos,tPos);
        puts("");
    }
}

//Finds minimum of hare or tortoise position to decide which position to print first
int min(int hMin, int tMin) {
    return Min(hMin, tMin);
}

//Prints the position of the H and T
void printRace(int hPos, int tPos) {
    if (hPos == tPos)
    {
        printf("%s", "\t");
        for (int i = 0; i < hPos; ++i)
        {
            printf("%s", " ");
        }

        printf("%s", "OUCH!!!");
    }
    else if (hPos >= 70)
    {
        printf("%s", "\tHare wins. Yuch.");
    }
    else if (tPos >= 70)
    {
        printf("%s", "\tTORTOISE WINS!!! YAY!!!");
    }
    else if (min(hPos, tPos) == hPos)
    {
        printf("%s", "\t");
        for (int i = 0; i < hPos; ++i)
        {
            printf("%s", " ");
        }

        printf("%s", "H");

        for (int i = 0; i < (tPos - hPos); ++i)
        {
            printf(" ");
        }

        printf("%s", "T");
    }
    else if (min(hPos, tPos) == tPos)
    {
        printf("%s", "\t");
        for (int i = 0; i < tPos; ++i)
        {
            printf("%s", " ");
        }

        printf("%s", "T");

        for (int i = 0; i < (hPos - tPos); ++i)
        {
            printf("%s", " ");
        }

        printf("%s", "H");
    }
}

//Controls the tortoise movement
void tortMove(int *tPtr) {
    int rand_move = randomNumberGenerator();

    if (rand_move >= 1 && rand_move <= 5)
    {
        *tPtr += 3;
    }
    else if (rand_move == 6 || rand_move == 7)
    {
        *tPtr = Max(0, *tPtr - 6);
    }
    else
    {
        *tPtr += 1;
    }
}

//Controls the hare movement
void hareMove(int *hPtr) {
    int rand_move = randomNumberGenerator();

    if (rand_move == 3 || rand_move == 4)
    {
        *hPtr += 9;
    }
    else if (rand_move == 5)
    {
        *hPtr = Max(0, *hPtr - 12);
    }
    else if (rand_move >= 6 && rand_move <= 8)
    {
        *hPtr += 1;
    }
    else if (rand_move == 9 || rand_move == 10)
    {
        *hPtr = Max(0, *hPtr - 2);
    }
}

//Generates random number from 1-10
int randomNumberGenerator() {
    return Min((rand() % (INT_MAX + 1) + INT_MIN), 10);
}
