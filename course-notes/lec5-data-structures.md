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

```
// Implements a list of numbers with linked list

#include <stdio.h>
#include <stdlib.h>

// Represents a node
typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(void)
{
    // List of size 0
    node *list = NULL;

    // Add number to list
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->number = 1;
    n->next = NULL;
    list = n;

    // Add number to list
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->number = 2;
    n->next = NULL;
    list->next = n;

    // Add number to list
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->number = 3;
    n->next = NULL;
    list->next->next = n;

    // Print list
    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("%i\n", tmp->number);
    }

    // Free list
    while (list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }
}
```
### Trees

 Unlike Arrays, Linked Lists, Stack and queues, which are linear data structures, trees are hierarchical data structures.

#### Tree Vocabulary

 The topmost node is called root of the tree. The elements that are directly under an element are called its children. The element directly above something is called its parent. For example, ‘a’ is a child of ‘f’, and ‘f’ is the parent of ‘a’. Finally, elements with no children are called leaves.

#### Main applications of trees include:
1. Manipulate hierarchical data.
2. Make information easy to search (see tree traversal).
3. Manipulate sorted lists of data.
4. As a workflow for compositing digital images for visual effects.
5. Router algorithms
6. Form of a multi-stage decision-making.

### Hash tables

Is a combination of an array(random access ability) and linked lists(dynamism).

If we define our hash table well
    - Inserstion can start to tend toward O(1) - constant time
    - Deletion cab start to tend towards O(1)
    - Lookup can start to tend towrds O(1)

> Collision - If you have a value you wish to put somewhere but there is already something in this location. This can be resolved with **linear probing** 

#### Linear Probing

- Try to place the data in the next consecutive element in the array

- This is subject to a problem called **clustering**

#### Resolving collisions: Chaining

- Each element of the array can hold multiple peices of data, if each elelemt of the array is a pointer to the hread of a linked list, then multiple peices of data can yield the same hash code abd we can store it all.

- We can eleiminate clustering by doing this

- We know thart insertion and creation in linked lists is an O(1) operation

- For lookup we only need to search through what we hope is a small list



- You index into this type of array using a **hash function**

> Hash function - decides which bucket to put the data in for example by the first character of the name (alphabetically)

- A good hash function should:
    - Use only the data being hashed
    - Use all of the data being hashed
    - Be deterministic
    - Uniformly distribute data
    - Generate very different hash codes for very similar data

```
unsigned int hash(char* str)
{
    int sum = 0;
    for (int j = 0; str[j] != '\0'; j++)
    {
        sum += str[j];
    }
    return sum % HASH_MAX:
}
```
As a rule you wouldn't write your own hash functions


### Tries

(Short for retreival) Uses more memory but gives actual constant time look up for names or words.

- Tries combine structures and pointers together to store data in an interesting way

- The data to be searched for in the trie is now a road map.
    - If you can follow the map from begining to ens, the data exists in the trie
    - If you can't, it doesn't

- Unlike a hash table, there are no collisions and no twi pieces of data(unless they are identical) have the same path.

> is a tree each of whose nodes is an array
> you look at each letter of the name rather than just the first few as in the hash table.

- Lets map key-value pairs where the keys are 4 digit years(yyyy) and the values are the names of universities founded in that year

- In a trie, the paths for a central **root** node to a **leaf** node

- each node on the path from root to leaf could have 10 pointers emanating from it, one for each digit.

```
typedef struct_trie
{
    char university[20];
    struct_trie* paths[10];
}
trie;
```


### Queues

A data structure (FIFO)

> enqueue - get in line
> dequeue - get out of line

### Stacks

A data structure (LIFO)

> Push - add to the stack
> Pop -  removing the top element in the stack


















