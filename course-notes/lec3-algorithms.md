# Week 3 Algorithms

## Big *O* Notation

https://youtu.be/fykrlqbV9wM


Big O notation is a mathematical notation that describes the limiting behavior of a function when the argument tends towards a particular value or infinity, and is usually written as ‘O’. It is an Asymptotic Notation for the worst case, which is also the ceiling of growth for a given function. It provides us with what is called an asymptotic upper bound for the growth rate of runtime of an algorithm or program.

The mathematical definition is below:
f(n) is O(g(n)) if and only if f(n) <= C * g(n) for all n >= k,
where C and k are positive constant values

Big O is a set of functions that are all limiting some other function(s), meaning the function(s) will never grow faster than the other functions that are in the set at a specific point.
Here is an example, n is O(n²). This is a true statement, but why ?
This is because the function f(n) = n, will never exceed or grow faster than the function g(n) = n², no matter what positive value you input for the variable ’n’, n² will always be greater. The specific point where the function n² is greater than or equal to ’n’ is when ’n’ is equal to 1.

Mathematically :
n is O(n^2) if and only if n <= 1* n^2 for all n >= 1,
where C=1 and k=1 which are positive constant values



### Big *O* Events


Big O is the upper bound - worse case 

O(n²) bubble sort, selection sort
O(n log n) merge sort
O(n)  linear search
O(log n)  binary search
O(1)

### Ω 

Is like the opposite of Ο. The best case, the fewest steps, the lower bound

Ω(n²) selection sort
Ω(n log n) merge sort
Ω(n) bubble sort
Ω(log n)
Ω(1)  linear search, binary search

### Θ

If an algorith has an identical upper and lower bound 

Θ(n²) selection sort
Θ(n log n) merge sort
Θ(n) 
Θ(log n)
Θ(1)  

### Linear Search

The idea of the algorithm is to iterate across the array from left to right, searching for a specified element.

>Repeat, starting at the first element
    >If the first element is what you arte looking for then stop
    >Otherwise move to the next element

**Worst case**
We have to look through the entire array of n elements, either because the target is the last element or because it is not in the array `Ο(n)`

**Best case**
The target is the first element and we can stop looking `Ω(1)`

```
int main(void)
{
    int numbers[6] = {4, 8, 15, 16, 23, 42};

    for (int i = 0; i < 6; i++)
    {
        if (numbers[i == 50)
        {
            printf("Found\n");
        }
    }
    printf("Not found\n);
}
```
 Will search for the number 50 and in this case print Not found


 ```
 include <string.h>

int main(void)
{
    string names[4] = {"emma", "Bob", "bill", "ted"};

    for (int i = 0; i < 4; i++)
    {
        if (strcmp (names[i], "emma" ) == 0)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n);
    return 1;
}
```
will search for emma and return found, you must use the strcmp in <string.h> and return values for sucess and faliure

 ```
 include <string.h>

int main(void)
{
    string names[4] = {"emma", "Bob", "bill", "ted"};
    string numbers  = {"617-555-0100", "617-555-0101", "617-555-0102", "617-555-0103"};

    for (int i = 0; i < 4; i++)
    {
        if (strcmp (names[i], "emma" ) == 0)
        {
            printf("%s\n", numbers[i]);
            return 0;
        }
    }
    printf("Not found\n);
    return 1;
}
```

will return the number with the same index as emma but only by assuming that emmas number is the first number like emma is the first name. This is not realistic.

### typedef struct

Is a container for multiple data types

 ```
include <string.h>

typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    person people[4]; 

    people[0].name = "emma";
    people[0].number = "617-555-0100";

    people[1].name = "bob";
    people[1].number = "617-555-0101";

    people[2].name = "bill";
    people[2].number = "617-555-0102";

    people[3].name = "ted";
    people[3].number = "617-555-0103";

    for (int i = 0; i < 4; i++)
    {
        if (strcmp (people[i].name, "emma" ) == 0)
        {
            printf("%s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found\n);
    return 1;
}
```

will return emmas number

## Sorting

### Bubble sort

> repeat n - 1 times 
    >for i from 0 to n -2
        >if i'th and i+1th elements out of order
            >swap them

keep swapping the order of adjacent elements until the elements are in sequence 

repeat until no swaps

keep doing it until there are no numbers left to swap, then stop

### Selection sort

looks for the the smallest number and remembers that and shifts it to the start and then repeats until the numbers are in ascending order

>for i from 0 to n-1
    >find smallest item between i'th item and last item
    >swap smallest item with i'th item

## Recursion

A program, function or algorithm that calls itself.

The follwoing example builds a Mario pyramid like pset1 using recursion

```
#include <cs50.h>
#include <stdio.h>

void draw(int h)

int main(void)
{
    int height = get int("Height: ");

    draw(height);
}

void draw(int h)
{
    if (h == 0)
    {
        return;
    }
    draw(h-1);

    for (int i = 0;  i < h; i++)
    {
        printf("#");
    }
    printf("\n")
}

```

### Merge Sort

> If only one item
    >Return
>else
    >sort left half of items
    >sort right half of items
    >Merge sorted halves

A process that divides again and again uses logarithm log(n) much more efficient
