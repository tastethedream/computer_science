# Week 2 shorts

## variables and scope

- Global varibales are declared outside of the function and can be used anywhere

- Local variables are declared inside a function and can only be used in that function

- Global variables are flexible but dangerous

- For the most part variables are **passed by value** in function calls

- When the variable is passed by value the callee recieves a copy of the passed variable not the variable itself

- This means the variable in the caller is unchanged unless overwritten

This will have no effect on `foo`

```
int main(void)
{
    int foo = 4;
    
int triple(int x)
{
    return x * 3;
}
```

This will alter the value of `foo`

```
int main(void)
{
    int foo = 4;
    foo = triple(foo);
}

int triple(int x)
{
    return x * 3;
}
```
 We overwrite `foo` in `main` this time