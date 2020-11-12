import csv #cannot run outside of cs50 ide

name = input("Name: ")
number = input("Number: ")

with open("phonebook.csv","a") as file:
    writer = csv.writer(file)
    writer = writerow((name, number))
