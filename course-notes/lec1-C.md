# Lecture 1 week 2 C

```

# include <stdio.h>
int main(void)
{
    printf("hello, world");
}
```

`int main(void)` - The begining of a function definition (void) = takes no input 

`printf()`  - print formatted text


`# include <stdio.h>` - indicates the <file> that holds your code.

## Programmimng environment

www.sandbox.cs50.io

### create file name

`filename.c`

### Run the program

source code --> compiler --> machine code


terminal - `gcc filename.c` to compile

terminal - `ls`  to look for compiled file if its green it is executable

terminal - `./a.out` to run

### printing on a new line
```
# include <stdio.h>
int main(void)
{
    printf("hello, world\n");
}
```
