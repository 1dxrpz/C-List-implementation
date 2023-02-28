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
	printf("\n");
	list
		->reverse(list)
		->foreach(list, &foreach_lambda);
	
	int* found = list
		->find(list, &find_lambda);	
	
	printf("\n");
	list
		->remove(list, found)
		->add(list, 12)
		->foreach(list, &foreach_lambda);	

	printf("\n");
	printf("min: %d\n", list->min(list));
	printf("max: %d\n", list->max(list));

	list
		->map(list, &map_lambda)
		->foreach(list, &foreach_lambda);
	printf("\n");
	//printf("%d", list->reduce(list, &reduce_lambda));
	
	list->destroy(list);

	return 0;
}
