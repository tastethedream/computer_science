# include <stdio.h>
# include <cs50.h>
# include <math.h>

int main(void)
{
    float dollars;
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);
    int cents = round(dollars * 100);
    
    int coins = 0;
    
    while (cents != 0) 
    {
        // calculate quarters 1 quarter = 25c
        coins += cents / 25;
        cents = cents % 25;
        
        // calculate dimes 1 dime = 10c
        coins += cents / 10;
        cents = cents % 10;
        
        // calculate nickels 1 nickel = 5c
        coins += cents / 5;
        cents = cents % 5;
        
        // calculate pennies  1 penny = 1c
        coins += cents / 1;
        cents = cents % 1;
    }
    
    printf("%d\n", coins);
}