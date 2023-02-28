#include "list.h"
#define INT_MAX 2147483647
#define INT_MIN -2147483648

void u_swap (int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}
List* f_map(struct s_list* self, void (*lambda)(int* a)) {
	for (int i = 0; i < self->size; i++)
		lambda(&self->values[i]);
	return self;
}
List* f_reverse(struct s_list* self) {
	for (int i = 0; i < self->size / 2; i++) {
		u_swap(&self->values[i], &self->values[self->size - i - 1]);
	}
	return self;
}
void f_foreach(struct s_list* self, void (*lambda)(int a)) {
	for (int i = 0; i < self->size; i++)
		lambda(self->values[i]);
}
int f_reduce(struct s_list* self, int (*lambda)(int acc, int num)) {
	int result = self->values[0];
	for (int i = 1; i < self->size; i++)
		result = lambda(result, self->values[i]);
	return result;
}
void f_destroy (struct s_list* self) {
	free(self->values);
	free(self);
}
List* f_sort(struct s_list* self, bool (*lambda)(int a, int b)) {
	return self;
}
List* f_add(struct s_list* self, int a) {
	self->values = realloc(self->values, sizeof(struct s_list) * (self->size + 1));
	self->values[self->size] = a;
	self->size += 1;
	return self;
}
List* f_remove(struct s_list* self, int* a) {
	for (int* p = a; p - a < self->values[self->size - 1]; p++) {
		int* s = (p + 1);
		u_swap(p, s);
	}
	self->values = realloc(self->values, sizeof(struct s_list) * (self->size - 1));
	self->size -= 1;
	return self;
}
int* f_find(struct s_list* self, bool (*lambda)(int a)) {
	int* result = NULL;
	for (int i = 0; i < self->size; i++) {
		if (lambda(self->values[i])) {
			result = &self->values[i];
			break;
		}
	}
	return result;
}
int* f_max_ref(struct s_list* self) {
	int* result = &self->values[0];
	for (int* p = &self->values[0]; p - self->values < self->size; p++) {
		if (*p > *result)
			result = p;
	}
	return result;
}
int* f_min_ref(struct s_list* self) {
	int* result = &self->values[0];
	for (int* p = &self->values[0]; p - self->values < self->size; p++) {
		if (*p < *result)
			result = p;
	}
	return result;
}
int f_max(struct s_list* self) {
	return *f_max_ref(self);
}
int f_min(struct s_list* self) {
	return *f_min_ref(self);
}

List* to_list(int* array, int size) {
	List* list = malloc(sizeof(struct s_list));
	list->size = size;
	int* values = malloc(sizeof(int) * size);
	for(int i = 0; i < size; i++)
		values[i] = array[i];
	list->values = values;
	list->sort = &f_sort;
	list->add = &f_add;
	list->remove = &f_remove;
	list->reverse = &f_reverse;
	list->find = &f_find;
	list->map = &f_map;
	list->reduce = &f_reduce;
	list->foreach = &f_foreach;
	list->destroy = &f_destroy;
	list->min_ref = &f_min_ref;
	list->max_ref = &f_max_ref;
	list->min = &f_min;
	list->max = &f_max;
	return list;
}

