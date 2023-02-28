#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdbool.h>

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

void f_foreach(struct s_list*, void (*)(int));
int f_reduce(struct s_list*, int (*)(int, int));
List* f_map(struct s_list*, void (*)(int*));
List* to_list(int*, int);
List* f_sort(struct s_list*, bool (*)(int, int));
List* f_add(struct s_list*, int);
List* f_remove(struct s_list*, int*);
List* f_reverse(struct s_list*);
int* f_find(struct s_list*, bool (*)(int));
int* f_max_ref(struct s_list* self);
int* f_min_ref(struct s_list* self);
int f_max(struct s_list* self);
int f_min(struct s_list* self);

#endif
