/*
 * Anand Singh
 * 02/04/2021
 * CIS 2107
 * Lab 02
 * Calculates the new price of the item from the price and
 * quantity entered, based on range of discounts
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    float item_price;
    float quantity;

    // Header
    printf("%s", "\nWelcome to \"Temple\" store\n\n");

    // Get the item price from user
    printf("%s", "\tEnter item price: ");
    scanf("%f", &item_price);

    // Check if the price is greater than 0
    if (item_price <= 0)
    {
        // Prints out footer and exits if not valid
        printf("%s", "\n\tThis is not a valid item price.\n\tPlease run the program again\n\n");
        printf("%s", "Thank you for using \"Temple\" store\n\n");
        exit(1);
    }

    // Get the quantity from user
    printf("%s", "\tEnter quantity: ");
    scanf("%f", &quantity);

    // Check if the quantity is more than 0 and an integer
    if (quantity <= 0 || (quantity - (int)quantity) != 0)
    {
        // Prints out footer and exits if not valid
        printf("%s", "\n\tThis is not a valid quantity.\n\tPlease run the program again\n\n");
        printf("%s", "Thank you for using \"Temple\" store\n\n");
        exit(1);
    }

    // Figure out the discount
    float discount = 0.f;

    if (quantity >= 150)
    {
        discount = 0.25f;
    }
    else if (quantity >= 100)
    {
        discount = 0.15f;
    }
    else if (quantity >= 50)
    {
        discount = 0.1f;
    }

    // Calculate the information based on the inputs
    float cost = item_price * quantity;
    float discount_amount = cost * discount;
    float total = cost - discount_amount;

    // Prints out information to the users
    printf("%s", "\n");
    printf("\tThe item price is: $%.1f\n", item_price);
    printf("\tThe order is: %d items(s)\n", (int)quantity);
    printf("\tThe cost is: $%.1f\n", cost);
    printf("\tThe discount is: %.1f%%\n", (discount * 100));
    printf("\tThe discount_amount is: $%.1f\n", discount_amount);
    printf("\tThe total is: $%.1f\n", total);
    printf("%s", "\n");

    // Footer
    printf("%s", "Thank you for using \"Temple\" store\n\n");

    return 0;
}
