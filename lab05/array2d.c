/* 
 * Anandsroop Singh
 * 03/04/2021
 * CIS 2107
 * Lab05
 * Let's user interact with 2D arrays, let's user create
 * 2D array based on size of their choosing, and let's user
 * know the max element, the sum of the row, the sum of the cols
 * if the array is a square array and prints out the array.
 */
#include <stdio.h>
#include <stdlib.h>

static int ROWS, COLS;

// Fill the array based on user input
void FillArray(int arr[][COLS])
{
    int val;

    for (int j = 0; j < ROWS; ++j)
    {
        for (int i = 0; i < COLS; ++i)
        {
            printf("\tEnter [%d][%d]: ", j, i);
            scanf("%d", &val);

            arr[j][i] = val;
        }
    }

    puts("");
}

// Prints out the max value of the array
void Max(int arr[][COLS])
{
    int max = arr[0][0];

    for (int j = 0; j < ROWS; ++j)
    {
        for (int i = 0; i < COLS; ++i)
        {
            if (max < arr[j][i])
            {
                max = arr[j][i];
            }
        }
    }

    printf("The max element in the array is %d.\n\n", max);
}

// Prints out the sums of the rows
void RowSum(int arr[][COLS])
{
    for (int j = 0; j < ROWS; ++j)
    {
        int row_sum = 0;
        for (int i = 0; i < COLS; ++i)
        {
            row_sum += arr[j][i];
        }

        printf("Sum of row %d = %d\n", j + 1, row_sum);
    }

    puts("");
}

// Prints out the sums of the cols
void ColSum(int arr[][COLS])
{
    for (int j = 0; j < COLS; ++j)
    {
        int col_sum = 0;
        for (int i = 0; i < ROWS; ++i)
        {
            col_sum += arr[i][j];
        }

        printf("Sum of column %d = %d\n", j + 1, col_sum);
    }

    puts("");
}

// Checks if the array is a square array
void IsSquare()
{
    if (ROWS == COLS)
    {
        printf("%s", "This is a square array.\n\n");
    }
    else
    {
        printf("%s", "This is not a square array.\n\n");
    }
}

// Prints out the array
void PrintArray(int arr[][COLS])
{
    printf("%s", "Here is your 2D array:\n");

    for (int j = 0; j < ROWS; ++j)
    {
        printf("%s", "[");

        for (int i = 0; i < COLS; ++i)
        {
            if (i == 0)
            {
               printf("%d", arr[j][i]); 
            }
            else
            {
                printf(", %d", arr[j][i]);
            }
        }

        printf("%s", "]\n");
    }

    puts("");
}

int main(int argc, char **argv)
{
    printf("Let's create a 2D array\n\n");

    // Gets the size of the array
    printf("%s", "\tEnter the number of rows: ");
    scanf("%d", &ROWS);

    printf("%s", "\tEnter the number of columns: ");
    scanf("%d", &COLS);

    puts("");

    int arr[ROWS][COLS];

    // Function calls for all of the functions
    FillArray(arr);
    Max(arr);
    RowSum(arr);
    ColSum(arr);
    IsSquare();
    PrintArray(arr);

    return 0;
}
