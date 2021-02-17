/*
 * Anand Singh
 * 02/12/2021
 * CIS 2107
 * Lab 03
 * Emulates a ATM, where users are able to withdrawal, 
 * deposit and check thier balance
*/

#include <stdio.h>
#include <stdlib.h>

#define b32 int
#define u32 unsigned int

#define PIN 3014

// Global Variable (maybe improvement: make a struct with some of these var)
int balance = 5000;
int cash_withdrawn = 0;
int cash_deposited = 0;
u32 transaction_num = 0;

// Asks the user if they want a receipt, keeps asking until right input given
void Receipt()
{
    int receipt_option;

    printf("%s", "\n\tWould you like a receipt? (1/2): ");
    scanf("%d", &receipt_option);

    if (receipt_option != 1 && receipt_option != 2)
    {
        Receipt();
    }
}

// Exits out of the program, and prints the number of transactions
void Quit()
{
    printf("\n\nThank you for visiting the ATM, you have made %u transactions. Come back soon!\n\n", transaction_num);
    exit(1);
}

// Allows users to enter 1 < x < 10000 (whole number) to deposit, or 0 to return to menu
void CashDeposit(u32 try)
{
    // Quits after thrid failed attempt
    if (try >= 3)
    {
        Quit();
    }

    // Asks user for deposit amount
    float deposit_amount;
    printf("%s", "\n\n\n\tEnter the amount you want to deposit or enter 0 to return to the menu.\n");
    printf("%s", "\tDeposit Amount: "); 
    scanf("%f", &deposit_amount);

    // Checks if over deposit limit
    if ((int)deposit_amount + cash_deposited > 10000)
    {
        printf("%s", "\n\tTransaction could not be completed: deposit amount cannot go over $10000.\n");
        printf("\tThere are %u more attempts before auto quit.\n", (3 - try - 1));
        CashDeposit(++try);
        return;
    }

    // Checks if deposit doesn't have coins
    if (deposit_amount - (int)deposit_amount != 0.f)
    {
        printf("%s", "\n\tTransaction could not be completed: ATM can only intake bills.\n");
        printf("\tThere are %u more attempts before auto quit.\n", (3 - try - 1));
        CashDeposit(++try);
        return;
    }

    // Makes transaction if the amount not 0, or takes them back to menu if 0
    if (deposit_amount != 0.f) 
    {
        balance += (int)deposit_amount;
        cash_deposited += (int)deposit_amount;
        ++transaction_num;

        printf("\n\tTransaction was successful, $%.2f was deposited\n", deposit_amount);

        Receipt();
    }
}

// Allows users to enter multiple of 20 to withdrawal, or 0 to return to menu
void CashWithdrawal(u32 try)
{
    // Quits after thrid failed attempt
    if (try >= 3)
    {
        Quit();
    }

    // Asks user for the withdrawal amount
    float withdrawal_amount;
    printf("%s", "\n\n\n\tEnter the amount you want to withdrawal or enter 0 to return to the menu.\n");
    printf("%s", "\tWithdrawal Amount: "); 
    scanf("%f", &withdrawal_amount);

    // Checks if withdrawal amount is over the limit
    if ((int)withdrawal_amount + cash_withdrawn > 1000)
    {
        printf("%s", "\n\tTransaction could not be completed: withdrawal amount cannot go over $1000.\n");
        printf("\tThere are %u more attempts before auto quit.\n", (3 - try - 1));
        CashWithdrawal(++try);
        return;
    }

    // Checks if the withdrawal amount is multiple of 20
    if ((int)withdrawal_amount % 20 != 0 ||
        withdrawal_amount - (int)withdrawal_amount != 0.f)
    {
        printf("%s", "\n\tTransaction could not be completed: ATM can only output $20 bills\n");
        printf("\tThere are %u more attempts before auto quit.\n", (3 - try - 1));
        CashWithdrawal(++try);
        return;
    }

    // Makes transaction if the amount not 0, or takes them back to menu if 0
    if (withdrawal_amount != 0.f) 
    {
        balance -= (int)withdrawal_amount;
        cash_withdrawn += (int)withdrawal_amount;
        ++transaction_num;

        printf("\n\tTransaction was successful, $%.2f was withdrawn\n", withdrawal_amount);

        Receipt();
    }
}

// Prints out the balance of the user
void Balance()
{
    printf("\n\n\n\tYour current balance: $%.2f\n", (float)balance);
}

// Asks for the user's PIN, and quits if not right in 3 attempts
b32 Login()
{
    printf("%s", "\nWelcome to the ATM!\n\n");
    
    for (int i = 0; i < 3; ++i)
    {
        float pin_entered;
        printf("%s", "\tEnter the pin to access your account: ");
        scanf("%f", &pin_entered);

        if ((int)pin_entered == PIN && (pin_entered - (int)pin_entered) == 0.f)
        {
            return 1;
        }
        else
        {
            printf("\n\tThe pin you entered was wrong, you have %d remaining attempts\n", (3 - i - 1));
        }
    }

    Quit();
    return 0;
}

int main(int argc, char **argv)
{
    if (Login())
    {
        while (1)
        {
            int action;

            // Asks the users which transaction the would like to do
            printf("%s", "\n\n\n\tATM Possible Transactions\n");
            printf("%s", "\n\t1. Balance\n\t2. Cash Withdrawal\n\t3. Cash Deposition\n\t4. Quit\n\n");
            printf("%s", "\tWhat transaction would you like to do? (Enter the corresponding number): ");
            scanf("%d", &action);

            // Calls function based on which action the user chooses
            switch (action)
            {
                case 1:
                    Balance();
                    break;

                case 2:
                    CashWithdrawal(0);
                    break;

                case 3:
                    CashDeposit(0);
                    break;

                case 4:
                    Quit();
                    break;

                default:
                    printf("%s", "\tThat is not a vaild command, please try again.\n");
                    break;
            }
        }
    }

    return 0;
}

