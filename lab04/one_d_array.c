/*
 * Anandsroop Singh
 * 03/01/2021
 * CIS 2107
 * Lab 04
 * Program which allows users to work with arrays, such as
 * allowing them to fill arrays with values [low, high],
 * reverse arrays, reverse part of arrays, find the
 * max element in part of the array, find two consqecutive numbers
 * in the array.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define b32 int

// Prints out the array passed in formated
void PrintArrayFormated(int *arr, size_t size, char *message, int n)
{
    printf("%s:\n", message);

    b32 new_line = 0;

    // Loops through the array to print out the elements
    for (size_t i = 0; i < size; ++i)
    {
        printf("%3d ", arr[i]);

        new_line = 0;

        // Prints new line if n elements printed
        if ((i + 1) % n == 0)
        {
            puts("");
            new_line = 1;
        }
    }

    if (new_line)
    {
        puts("");
    }
    else
    {
        puts("\n");
    }
}

// Fills the array that is passed in with value in range [low, high]
void FillArray(int *arr, size_t size)
{
    int low, high;

    printf("%s", "Filling array with values from certain range\n");

    printf("%s", "Enter the low range value: ");
    scanf("%d", &low);

    printf("%s", "Enter the high range value: ");
    scanf("%d", &high);

    puts("");

    for (size_t i = 0; i < size; ++i)
    {
        arr[i] = rand() % (high + 1) + low;
    }
}

// Finds the highest value element from a certain index range of arr
int FindWithRange(int *arr, size_t size)
{
    int index_low, index_high;

    printf("%s", "Finding the greatest element from certain range\n");

    printf("%s", "Enter lower index of the range: ");
    scanf("%d", &index_low);

    printf("%s", "Enter higher index of the range: ");
    scanf("%d", &index_high);

    puts("\n");

    // Check for valid input
    if (index_low < 0 || index_high >= size || index_low > index_high)
    {
        printf("%s", "Input that is entered is not valid, try again.\n");
        exit(1);
    }

    int max = arr[index_low];

    // Loop through that range to find the max
    for (size_t i = index_low + 1; i <= index_high; ++i)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }

    return max;
}

// Reverses the elements of the array
void ReverseArray(int *arr, size_t size)
{
    // Loop through the array and reverses it
    for (size_t i = 0; i < size / 2; ++i)
    {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

// Reverses part of the array
void ReverseWithRange(int *arr, size_t size)
{
    int index_low, index_high;

    printf("%s", "Reversing array with from index passed in\n");

    printf("%s", "Enter lower index of the range: ");
    scanf("%d", &index_low);

    printf("%s", "Enter higher index of the range: ");
    scanf("%d", &index_high);

    puts("");

    // Check for valid input
    if (index_low < 0 || index_high >= size || index_low > index_high)
    {
        printf("%s", "Input that is entered is not valid, try again.\n");
        exit(1);
    }

    int range_size = (index_low + index_high) / 2 + 1;

    // Loop through the range and reverses
    for (size_t i = index_low; i < range_size; ++i)
    {
        int temp = arr[i];
        arr[i] = arr[index_high - (i - index_low)];
        arr[index_high - (i - index_low)] = temp;
    }
}

// See if two numbers enter are in the array consecutively
void FindSequence(int *arr, size_t size)
{
    int tom, jerry;

    printf("%s", "Find numbers in array\n");

    printf("%s", "Enter two numbers: ");
    scanf("%d %d", &tom, &jerry);

    int found = -1;

    for (size_t i = 0; i < size; ++i)
    {
        if (arr[i] == tom && arr[i + 1] == jerry)
        {
            found = i;
            break;
        }
    }

    if (found == -1)
    {
        printf("%s", "Sequence not found\n");
    }
    else
    {
        printf("Sequence was found at %d\n", found);
    }
}

int main(int argc, char **argv)
{
    // Seeding random with time
    srand((unsigned)time(NULL));

    int num_of_elements;
    printf("%s", "Enter the number of elements: ");
    scanf("%d", &num_of_elements);
    puts("");

    // Variable lenght array
    int arr[num_of_elements];

    // Fill Array
    FillArray(arr, num_of_elements);
    PrintArrayFormated(arr, num_of_elements, "Original Array", 10);

    // Find with range
    int max = FindWithRange(arr, num_of_elements);
    printf("The greatest element from that range was %d\n\n", max);

    // Reverse
    ReverseArray(arr, num_of_elements);
    PrintArrayFormated(arr, num_of_elements, "Reversed Array", 10);

    // Reverse with range
    ReverseWithRange(arr, num_of_elements);
    PrintArrayFormated(arr, num_of_elements, "Reversed Array", 10);

    // Find sequence
    FindSequence(arr, num_of_elements);

    return 0;
}
