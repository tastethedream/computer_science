# Lecture 5 Data Structures

## Pointers

```
int main(void)
{
    int *x;
    int *y;

    x = malloc(sizeof(int));

    *x = 42;
    *y = 13;
}
```
 initially pointers don't point to anything(the pointee). This is a seperate step

 ## Arrays

 Resizing an array is inefficient `O(n)` (insert) but you can use `malloc` to allocate more memory

 ```
 int main(void)
 {

    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        return 1;
    }

     list[0] = 1;
     list[1] = 2;
     list[2] = 3;

     for (int i = 0; i < 3; i++);
     {
         printf("%i\n", list[i]);
     }
 }
 ```

 Header file for `malloc` is <stdlib.h>

 `realloc()` will reallocate memory and is a simpler way of dealing with adding memory.

  ```
  // Implements a list of numbers with an array of dynamic size using realloc

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // List of size 3
    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        return 1;
    }

    // Initialize list of size 3 with numbers
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // Resize list to be of size 4
    int *tmp = realloc(list, 4 * sizeof(int));
    if (tmp == NULL)
    {
        return 1;
    }
    list = tmp;

    // Add number to list
    list[3] = 4;

    // Print list
    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    // Free list
    free(list);
}
  ```

  Data structures allow you to store things in your computers memory.

  `struct` - allows you to create your own structure
  `.` - Dot notation allows you to access a property of a structure.
  `*` - Star operator allows you to go to a chunk of memory by way of a pointer.

  ## Singly-Linked Lists

  - Is a data structure containing multiple chunks of memory that are somehow linked together by pointers.

  - A linked list node is a special kind of `struct` with 2 members
    1. Data of some type
    2. A pointer to another node of the same data



  ```
  typedef struct node
  {
      int number;
      struct node* next;
  }
  node;
  ```

  ```
  node *n = malloc(sizeof(node));
  if (n != NULL)
  {
      n->number = 4;
      n->next = NULL;
  }
  ```

  - In order to work with linked lists there are a number of operations that we need to understand:

  1. Create a linked list when it doesn't already exist.
  2. Search through a linked list to find an element.
  3. Insert a new node.
  4. Delete a single element from the list.
  5. Delete an entire list (free up the memory).

  ### Create a linked list

  `sllnode* create(VALUE val);`

  - Dynamically aloocate space for a new `sllnode` (malloc)
  - Check to make sure we didn't run out of memory
  - Initialise the nodes `val` field
  - Initialise the nodes `next` field
  - Return a pointer to the newly created `sllnode`

  `sllnode* new = create(6)`

  ### Search a linked list

  `bool find(sllnode* head, VALUE val);`

- Create a traversal pointer pointing to the lists head (first value)
- If the current node's `val` field is what we are looking for, report sucesss
- If not, set up the traversal pointer to the next pointer in the list and check if that is what you are looking for
- If you have reached the end of the list report faliure  

`bool exists = find(list, 6)`

### Insert a new node in the list

`sllnode* insert(sllnode* head, VALUE val);`

- Dymaically allocate space for a new `sllnode` (malloc)
- Check to make sure we did not run out of memory
- Populate and insert the node **at the begining of the linked list**
- Return a pointer to the new head of the linked list

`list = insert(list, 12);`

**ORDER MATTERS** connect the new element into the list before moving the pointer

### Delete an entire list

`void destroy(sllnode* head);`

- If you have reached a null pointer - stop!
- Delete the rest of the list `destroy(list);`
- Free the current node

Similar to recursion, delete everything else and then delete me.



















