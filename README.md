![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)

# C-List-implementation
Implementation of dynamic lists of int C

# Basic Struct

```C
typedef struct s_list {
	int* values;
	int size;
	struct s_list* (*map)(struct s_list*, void (*)(int*));
	struct s_list* (*sort)(struct s_list*, bool (*)(int, int));
	struct s_list* (*add)(struct s_list*, int);
	struct s_list* (*remove)(struct s_list*, int*);
	struct s_list* (*reverse)(struct s_list*);
	int* (*find)(struct s_list*, bool (*)(int));
	void (*foreach)(struct s_list*, void (*)(int));
	int (*reduce)(struct s_list*, int (*)(int, int));
	int* (*max_ref)(struct s_list* self);
	int* (*min_ref)(struct s_list* self);
	int (*max)(struct s_list* self);
	int (*min)(struct s_list* self);
	void (*destroy)(struct s_list*);
} List;
```

# Get Started
## Initialization

```C
struct s_list* self
// pointer to base struct a.k.a self pointer;
// could be rewritten as private argument to get rid of passing pointer to every function
// but I'd prefer simpler approach, if you want, you can make fork
```

```C
List* to_list(int*, int); // self pointer & size;

{
	...
	List* list = to_list(new int[5] {1, 2, 3, 4, 5});
	// Automatic memory allocation;
	...
}
```

## Destruction & release of memory

```C
void destroy(struct s_list*);

{
	...
	list->destroy(list);
	...
}
```
Always destroy list instance in case of memory leaks;

# Functions & Methods
## Iterators

Iterators - specialized functions to iterate through array;
Some of functions return base instance of list to create assembly of functions;
Every function, except reverse, requires lambda function;

```C
void foreach(struct s_list*, void (*)(int));
int reduce(struct s_list*, int (*)(int, int));
List* map(struct s_list*, void (*)(int*));
List* sort(struct s_list*, bool (*)(int, int));
List* reverse(struct s_list*);
```

## Structure functions
Simple & base functions of primitive logic;
```C
List* add(struct s_list*, int);
List* remove(struct s_list*, int*);
int* find(struct s_list*, bool (*)(int));
int* max_ref(struct s_list*);
int* min_ref(struct s_list*);
int max(struct s_list*);
int min(struct s_list*);
```

# Examples & usage
```C
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int reduce_lambda(int a, int b) {
	return a - b;
}
bool find_lambda(int a) {
	return a == 2;
}
void map_lambda(int* a) {
	*a = *a + 1;
}
void foreach_lambda(int a) {
	printf("%d ", a);
}

#define SIZE 7

int main(void) {
	int array[SIZE] = {6, 5, 4, 3, 2, 1, 0};
	List* list = to_list(array, SIZE);

	list
		->foreach(list, &foreach_lambda);
	// OUTPUT: 6 5 4 3 2 1 0
	printf("\n");
	list
		->reverse(list)
		->foreach(list, &foreach_lambda);
	// OUTPUT: 0 1 2 3 4 5 6
	int* found = list
		->find(list, &find_lambda);	
	// find pointer to element using lambda function
	
	printf("\n");
	list
		->remove(list, found)
		->add(list, 12)
		->foreach(list, &foreach_lambda);	
	// OUTPUT: 0 1 3 4 5 6 12 
	
	printf("\n");
	printf("min: %d\n", list->min(list));
	printf("max: %d\n", list->max(list));
	//min: 0
	//max: 12
	
	list
		->map(list, &map_lambda)
		->foreach(list, &foreach_lambda);
	// OUTPUT: 1 2 4 5 6 7 13
	printf("\n");
	printf("%d", list->reduce(list, &reduce_lambda));
	// OUTPUT: -36
	
	list->destroy(list);

	return 0;
}

```
