#include <limits.h>
#include <stdbool.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define VX 9
#define INFINITY 99999
#define INF 99999
struct Edge {
  int u;  //start vertex of the edge
  int v;  //end vertex of the edge
  int w;  //weight of the edge (u,v)
};
struct Graph {
  int V;        //total number of vertices in the graph
  int E;        //total number of edges in the graph
  struct Edge *edge;  //array of edges
};
struct Edge2 {
  int src;  //start vertex of the edge
  int dest;  //end vertex of the edge
  int weight;  //weight of the edge (u,v)
};

//Graph - it consists of edges
struct Graph2 {
  int V;        //total number of vertices in the graph
  int E;        //total number of edges in the graph
  struct Edge2 *edge2;  //array of edges
};
void display(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
void bellmanford(struct Graph *g, int source) {
  //variables
  int i, j, u, v, w;

  //total vertex in the graph g
  int tV = g->V;

  //total edge in the graph g
  int tE = g->E;

  //distance array
  //size equal to the number of vertices of the graph g
  int d[tV];

  //predecessor array
  //size equal to the number of vertices of the graph g
  int p[tV];
  
  printf("Gan %d %d \n", tV, tE);
  //step 1: fill the distance array and predecessor array
  for (i = 0; i < tV; i++) {
    d[i] = INFINITY;
    p[i] = 0;
  }
  printf("Junifer\n");

  //mark the source vertex
  d[source] = 0;

  //step 2: relax edges |V| - 1 times
  for (i = 1; i <= tV - 1; i++) {
    for (j = 0; j < tE; j++) {
      //get the edge data
      u = g->edge[j].u;
      v = g->edge[j].v;
      w = g->edge[j].w;
      //printf("Checkers %d %d %d \n", u, v, w);
      if (d[u] != INFINITY && d[v] > d[u] + w) {
        d[v] = d[u] + w;
        p[v] = u;
      }
    }
    printf("Iteration %d Distance array: ", i);
    display(d, tV);
    printf("Iteration %d Predecessor array: ", i);
    display(p, tV);
  }
  printf("Jack\n");

  //step 3: detect negative cycle
  //if value changes then we have a negative cycle in the graph
  //and we cannot find the shortest distances
  for (i = 0; i < tE; i++) {
    u = g->edge[i].u;
    v = g->edge[i].v;
    w = g->edge[i].w;
    if (d[u] != INFINITY && d[v] > d[u] + w) {
      printf("Negative weight cycle detected!\n");
      return;
    }
  }
  printf("Guy in woods\n");

  //No negative weight cycle found!
  //print the distance and predecessor array
  printf("Final Distance array: ");
  display(d, tV);
  printf("Final Predecessor array: ");
  display(p, tV);
}
void sort2()
{
    
}
void sort1()
{

}
void bellfordinitial(int G[][50] , int vert, int edges) {
  printf("Hello zap\n");
  int i, j, edg2 = 0;
  
  struct Graph *g = (struct Graph *)malloc(sizeof(struct Graph));
  printf("Struct\n");
  g->V = vert;
  g->E = edges;
   g->edge = (struct Edge *)malloc(g->E * sizeof(struct Edge));
   printf("Bellford\n");
  for (i = 0; i < edges; i++) {
    for (j = 0; j < edges; j++) {
       int nas = G[i][j];
       if (nas == NULL) {
       

       }
       else {
         printf("AMAZING WORLD\n");
          g->edge[edg2].u = i;
          g->edge[edg2].v = j;
          g->edge[edg2].w = nas;
          edg2++;
       }

    }
    
  }
  printf("Hello ford\n");
  bellmanford(g, 0);
}
void displaymatrix(int G[][50]) {
    //displaying of matrix
    int i, j, max = 0, conf = 0;
    for (i = 0; i < 50; i++) {
        for (j = 0; j < 50; j++) {
            int num = G[i][j];
            if (num == NULL) {

            }
            else {
                if (max < j) {
                printf("%d i % d j % d\n", G[i][j], i, j);
                printf("J %d max %d\n", j, max);
                max = j;
                conf = 1;
                }
                if (max < i) {
                printf("I %d max %d\n", i, max);
                
                max = i;
                conf = 0;
            }
            }
            
        } 
        
        
    }
    max = max + 1;
    printf("asd %d\n", max);
    for (i = 0; i < max; i++) {
        for (j = 0; j < max; j++) {
            int nas = G[i][j];
            if (nas == NULL) {
                printf(". ");
            }
            else {
                printf("%d ", nas);
            }
            
        }
        printf("\n");
    }
}

void innitgraph(int G[][50], FILE* F) {
    //file reading
    FILE* stream2 = fopen("14_2.csv", "r");
    if (F== NULL) {
        printf("Unable");
        exit(1);
    }
    char line[1024];
   
    int counters = 0, san = 0, vert = 0;
    while (fgets(line, sizeof(line), F))
    {
        counters++;
        
        char* tmp = strtok(line, ",");
        while(tmp != NULL) {
            san++;
          
            int numb = atoi(tmp);
           
            if (san == 1 && counters == 2) {
                //getting the number of vertices
                vert = numb;
            }
            tmp = strtok(NULL, ",");

        }
        san = 0;
    
        // NOTE strtok clobbers tmp
        free(tmp);
        
    }
    int sans2 = 0, counter = 0, first = 0, sec = 0, edges = 0;
    while (fgets(line, sizeof(line), stream2))
    {
        counter++;
        
        char* tmp2 = strtok(line, ",");
        while(tmp2 != NULL) {
            //adding of weights according to their vertices
            sans2++;
            if (counter > 2) {
                if (sans2 == 1) {
                    first = atoi(tmp2);
                   
                }
                else if (sans2 == 2) {
                    sec = atoi(tmp2);
                }
                else {
                    int num = atoi(tmp2);
                    G[first][sec] = num;
                    edges++;
                }
                
            }
            tmp2 = strtok(NULL, ",");
        }
        // NOTE strtok clobbers tmp
        sans2 = 0;
        free(tmp2);
    }
    printf("Hello bellford\n");
    //displaymatrix(G);
    bellfordinitial(G, vert, edges);
}
//dynamic dijkstra
void displaydij_dynamic(int arr[], int size) {
  int i;
  printf("Vertex   Distance from Source\n");
    for (i = 0; i < size; ++i)
        printf("%d \t\t %d\n", i, arr[i]);
}
//dijkstra dynamic functions
void dijkstra_dynamic(struct Graph2 *graph, int src) {

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
      u = graph->edge2[j].src;
      v = graph->edge2[j].dest;
      w = graph->edge2[j].weight;

      if (dest[u] != INF && dest[v] > dest[u] + w) {
        dest[v] = dest[u] + w;
      }
    }
  }

  displaydij_dynamic(dest, totalV);

}
void dij_dynamic() {
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
  struct Graph2 *graph = (struct Graph2 *)malloc(sizeof(struct Graph2));
  graph->V = col1[0];  //total vertices
  graph->E = totalNums-1;  //total edges

  //array of edges for graph
  graph->edge2 = (struct Edge2 *)malloc(graph->E * sizeof(struct Edge2));
	
	int k;
	for(k = 0; k < graph->E; k++){
		graph->edge2[k].src = col1[k+1];
		graph->edge2[k].dest = col2[k+1];
		graph->edge2[k].weight = col3[k+1];
	}

  dijkstra_dynamic(graph, 0);  //0 is the source vertex

}
//dijkstra greedy
// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
	// Initialize min value
	int min = INT_MAX, min_index;
	int v;
	for (v = 0; v < VX; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

// A utility function to print the constructed distance array
void printSolution(int dist[])
{
	printf("Vertex \t\t Distance from Source\n");
	int i;
	for (i = 0; i < VX; i++)
		printf("%d \t\t %d\n", i, dist[i]);
}

void initGraph(int AdjMatrix[][VX],int nSize){
 int i, j;
  for (i = 0; i < nSize; i++)
    for (j = 0; j < nSize; j++)
      AdjMatrix[i][j] = 0;	
}

void UndirectedMatix(int AdjMatrix[][VX], int nSize, int matrixSize, int col1[], int col2[], int col3[]) {
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
void dijkstra_greedy(int graph[VX][VX], int src)
{
	int dist[VX]; // The output array. dist[i] will hold the shortest
	// distance from src to i

	bool sptSet[VX]; // sptSet[i] will be true if vertex i is included in shortest
	// path tree or shortest distance from src to i is finalized

	// Initialize all distances as INFINITE and stpSet[] as false
	int i;
	for (i = 0; i < VX; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	int count;
	for (count = 0; count < VX - 1; count++) {
		// Pick the minimum distance vertex from the set of vertices not
		// yet processed. u is always equal to src in the first iteration.
		int u = minDistance(dist, sptSet);

		// Mark the picked vertex as processed
		sptSet[u] = true;

		// Update dist value of the adjacent vertices of the picked vertex.
		int v;
		for (v = 0; v < VX; v++)

			// Update dist[v] only if is not in sptSet, there is an edge from
			// u to v, and total weight of path from src to v through u is
			// smaller than current value of dist[v]
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	// print the constructed distance array
	printSolution(dist);
}
void dij_greed() {
  int  i=0, row = 0, column = 0;
	int col1[100];
	int col2[100];
	int col3[100];
	int atoi ( const char * str ); 
	char line[100];  /* declare a char array */

FILE *file;  /* declare a FILE pointer  */
file = fopen("14_2.csv", "r");  /* open a text file for reading */
	
  	while(fgets(line, sizeof line, file)!=NULL) {       /* keep looping until NULL pointer... */
		 printf("Lines of numbers.txt file are: %s", line);
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
	int AdjMatrix[matrixSize][matrixSize];  
	printf("\n\n");
	
	initGraph(AdjMatrix,matrixSize);
	UndirectedMatix(AdjMatrix,nSize,matrixSize,col1,col2,col3);
	
	dijkstra_greedy(AdjMatrix, 0);
}
int main()
{
  printf("Greedy Dijkstra\n");
  dij_greed();
  printf("Dynamic Dijkstra\n");
  dij_dynamic();
  printf("Bellford\n");
    printf("Hello world\n");
    printf("I am the bone of my sword");
    
    FILE* stream = fopen("14_2.csv", "r");
    int G[50][50], i, j;
    for (i = 0; i < 50; i++) {
        for (j = 0; j < 50; j++) {
            G[i][j] = NULL;
        }
    }
    innitgraph(G, stream);
   
    return 0;
}
