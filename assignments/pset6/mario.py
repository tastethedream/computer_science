from cs50 import get_int


def main():
    # prompt the user again if the height is < 1 or > 8 
    height = get_int("Please select the height of your pyramid:\n")
    while height < 1 or height > 8:
        height = get_int("Please select the height of your pyramid:\n")
            
    for i in range(height):
        space(height, i)
        hash(i)
        print("  ", end="")
        hash(i)
        print()
        
            
def space(height, i):
    for j in range(height, i + 1, -1):
        print(" ", end="")
    
            
def hash(i):
    for k in range(0, i + 1):
        print("#", end="")
  
            
main()
            
        