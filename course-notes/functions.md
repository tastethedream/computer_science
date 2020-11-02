# Shorts Week 2

## Functions

**What is a function?**

- a black box with a set of 0+ inputs and 1 output 

**Why do we use functions**

 - Allow us to organsise and break up a complicated problem into smaller parts

 - Simplification, smaller componenets are easier to design and debug

 - Reusability - functions can be recycled and used as often as you need 

 ### Function Declaration

 - The first step to creating a function is to declare it. This tells the compiler that a user-written function appears in the code.

 - Function declarations should always be written at the top of your code, before  `main()`.

 - There is a standard form that every declaration follows

    `return-type name(argument-list);`

    - The `return-type`  is what kind of variable the function will output (int, string etc)

    - The `name` is what you will call your functions and should be meaningful

    - The `argument-list` is the comma seperated set of inputs to your function, each of which has a type and name.

    For example ...

    `int add_two_ints(int a, int b);`

    - The sum of two integers is going to also be an integer so the `return-type` is `int`.

    - `add_two_ints` is the `name` and explains what the function will do.

    - There are two `inputs` to this function and we need to give them both a name and return type`int a` and `int b`

    ### Function Definitions

    - The second step to creating a fuction is to define it. This allows for predictable behavior when the function is called.

    - A function definition looks almost identical to the declaration with 1 small change.

    `float mult_two_reals(float x, float y);`

     ```
     float mult_two_reals(float x, float y)
     {
         float product = x * y;
         return product;
     }
     ```

    
     `int add_two_ints(int a, int b);`

     ```
     int add_two_ints(int a, int b)
     {
         int sum; // declare variable
         sum = a + b; // calculate the sum
         return sum; // give back the result
     }
     ```

     ### Function calls

      - To use a function you must call it

      - To call is simply pass it the appropriate arguments and assign its reurn value to the correct type

      `int z = add_two_ints(x, y);`

      ### Function Miscellany

       - If a function takes no inputs we use `(void)` in the `argument-list`

       - If a function has no output it has a void return type.

       ### Practice problem

       ```
       bool valid_triangle(float x, float y, float z);

       bool valid_triangle(float x, float y, float z)
       {
           //check for all positive side lengths
           if (x <= 0 || y <= 0 || z <= 0)
           {
               return false;
           }

           //check that the sum of any 2 sides is greater than the length of the 3rd side
           if ((x + y <= z || x + z <= y || y + z <= x))
           {
               return false;
           }

           // if all tests are passed
           return true;
       }
       ```





