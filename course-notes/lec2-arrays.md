# lecture 2 Arrays

 - Prepocessing

 - Compiling

 - Assembling

 - Linking

 ## Debugging

 ### debugging in the sandbox

-  `help50 filename` - cs50s help to simplfy debugging messages

-  `printf()` like console.log good for debugging


 ### debugging in the cs50 IDE

- `debug50 filename.c` -  will open up the debugger

- `ctrl c` will take you out of the debugger

- `style50` -  green blocks indicate you should add space
            -  red blocks indicate excess space or style error

- `check50` - to check for errors


## Design

A subjective method of solving problems well

### storage

`char`  1 byte
`bool`  1 byte
`int`   4 bytes
`float` 4 bytes
`long`  8 bytes
`double` 8 bytes
`string` ? bytes

**in C '' are used for chars and "" for strings**

repetitiveness is an oppertunity for a better design

The first location in an array is always 0

```
int scores[3]
scores[0] = 72;
scores[1] = 73;
scores[2] = 33;

printf("average: %i\n", scores[0] + scores[1] + scores[3] / 3);

```
The aboves uses an array but the design is still not great and repeats itself.

### Use a constant


```
const int N = 3;

int main(void)
{
int scores[N]
scores[0] = 72;
scores[1] = 73;
scores[2] = 33;

printf("average: %i\n", scores[0] + scores[1] + scores[3] / N);
}
```
**consts are capitalised**

```
#include <cs50.h>
#include <stdio.h>

float average(int length, int array[]);

int main(void)
{
    // Get number of scores
    int n = get_int("Scores:  ");

    // Get scores
    int scores[n];
    for (int i = 0; i < n; i++)
    {
        scores[i] = get_int("Score %i: ", i + 1);
    }

    // Print average
    printf("Average: %.1f\n", average(n, scores));
}

float average(int length, int array[])
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return (float) sum / (float) length;
}
```

`\0` null terminating character indicates the end of a string

> print a string character by character

```
#include <string.h>

int main(void)
{
    string s = get_string("input: ");
    printf("output: ");
    for (int i = 0; n = strlen(s); i < n; i++)
    {
        printf("%c, s[i]);
    }
    printf("\n");
}
```
> Change string to uppercase

```
// Uppercases string using ctype library

#include <cs50.h>
#include <ctype.h> // library that contains `toupper` 
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After:  ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", toupper(s[i]));
    }
    printf("\n");
}
```

### int main(int argc, string argv[])

Int main takes 2 conditions

#### int argc

> argc - argument count
> the length of the array???

#### string argv[]

> argv - argument vector

> an array of strings 

```
// Printing a command-line argument

#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        printf("hello, %s\n", argv[1]);
    }
    else
    {
        printf("hello, world\n");
    }
}
```

`main` has a default return value of 0 and it indicates all is well.

```
// Returns explicit value from main

#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("missing command-line argument\n");
        return 1;
    }
    printf("hello, %s\n", argv[1]);
    return 0;
}
```
Returning 1 here indicates that something went wrong


## Shorts for week 2

## Functions



















