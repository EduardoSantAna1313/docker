#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE 10

int main() {
	int array[ARRAY_SIZE];
	
	int i = 0;
	for (i; i < ARRAY_SIZE; i++) {
		array[i] = i*21;
	}

	printf("|i\t|array i|Address\t|Next\t\t|\n");
	for (i = 0; i < ARRAY_SIZE; i++) {
		const int addres = &array[i];
		const int nextAddress = addres + sizeof (int);
		printf("|%d\t|%d\t|%u\t|%u\t|\n", i, array[i], addres, nextAddress);
	}

	int pos = 5;
	int* pointer = &array;
	pointer += pos;

	printf ("Addres[%d]: %d\n", pos, *pointer);

	char value =  0;
	char *ptr = 0x5800;
	value = *ptr;

	return 0;
}