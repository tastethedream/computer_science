# Week 2 Shorts

## Arrays

- Arrays are a fundamental data structure

- An array is a contiguous space in memory which has been split into equal sized blocks of space called **elements**

- Each of the **elements** can store a certain amount of data

- The data must be of the same data type eg int, char etc

- Elements can ve accessed by its `index`

- Arrays begin at `index 0`

- Arrays end at `index (n-1)`

### Array Declaration

`type name[size];`

- `type` what kind of variable each element will be e.g int, string etc

- `name`  meaningful name for your array

- `size` how many elements you would like your array to contain. This is placed in []

`double menu_prices[8];`

When you delace abd initialise and array simultaneousley there is a special syntax that may be used to fill up the array with its' starting values

```
// instantiation syntax
bool truthtable[3] = {false, true, true};

// individual element syntax
bool truthtable[3];
truthtable[0] = false;
truthtable[1] = true;
truthtable[2] = true;
```

The above will produce the exact same array

- you can also leave the array sizer blank[] in the instantiation

 - Arrays can consist of more than one single dimension eg

 `bool battleship[10][10];`

 -This will give you a grid of cells 10 x 10 but is actually only a 100 element array but can be helful when trying to visualise element positions.

 - Each array element can be treated like a variable

 - You cannot treat whole arrays as variables

 - If you want to copy one array into another you have to use a loop to copy them in element by element

 - Most variables in C are passed by value in function calls

 - Arrays do not follow this rule they are passed by reference and when called the callee gets the actual array not a copy of it







