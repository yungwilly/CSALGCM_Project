#include <limits.h>
#include <stdbool.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ** createZeroMatrix(int n){
	int ** array = (int**)malloc(n*sizeof(int *));	
	int i,j;
	for(i = 0;i < n; i++) {
	    	array[i] = (int*)malloc(n*sizeof(int));
   	 	for(j = 0; j < n; j++) {
	        	array[i][j] = 0;
	    	}
	}
	return array;
}


// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[], int V)
{
	// Initialize min value
	int min = INT_MAX, min_index;
	int v;
	for (v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

// A utility function to print the constructed distance array
void printSolution(int dist[],int V)
{
	printf("Vertex \t\t Distance from Source\n");
	int i;
	for (i = 0; i < V; i++)
		printf("%d \t\t %d\n", i, dist[i]);
}

void UndirectedMatix(int ** AdjMatrix, int nSize, int matrixSize, int col1[], int col2[], int col3[]) {
  int i,x = 0,y = 0,key = 0;
	
	for(i = 1; i < nSize; i++){
		x = col1[i];
		y = col2[i];
		key = col3[i];
		AdjMatrix[x][y] = key;
		AdjMatrix[y][x] = key;
	}
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra_greedy(int ** AdjMatrix, int src, int V)
{
	int dist[V]; // The output array. dist[i] will hold the shortest
	// distance from src to i

	bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest
	// path tree or shortest distance from src to i is finalized

	// Initialize all distances as INFINITE and stpSet[] as false
	int i;
	for (i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	int count;
	for (count = 0; count < V - 1; count++) {
		// Pick the minimum distance vertex from the set of vertices not
		// yet processed. u is always equal to src in the first iteration.
		int u = minDistance(dist, sptSet,V);

		// Mark the picked vertex as processed
		sptSet[u] = true;

		// Update dist value of the adjacent vertices of the picked vertex.
		int v;
		for (v = 0; v < V; v++)

			// Update dist[v] only if is not in sptSet, there is an edge from
			// u to v, and total weight of path from src to v through u is
			// smaller than current value of dist[v]
			if (!sptSet[v] && AdjMatrix[u][v] && dist[u] != INT_MAX
				&& dist[u] + AdjMatrix[u][v] < dist[v])
				dist[v] = dist[u] + AdjMatrix[u][v];
	}

	// print the constructed distance array
	printSolution(dist,V);
}

// driver program to test above function
int main()
{
	int  i=0, row = 0, column = 0;
	int col1[100];
	int col2[100];
	int col3[100];
	int atoi ( const char * str ); 
	char line[100];  /* declare a char array */

FILE *file;  /* declare a FILE pointer  */
file = fopen("12_2.csv", "r");  /* open a text file for reading */
	
  	while(fgets(line, sizeof line, file)!=NULL) {       /* keep looping until NULL pointer... */
		column = 0;
		row++;
		
		if (row == 1){
			continue;
		}
		
		char* temp = strtok(line, ",");
		
		while(temp != NULL){
			if(column == 0){
			col1[i] = atoi(temp);

			}
			if(column == 1){
				col2[i] = atoi(temp);
			}
			if(column == 2){
				col3[i] = atoi(temp);
			}
			
			temp = strtok(NULL, ",");
	        column++; 
		}
		i++;
    } 
	int nSize = i;
	int matrixSize = col1[0];
	int **AdjMatrix = createZeroMatrix(matrixSize);

	UndirectedMatix(AdjMatrix,nSize,matrixSize,col1,col2,col3);
	
	dijkstra_greedy(AdjMatrix, 0,matrixSize);

	return 0;
}

