# include <stdio.h>
# include <cs50.h>



int main(void)

{
    int height, level, width, space;
    do
    {
        // ask user how tall the pyramid should be and create the pyramid
        height = get_int("How many levels would you like your pyramid to be?: ");
    }
    //do while loop required >0 and <9
    while (height < 1 || height > 8);
    
    for (level = 0; level < height; level++)

    {
        // add spaces 
        for (space = 0; space < height - level - 1; space++)
        {
            printf(" ");
        }
        // add hashes
        for (width = 0; width <= level; width++)
        {
            printf("#");
        }
        
        printf(" ");
        printf(" ");
        
        
        // add hashes
        for (width = 0; width <= level; width++)
        {
            printf("#");
        }
        
        printf("\n");
    }
}