#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INF 99999

//struct for the edges of the graph
struct Edge {
  int src;  //start vertex of the edge
  int dest;  //end vertex of the edge
  int weight;  //weight of the edge (u,v)
};

//Graph - it consists of edges
struct Graph {
  int V;        //total number of vertices in the graph
  int E;        //total number of edges in the graph
  struct Edge *edge;  //array of edges
};

void display(int arr[], int size) {
  int i;
  printf("Vertex   Distance from Source\n");
    for (i = 0; i < size; ++i)
        printf("%d \t\t %d\n", i, arr[i]);
}

void dijkstra_dynamic(struct Graph *graph, int src) {

  int i, j, u, v, w;
  int totalV = graph->V;
  int totalE = graph->E;
  int dest[totalV];

  for (i = 0; i < totalV; i++) {
    dest[i] = INF;
  }
  dest[src] = 0;


  for (i = 1; i <= totalV - 1; i++) {
    for (j = 0; j < totalE; j++) {
      //get the edge data
      u = graph->edge[j].src;
      v = graph->edge[j].dest;
      w = graph->edge[j].weight;

      if (dest[u] != INF && dest[v] > dest[u] + w) {
        dest[v] = dest[u] + w;
      }
    }
  }

  display(dest, totalV);

}



int main(void) {
	int  i=0,totalNums, row = 0, column = 0;
	int col1[100];
	int col2[100];
	int col3[100];
	int atoi ( const char * str ); 
	char line[100];  /* declare a char array */

FILE *file;  /* declare a FILE pointer  */
file = fopen("14_2.csv", "r");  /* open a text file for reading */
	
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
    totalNums = i;  
    
  //create graph
  struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
  graph->V = col1[0];  //total vertices
  graph->E = totalNums-1;  //total edges

  //array of edges for graph
  graph->edge = (struct Edge *)malloc(graph->E * sizeof(struct Edge));
	
	int k;
	for(k = 0; k < graph->E; k++){
		graph->edge[k].src = col1[k+1];
		graph->edge[k].dest = col2[k+1];
		graph->edge[k].weight = col3[k+1];
	}

  dijkstra_dynamic(graph, 0);  //0 is the source vertex

  return 0;
}
