# C-List-implementation
Implementation of dynamic lists int C

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
