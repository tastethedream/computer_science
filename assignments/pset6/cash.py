from cs50 import get_float

change = 0.00

while change < .01:
    change = get_float("Change owed: ")

n = change * 100
count = 0

# Quarters
while n >= 25:
    count += 1
    n = n - 25

# Dimes
while n >= 10:
    count += 1
    n = n - 10

# Nickles
while n >= 5:
    count += 1
    n = n - 5

# Pennies
while n >= 1:
    count += 1
    n = n - 1

print(count)
