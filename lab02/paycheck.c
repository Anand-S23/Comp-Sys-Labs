/*
 * Anand Singh
 * 02/04/2021
 * CIS 2107
 * Lab 02
 * This program caluates the pay for the week depending on their
 * weekly time entered and their hourly pay
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    double employee_number;
    float hourly_salary;
    float weekly_time;

    float net_pay;
    float regular_pay;
    float overtime_pay = 0;

    // Header
    printf("%s", "\nWelcome to \"TEMPLE HUMAN RESOURCES\"\n\n");

    // Get the employee number from user
    printf("%s", "\tEnter Employee Number: ");
    scanf("%lf", &employee_number);

    // Check if the number is greater than 0 and is an integer
    if (employee_number <= 0 || (employee_number - (int)employee_number) != 0.f)
    {
        // Prints out footer and exits if not valid
        printf("%s", "\n\tThis is not a valid Employee Number.\n\tPlease run the program again\n\n");
        printf("%s", "Thank you for using \"TEMPLE HUMAN RESOURCES\"\n\n");
        exit(1);
    }

    // Get the hourly salary from user
    printf("%s", "\tEnter Hourly Salary: ");
    scanf("%f", &hourly_salary);

    // Checks if salary is greater than 0
    if (hourly_salary <= 0)
    {
        // Prints out footer and exits if not valid
        printf("%s", "\n\tThis is not a valid hourly salary amount.\n\tPlease run the program again\n\n");
        printf("%s", "Thank you for using \"TEMPLE HUMAN RESOURCES\"\n\n");
        exit(1);
    }

    // Get the time worked for the week from user
    printf("%s", "\tEnter Weekly Time: ");
    scanf("%f", &weekly_time);

    // Checks if time is greater than 0 and less than 100
    if (weekly_time <= 0 || weekly_time > 100)
    {
        // Prints out footer and exits if not valid
        printf("%s", "\n\tThis is not a valid weekly time.\n\tPlease run the program again\n\n");
        printf("%s", "Thank you for using \"TEMPLE HUMAN RESOURCES\"\n\n");
        exit(1);
    }


    // Calculate the regular pay and overtime pay based on if user worked overtime
    if (weekly_time > 40)
    {
        regular_pay = 40 * hourly_salary;
        overtime_pay = (weekly_time - 40) * (1.5 * hourly_salary);
    }
    else
    {
        regular_pay = weekly_time * hourly_salary;
    }

    // Calculates the net pay
    net_pay = regular_pay + overtime_pay;

    // Prints out information to the users
    printf("%s", "\t==============================\n");
    printf("\tEmployee #: %d\n", (int)employee_number);
    printf("\tHourly Salary: $%.1f\n", hourly_salary);
    printf("\tWeekly Time: %.1f\n", weekly_time);
    printf("\tRegular Pay: $%.1f\n", regular_pay);
    printf("\tOvertime Pay: $%.1f\n", overtime_pay);
    printf("\tNet Pay: $%.1f\n", net_pay);
    printf("%s", "\t==============================\n");

    // Footer
    printf("%s", "Thank you for using \"TEMPLE HUMAN RESOURCES\"\n\n");

    return 0;
}
