# Lecture 6 Python

File naming convention **filename.py**

To run is CS50 IDE `python filename.py`

`print("Hello World")`

## Print

```
answer = get_string("What is your name?\n")
print("Hello, " + answer)
```
or
```
answer = get_string("What is your name?\n")
print(f"Hello,  {answer}")
```
- `f` - format string tells python not to print literally "Hello,  {answer}"

## Counters

- `++` operator does not exixt in python use `counter += 1`

## Conditions

```
if x < y:
    print("x is less than y")
```

Python is sensitive to white space so indentation is important

```
if x < y:
    print("x is less than y")
else:
    print("x is not less than y")
```

```
if x < y:
    print("x is less than y")
elif x > y:
    print("x is greater than y")
else:
    print("x is equal to y")
```

`elif`  - else if

## Loops

```
while True:
    print("hello, world")
```

> True and False have capital first chars

```
i = 3
while i > 0:
    print("cough")
    i -= 1
```
or

```
for i in [0, 1, 2]:
    print("cough")
```

> [] - represents a list

```
for i in range(3):
    print("cough")
```

> `range` returns a sequence of numbers, starting from 0 by default, and increments by 1 (by default), and stops before a specified number.

## Data Types 

- bool      bolean
- float     float
- int       integer
- str       string
- range     sequence of numbers 
- list      sequence of mutable values (array)
- tuple     sequence of immutable values
- dict      collection of key/value pairs (hash table)
- set       collection of unique values 

### Python example - image bluring

```
from PIL import Image, ImageFilter

before = Image.open("bridge.bmp")
after = before.filter(ImageFilter.BLUR)
after.save("out.bmp")
```

### Python example - speller

```
words  = set()

def check(word):
     if word.lower() in words:
        return True
    else:
        return False

def load(dictionary):
    file = open(dictionary, "r")
    for line in file:
        // restrip will delete the /n from the end of each line
        words.add(line.rstrip("\n"))
    file.close()
    return True    

def size():
    return len(words)

def unload():
    return True

```

The python version is much quicker to write but takes much longer to get the results from the program.

## Functions

`def` - define 

```
def main():
    for i in range(3):
        cough()

def cough():
    print("cough")

main()

```

### Python example mario

```
for i in range(4):
    print("?", end"")
print()

```

## Named arguements

`print` can take an arguement `end` whose value can equal what ever you want it to
`print("?", end="")

`input` always returns a string
`int` will convert a string to an integer `int(input(What is your age?\n))`

`int` has no upper bounds

## Command Line Arguments

You can import `argv` and `exit` etc from a library `from sys import argv`

`argc` does not exist but you vcan use the length of `argv`  eg.  `for i in range(len(argv)):`

## Dictionaries

- Dictionaries (hash tables) are enclosed in {}

```
people = {
    "EMMA": "617-555-0100",
    "RODRIGO": "617-555-0101",
    "BRIAN": "617-555-0102",
    "DAVID": "617-555-0103"
}
```
- Keys and values are seperated with a : and each pair is seperated with a comma.

## Regular Expressions

- .   any character
- .*  0 or more characters
- .+  1 or more characters
- ?   optional
- ^   start of input
- $   end of input


Python regular expression library - `re`  `import re`

