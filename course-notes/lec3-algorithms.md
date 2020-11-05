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
 #include <string.h>

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

### Binary search

Divide and conquer, only works if the array is already sorted

>Repeat until the (sub)array is size 0
    >calculate the middle point of the sub array
    >if target is at the middle...stop
    >Otherwise, if target is less than whats is in the middle, repeat to the left
    >Otherwise if the target is greater than whats in the middle repeat to the right


 If the target is not in the array....the start point will end up being greater than the end point and give you a sub array of 0 and proves the element does not exist in the array.

 **Worst-case**
 We have to divide the list of n elements in half repeatedly to fund the target either because the target will be found in the last sub array or does not exist `Ο(log n)`

 **Best case** 
 The target is at the midpoint of the original array so we can stop `Ω(1)`

 This search is more efficient than a linear search but can only be used when the array is sorted.


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

In bubble sort the idea of the algorithm is to move higher valued elements towards the right and lower values towards the left

> repeat n - 1 times 
    >for i from 0 to n -2
        >if i'th and i+1th elements out of order
            >swap them

keep swapping the order of adjacent elements until the elements are in sequence 

repeat until no swaps (swap counter is 0)

keep doing it until there are no numbers left to swap, then stop

 **Worst-case**
The array is in reverse order, we have to bubble each of the n elements all the way across the array and since we can only fully bubbble one element into position per pass, we must do this n times `Ο(n²)`

 **Best case** 
 The array is already sorted and we make no swaps on the first pass so we can stop `Ω(n)`


### Selection sort

looks for the the smallest number and remembers that and shifts it to the start and then repeats until the numbers are in ascending order

>for i from 0 to n-1
    >find smallest item between i'th item and last item
    >swap smallest item with i'th item

**Worst-case**
We have to iterate over each of the n elements of the array (to find the smallest) and must repeat the process n times, since only one element gets sorted on each pass `Ο(n²)`

 **Best case** 
 Exactly the same as there is no way to gaurentee the array is sorted until we go through the whole process `Ω(n²)`

## Recursion

A program, function or algorithm that **calls itself**.

Creates elegant code that is both interesting and easy to visualise

The factorial function (n!) is defined over all poitive integers.

n! equals all of the positive integers less than or equal to n, multiplied together

Thinking in terms of programming, we will define the mathamatical function n! as fact(n)

fact(1) = 1
fact(2) = 2 * 1
fact(3) = 3 * 2 * 1
fact(4) = 4 * 3 * 2 * 1
fact(5) = 5 * 4 * 3 * 2 * 1
...


fact(1) = 1
fact(2) = 2 * fact(1)
fact(3) = 3 * fact(2)
fact(4) = 4 * fact(3)
fact(5) = 5 * fact(4)

fact(n) = n * fact(n-1)

Every recursive function has two cases that could apply, given any input

    - The *base case* which when triggered will terminate the recursive process
    - The *recursive case*, which is where the recursion will actually occur

    ```
    int fact(int n)
    {
        if (n = 1) //base case
        {
            return 1;
        }
        else
        {
            return n * fact(n - 1); //recursive case
        }
    }
    ```

    In general, but not always a recursive function can replace a loop



**multiple base cases**

**Fibonacci** -
    - first element is 0
    - second element is 1
    - the nth element is the sum of the (n-1)th and (n-2th) elements

**Multiple recursive cases**

**The Collatz conjecture**

The Collatz conjecture is applied to positive integers and speculates that is is always possible to get back to 1 if you follow these steps

    - If n is 1 stop
    - Otherwise if n is even then repeat this process on n/2
    - Otherwise if n is odd, repeat this process on 3n + 1

```
int collatz(int n)
{
    //base case
    if (n == 1)
        return 0;
    //even numbers
    else if ((n % 2) == 0)
        return 1 + collatz(n/2);
    odd numbers
    else
        return 1 + collatz(3 * n + 1)
}
```
**- The following example builds a Mario pyramid like pset1 using recursion**

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

### Insertion sort

In insertion sort, the idea of the algorith is to buils your sorted array in place, shifting elements out of the way if necessary to make room as you go

> Call the first element of the array "sorted"
    > Repeat until all elements are sorted
        > Look at the next unsorted element, insert into the "sorted" position by shifting the requisite number of elements


**Worst-case**
The array is in reverse order and we have to shift each of the n elements n positions each time we make an insertion`Ο(n²)`

**Best-case**

 The array is perfectly sorted and we simply keep moving the line between "unsorted" and "sorted" as we examine each element`Ω(n)`


### Merge Sort

The idea of the algorithm is is to sort smaller arrays and then combine them in sorted order, using recursion

> If only one item
    >Return
>else
    >sort left half of items
    >sort right half of items
    >Merge sorted halves

A process that divides again and again uses logarithm log(n) and is much more efficient

**Worst case**
We have to split n elements up and recombine them, effectively doubling the sorted sub arrays as we build them. `Ο(n log n)`

**Best-case**
The array is already perfectly sorted but we have to split and recombine it back together `Ω(n log n)`
