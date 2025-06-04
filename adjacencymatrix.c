#include<stdio.h>
#define V 10
//This is for undirected, unweighted graph
void add_edge(int mat[V][V], int i, int j) {
	mat[i][j] = 1;
	mat[j][i] = 1;
}

void display(int mat[V][V]) {
	for(int i = 0; i < V; i++) {
		for(int j = 0; j < V; j++) {
			printf("%d   ", mat[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int mat[V][V] = {0};
	add_edge(mat,0,1);
	add_edge(mat,0,2);
	add_edge(mat,1,2);
	add_edge(mat,2,3);
	add_edge(mat,4,8);
	display(mat);
	return 0;
}
