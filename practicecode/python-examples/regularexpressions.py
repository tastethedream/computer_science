import re

s = input("Do you agree?\n")

if re.search("^y(es)?$", s, re.IGNORECASE):
    print("Agreed")
elif re.search("^n(o)?$", s):
    print("Not agreed")