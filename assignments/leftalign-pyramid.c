

// ask user how tall the pyramid should be and create the pyramid
//do while loop required >0 and <9
int main(void)

{
    int height, level, width;
    do
    {
        height = get_int("How many levels would you like your pyramid to be?: ");
    }
    while (height < 1 || height > 8);
    
    for (level = 0; level < height; level++)
    {
        for (width = 0; width <= level; width++)
        {
            printf("#");
        }
        
        printf("\n");
    }
}