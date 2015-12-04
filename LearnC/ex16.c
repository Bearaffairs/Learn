#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

/* stdlib is required for malloc and free, the allocation for the structure.
   string is required for str duplication 
   assert for the assert function to test if something is false. */

//Creates a person structure which should contain elements to describe a person

struct Person{

	char *name;	
	int age;
	int height;
	int weight;
};

//Allocates a space of memory, assert it to make sure the space is valid then	 initialises the variables for each instance created. strdup is to ensure it is  owned by the structure.
 
struct Person *Person_create(char *name, int age, int height, int weight){

	struct Person *who = malloc(sizeof(struct Person));
	assert(who != NULL);

	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight = weight;
	
	return who;
	};

//Allows the destruction of a person struct and free memory and prevent leaks

void Person_destroy(struct Person *who){

	assert(who != NULL);
	
	free(who->name);
	free(who);
	};

//Prints out the data  for the person specified in the passed argument 
void Person_print(struct Person *who){

	printf("Name: %s\n", who->name);
	printf("\tAge: %d\n", who->age);
	printf("\tHeight: %d\n", who->height);
	printf("\tWeight: %d\n", who->weight);

	};

int main(int argc, char *argv[]){

	//make two people sructures

	struct Person *joe = Person_create(
		"Joe Alex", 32, 64, 140);

	struct Person *frank = Person_create(
		"Frank Blank", 20, 72, 180);

	//print them out and where they are in memory

	printf("Joe is at memory location %p:\n", joe);
	Person_print(joe);

	printf("Frank is at memory location %p:\n", frank);
	Person_print(frank);

	//make everyone age 20 years and print them again

	joe->age += 20;
	joe->height -= 2;
	joe->weight += 40;
	Person_print(joe);

	frank->age += 20;
	frank->weight += 20;
	Person_print(frank);

	//destroy them both so we clean up memory
	Person_destroy(joe);
	Person_destroy(frank);

	return 0;
}
