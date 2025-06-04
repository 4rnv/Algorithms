#include<stdio.h>
#include<stdlib.h>

// Vectors aka dynamic arrays aka arraylist aka slices

struct vector{
	int capacity; //capacity of vector
	int current; //index where next element will be pushed
	int* container; //pointer to first element in array, in a sense the array itself
	int default_value; //default value specified by user
};

struct vector makeVec(int capacity, int default_value) {
	struct vector v;
	v.current = 0;
	v.capacity = capacity;
	v.container = (int*)malloc(capacity*capacityof(int));
	v.default_value = default_value;
	if(v.container==NULL) {
		printf("Malloc failed");
	}
	else {
		for(int i=0; i<capacity; i++) {
			v.container[i] = default_value;
		}
	}
	return v;
}

void pushVec(struct vector* v, int value) {
	if(v->current!=v->capacity) {
		//-> is used instead of . because we are pointing to an instance of the struct, not the struct itself.
		//. is used only while defining the struct
		v->container[v->current] = value;
		v->current++;
	}
	else {
		int new_capacity = v->capacity*2;
		int* new_container = (int*)malloc(new_capacity*sizeof(int));
		if(new_container==NULL) {
			printf("Malloc failed");
			return;
		}
		for(int i=0;i<new_capacity;i++) {
			new_container[i] = (i < v->capacity) ? v->container[i] : v->default_value;
		}
		free(v->container);
		v->capacity = new_capacity;
		v->container= new_container;
		v->container[v->current] = value;
		v->current++;
	}
}

int displayAt(struct vector* v, int index) {
	if(index>=0 && index < v->current) {
		return v->container[index];
	}
	printf("\nIndex %d out of bounds for vector of capacity %d", index, v->current);
	exit(1);
}

void displayEnt(struct vector* v) {
	printf("\n");
	for(int i=0; i< v->capacity; i++) {
		printf("%d ", v->container[i]);
	}
	printf("\n");
}

void freeVec(struct vector* v) {
	if(v->container!=NULL) {
		free(v->container);
	}
	v->container=NULL;
}

void pushAt(struct vector* v, int index, int value) {
	if(index<0 || index > v->current) {
		printf("\nIndex %d out of bounds for vector of capacity %d", index, v->current);
		return;
	}
	if(v->current==v->capacity) {
		int new_capacity = v->capacity*2;
		int* new_container = (int*)malloc(new_capacity*sizeof(int));
		if(new_container==NULL) {
			printf("Malloc failed");
			return;
		}
        for (int i = 0; i < v->current; i++) {
            new_container[i] = v->container[i];
        }
		free(v->container);
		v->capacity = new_capacity;
		v->container= new_container;
	}
	for (int i = v->current; i > index; i--) {
        v->container[i] = v->container[i - 1];
    }
	v->container[index] = value;
    v->current++;
}

//to be added functions
//pushAt (push at particular index)
int main() {
	struct vector v1 = makeVec(1,0);
	for(int i=11; i<21; i++) {
		pushVec(&v1,i);
	}
	int index=5;
	printf("Element at index %d is %d", index, displayAt(&v1,index));
	displayEnt(&v1);
	pushVec(&v1, 19);
	displayEnt(&v1);
	pushAt(&v1, 5, 99);
	displayEnt(&v1);
	printf("%d", displayAt(&v1,20)); //error

	freeVec(&v1);
	return 0;
}
