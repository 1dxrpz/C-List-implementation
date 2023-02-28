# C-List-implementation
Implementation of dynamic lists int C

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

# Functions & Methods
## Iterators
```C
void foreach(struct s_list*, void (*)(int));
int reduce(struct s_list*, int (*)(int, int));
List* map(struct s_list*, void (*)(int*));
List* sort(struct s_list*, bool (*)(int, int));
List* reverse(struct s_list*);
```

## Structure functions
```C
List* add(struct s_list*, int);
List* remove(struct s_list*, int*);
int* find(struct s_list*, bool (*)(int));
int* max_ref(struct s_list*);
int* min_ref(struct s_list*);
int max(struct s_list*);
int min(struct s_list*);
```
