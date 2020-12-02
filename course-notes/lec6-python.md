# Lecture 6 Python 3

File naming convention **filename.py**

To run is CS50 IDE `python filename.py`

Python does not necesserily need to be compliled

`print("Hello World")`

## Variables

- No type specifier
- Declared by initialisation only

`phrase = "This is CS50"`

- You can use `""` or `''`

- `#` for comments

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

`input()` - to collect user input at the command line


## Counters

- `++` operator does not exixt in python use `counter += 1`

## Conditions

- or  `if y > 43 or z == 56:`
- and
- if
- else
- elif  - else if 
- True
- False


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

## Loops

- while
- for 

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

## Lists [arrays]

- Arrays in python are called lists

- You can grow and shrink as you need

### Declaring a list

` nums = []`

` nums = [1, 2, 3, 4]`

`nums = [x for x in range(500)]` - list comprehension

### Appending to a list

- will append to the end of a list

```
nums [1, 2, 3, 4]
nums.append(5)
```

### Inserting in a list

- will insert to a specific location in the list

```
nums [1, 2, 3, 4]
nums.insert(4, 5)
```
will place the number 5 in position 4

### Add lists together

- attach one list to the end of another list

```
nums = [1, 2, 3, 4]
nums[len(nums):] = [5]
```



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

### Tuples[]

Tuples are ordered, immutable sets of data. They are good for associating collections of data (like a struct??) but where the values are unlikley to change.

```
presidents = [
    ("George Wasington", 1789),
    ("John Adams", 1797),
    ("Thomas Jefferson", 1801),
    ("James Maddison", 1809)
]
```

- The tuple is iterable

```
for prez, year in presidents:
    print("In {1}, {0} took office".format(prez, year))
```

### Dictionaries{}

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

- `people["EMMA"] = "617-555-6000"` will amend the telehone number for emma

- `print("Our boss" + name + "can be reached on" + number)`

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

## Objects

- Python is an object-oriented programming language

- An object is sort of analgous to C

- C structures contain a number of fields which we maty also call properties

- The properties themselves can never stand on their own

- Objects, meanwhile have properties but also **methods** or functions that are inherent to the object, and mean nothing outside of it. You define the methods inside the object also

- Thus, properties and methods don't ever stand on their own

- `object.method()`

- You can define a type of object using the `class` keyword in Python

- Classes require an initialisation function **contructor** which sets the starting values of the properties of the object

- In defining each method of an object, `self` should be it's first parameter, which stipulates on what object the method is called

```
class Student():

    def __init__(self, name. id):
        self.name = name
        seld.id = id

    def changeID(self, id):
        self.id = id

    def print(self):
        print("{} - {}".format(self.name, self.id))    
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

## Regular Expressions

- .   any character
- .*  0 or more characters
- .+  1 or more characters
- ?   optional
- ^   start of input
- $   end of input


Python regular expression library - `re`  `import re`

## Python Syntax

### Style

- Good style is crucial in Python
- Tabs and indentation actually matter and things will not work properly if you disregard this
- No more curly braces to delineate blocks! only used for dictionaries

