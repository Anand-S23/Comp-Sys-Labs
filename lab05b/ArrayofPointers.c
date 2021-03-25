/*
 * Name: Anandsroop Singh
 * Date: 03/23/2021
 * Course: CSI2107
 * HW#: Lab 05: “Arrays of Pointers to Functions”
 *
 * Objective: To design and implement array of function pointer.
 * The purpose of this program is to modify existing code related to
 * examslecting grades for individual students in a 2D matrix and
 * determining the minimum, maximum,and each average.
 * Each of the functions has also been modified to allow for a
 * menu-driven interface. This interface is an array of pointers to the functions.
 */
#include <stdio.h>
#include <stdlib.h>

// Protoypes
void printArray(int students, int exams, int grades[students][exams]);
void minimum(int students, int exams, int grades[students][exams]);
void maximum(int students, int exams, int grades[students][exams]);
void average(int students, int exams, int grades[students][exams]);

int main(int argc, char **argv)
{
    int students, exams;
    printf("%s", "Let's create a 2D array:\n");

    // Allows users to specify the number of students and exams
    printf("%s", "\tEnter the number of students: ");
    scanf("%d", &students);

    printf("%s", "\tEnter the number of exam: ");
    scanf("%d", &exams);

    puts("");
    int val;
    int grades[students][exams];

    // Allows users to fill the array
    for (int j = 0; j < students; ++j)
    {
        for (int i = 0; i < exams; ++i)
        {
            printf("Enter [%d][%d]: ", j, i);
            scanf("%d", &val);

            grades[j][i] = val;
        }
    }

    puts("");

    // Array of poniters to functions
    void (*func_arr[4])(int, int, int [students][exams]) = { printArray, minimum, maximum, average };

    // Menu for the user to interact with the program
    int choice;
    printf("%s", "Enter a choice:\n\t0 Print the grades\n\t1 Find the minimum grade\n\t2 Find the maximum grade\n\t3 Find the average grade\n\t4 Quit\n> ");
    scanf("%d", &choice);
    puts("");

    while (choice >= 0 && choice < 4)
    {
        // Call function depending on the choice
        (*func_arr[choice])(students, exams, grades);

        printf("%s", "Enter a choice\n\t0 Print the grades\n\t1 The minimum grade\n\t2 The maximum grade\n\t3 The average grade\n\t4 Quit\n> ");
        scanf("%d", &choice);
        puts("");
    }

    printf("%s", "Thank you for using this program\n");
    return 0;
}

// Prints out the array formatted
void printArray(int students, int exams, int grades[students][exams])
{
    for (int j = 0; j < students; ++j)
    {
        printf("%s", "[");

        for (int i = 0; i < exams; ++i)
        {
            if (i == 0)
            {
                printf("%3d", grades[j][i]);
            }
            else
            {
                printf(", %3d", grades[j][i]);
            }
        }

        printf("%s", "]\n");
    }

    puts("");
}

// Finds the lowest grade out of any test
void minimum(int students, int exams, int grades[students][exams])
{
    int min = grades[0][0];

    for (int j = 0; j < students; ++j)
    {
        for (int i = 0; i < exams; ++i)
        {
            if (grades[j][i] < min)
            {
                min = grades[j][i];
            }
        }
    }

    printf("The lowest grade is %d\n\n", min);
}

// Finds the highest grade out of all the tests
void maximum(int students, int exams, int grades[students][exams])
{
    int max = grades[0][0];

    for (int j = 0; j < students; ++j)
    {
        for (int i = 0; i < exams; ++i)
        {
            if (grades[j][i] > max)
            {
                max = grades[j][i];
            }
        }
    }

    printf("The highest grade is %d\n\n", max);
}

// Calculates the average of all the tests for all students in the class
void average(int students, int exams, int grades[students][exams])
{
    int total_sum = 0;

    for (int j = 0; j < students; ++j)
    {
        int sum = 0;

        for (int i = 0; i < exams; ++i)
        {
            sum += grades[j][i];
            total_sum += grades[j][i];
        }

        float ave = (float)sum / (float)exams;
        printf("The average grade for sudent %d is %.2f\n", j+1, ave);
    }

    float ave = (float)total_sum / (float)(students * exams);
    printf("The average grade for all sudents is %.2f\n\n", ave);
}

