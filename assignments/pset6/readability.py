
from cs50 import get_string
from cs50 import get_float

# variables
words = 0
sentences = 0
chars = 0

# input from the user
text = input("Input your text: ")

# word count
words += 1

# count the Characters, Words and Sentences
for i in range(len(text)):
    if text[i].isalpha():
        chars += 1
    elif text[i] == ' ' and text[i+1] != ' ':
        words += 1
    elif (text[i] == '?') or (text[i] == '.') or (text[i] == '!'):
        sentences += 1
    else: 
        if words > chars: 
            words = 0

# calculate the grade
if words != 0:
    L = (chars*100)/words
    S = (sentences*100)/words
    index = round(((0.0588 * L) - (0.296 * S) - 15.8))

    if (index < 1):
        print("Before Grade 1\n")
    elif (index > 16):
        print("Grade 16+")
    else:
        print(f"Grade {index}")