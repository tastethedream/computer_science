# Week 7 SQL

> Structured Query Language

## Reading CSV files

```
import csv

counts = {}

with open ("filename.csv". "r") as file:
    reader = csv.Dictreader(file)

    for row in reader:

        for rowm["title"]

        if title in counts
            counts[title] += 1
        else:
            counts[title] = 1

for title, count in counts.items():
    print(title, count, sep=" | ")
```

The above code example looks at a csv file full of peoples favorite tv shows and their genres. It reads the file, creates a count for each title and then prints the title and it's count sperated by |.

## Sorting CSV files

**To sort the data by title**

```
import csv

counts = {}

with open ("filename.csv". "r") as file:
    reader = csv.Dictreader(file)

    for row in reader:

        for row["title"].lower()

        if title in counts
            counts[title] += 1
        else:
            counts[title] = 1

for title, count in sorted(counts.items()):
    print(title, count, sep=" | ")
```
> `sorted()` will sort your data in python

**To sort the data by count**

```
import csv

counts = {}

with open ("filename.csv". "r") as file:
    reader = csv.Dictreader(file)

    for row in reader:

        for rowm["title"]

        if title in counts
            counts[title] += 1
        else:
            counts[title] = 1

for title, count in sorted(counts.items(), key=lambda item: item[1], reverse=True):
    print(title, count, sep=" | ")
```
> `lambda` is an anonymous function that will only be used once

## Relational Databases

- More robust than using CSV files

- Store data

- Provide you with faster access to your data

### sqlite3

Is a command line program that allows you to interact with data

- mode csv
- import FILE TABLE
- schema

### Operations

- Create
- Read
- Update
- Delete

### SQL

- INSERT
    Add info to a table
        INSERT INTO
        <table>
        (<columns>)
        VALUES
        (<values>)

- SELECT
    Get info from a table
        SELECT
        <columns>
        FROM
        <table>
        WHERE
        <condition>
        ORDER BY
        <column>

    SELECT * will give you everything available

- SELECT (JOIN)
    Extract info from multiple tables
        SELECT
        <columns>
        FROM
        <table1>
        JOIN
        <table2>
        ON
        <predicate>

- UPDATE
    Modify data in a table
        UPDATE
        <table>
        SET
        <column> = <value>
        WHERE
        <predicate>

- DELETE
    Remove info from a table
        DELETE FROM
        <table>
        WHERE
        <predicate>
...

`CREATE TABLE table (column type, ...)`

### SQL Data Types

- BLOB (for binary data)
- INTEGER (smallint, integer, bigint)
- NUMERIC (boolean, date, datetime, numeric(scale,precision) time, timestamp)
- REAL (real, double precision)
- TEXT (char(n) varchar(n) text) 

### SQL Functions

- AVG
- COUNT
- DISTINCT
- MAX
- MIN
...

### Primary Key

- Choose 1 column to be your **primary key**
- Prinary keys enable rows of a table tp be uniquely and quickly identified
- It is possible to establish a joint primary key which is a combination of 2 columns that is always unique.

### TSV files

Tab Seperated Values

