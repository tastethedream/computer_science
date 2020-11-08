# Week 4 Memory

## Hexidecimal

> Hex = 16

`0 1 2 3 4 5 6 7 8 9 A B C D E F`

Makes mapping easier because a group of 4 binary digits has 16 different combinations and each of those combinations maps toa single hexidecimal bit

 - RGB codes are in hexidecimal eg FF FF FF is white

 - Convension dictates that hex numbers are prefixed with 0x to indicate it is a hex number eg. 0x0 is 0 to avoid ambiguity

 ```
 #include <stdio.h>

 int main(void)
 {
     int n = 50;
     printf("%p\n", &n);
 }
```

## Pointers

`&` is the **address of** operator and will give you the location in memory of things when used in conjunction with `%p`.

The above code will give you location of 50. **A pointer**
`0x7ffe00b3adbc`

`*` is the opposite of the address operator and means **go to the address**
`printf("%i\n", *&n);`
will give you an output of `50`

You can store addresses in variables


 ```
 #include <stdio.h>

 int main(void)
 {
     int n = 50;
     int *p = &n;

     printf("%p\n", p);
 }
```
You have to let the computer know that `p` is a pointer using `*p`

## Strings

> | E | M | M | A | \O |

Each byte has it's own address

You can use `typedef` to define strings

`typedef char *string;`

```
#include <stdio.h>

int main(void)
{
    char *s = "EMMA";
    printf("%p\n", s);
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);

}
```
> 0x42ab52
> 0x42ab52
> 0x42ab53
> 0x42ab54
> 0x42ab55

You cannot compare strings like integers are even if they are the same they have different addresses for the compare will be different.

## Dynamic Memory Allocation

### malloc()

Memory allocate, requires the number of bytes required passing in plus the null operator 

```
#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");

    char *t = malloc(strlen(s) + 1);

    for (int i = 0; n = strlen(s); i < n + 1; i++)
    {
        t[i] = s[i];
    }
    t[0] = toupper(t[0]);

    printf("%s\n", s);
    printf("%s\n", t);
}
```

## free()

Will hand back the allocated memory

## Valgrind

run valgrind ./filename at command line to look at memory management

you can use this in conjunction with `help50` to better understand the errors

## Temporary variables

```
void swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
```


```
#include <stdio.h>

void swap(int a, int b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is%i\n", x,y);
    swap(x, y);
    printf("x is %i, y is%i\n", x,y);

}
void swap(int a, int b);
{
    int tmp = a;
    a = b;
    b = tmp;
}
```

The program above will swap the values of a and b but not the values of x and y because they are copies.

## The stack

When you call a function, your local variables are stored in the **stack**

```
#include <stdio.h>

void swap(int a, int b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is%i\n", x,y);
    swap(&x, &y);
    printf("x is %i, y is%i\n", x,y);

}
void swap(int *a, int *b);
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
```

This program should give you `x = 2 y = 1` by using addresses instead of values (pointers)

## scanf()

Allows you to get data from the user

`scanf("%i", &x);`

You need to use the address of x here so the fuction can put a value there for you.

```
#include <stdio.h>

int main(void)
{
    char s = [5];
    printf("s: ");
    scanf("%s", s);
    printf("s: %s\n", s)
}
```


## Files

`fprintf()`  print or write to to a file
`fopen()`  open a file
`fclose()` close a file

```
#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    FILE *file = fopen("phonebook.csv", "a");

    char *name = get_string("Name: ");
    char *number = get_string("Mumber: ");

    fprintf(file, "%s,%s\n", name, number);

    fclose(file);

}
```

will create a csv file to store the user input names and phone numbers

Is a file a jpg or not

```
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        return 1;
    }
    // open file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        return 1;
    }
    // read 3 bytes from file
    unsigned char bytes[3];
    fread(bytes, 3, 1, file);

    //check if bytes are 0xff 0xd8 0xff which are the forst 3 bytes oa all jpegs

    if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff)
    {
        printf("Maybe\n");
    }
    else
    {
        printf("No\n");
    }
}
```

