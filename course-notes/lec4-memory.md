# Week 4 Memory

## Hexidecimal

> Hex = 16

`0 1 2 3 4 5 6 7 8 9 A B C D E F`

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

## malloc()

Memory allocate, requires the number of bytes required passing in
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