#include <cs50.h>
#include <stdio.h>

#define QUARTERS 25
#define DIMES 10
#define NICKELS 5
#define PENNIES 1

int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    int quarters = calculate_quarters(cents);
    cents = cents - (quarters * QUARTERS);

    int dimes = calculate_dimes(cents);
    cents = cents - (dimes * DIMES);

    int nickels = calculate_nickels(cents);
    cents = cents - (nickels * NICKELS);

    int pennies = calculate_pennies(cents);
    cents = cents - (pennies * PENNIES);

    int owed_coins = quarters + dimes + nickels + pennies;

    printf("%d\n", owed_coins);
}

int calculate_quarters(int cents)
{
    int quarters = 0;
    while (cents >= QUARTERS)
    {
        quarters++;
        cents = cents - QUARTERS;
    }
    return quarters;
}

int calculate_dimes(int cents)
{
    int dimes  = 0;
    while (cents >= DIMES)
    {
        dimes++;
        cents = cents - DIMES;
    }
    return dimes ;
}


int calculate_nickels(int cents)
{
    int quarters = 0;
    while (cents >= NICKELS)
    {
        quarters++;
        cents = cents - NICKELS;
    }
    return quarters;
}


int calculate_pennies(int cents)
{
    int pennies = 0;
    while (cents >= PENNIES)
    {
        pennies++;
        cents = cents - PENNIES;
    }
    return pennies;
}
