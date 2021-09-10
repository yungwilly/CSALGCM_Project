#include <stdio.h>
#include <stdlib.h>
#define INFINITY 99999
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

  //step 1: fill the distance array and predecessor array
  for (i = 0; i < tV; i++) {
    d[i] = INFINITY;
    p[i] = 0;
  }

  //mark the source vertex
  d[source] = 0;

  //step 2: relax edges |V| - 1 times
  for (i = 1; i <= tV - 1; i++) {
    for (j = 0; j < tE; j++) {
      //get the edge data
      u = g->edge[j].u;
      v = g->edge[j].v;
      w = g->edge[j].w;

      if (d[u] != INFINITY && d[v] > d[u] + w) {
        d[v] = d[u] + w;
        p[v] = u;
      }
    }
  }

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

  //No negative weight cycle found!
  //print the distance and predecessor array
  printf("Distance array: ");
  display(d, tV);
  printf("Predecessor array: ");
  display(p, tV);
}
void sort2()
{
    
}
void sort1()
{

}
void innitgraph(int G[][50], FILE* F) {
    FILE* stream2 = fopen("12_2.csv", "r");
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
                
                vert = numb;
            }
            tmp = strtok(NULL, ",");

        }
        san = 0;
    
        // NOTE strtok clobbers tmp
        free(tmp);
        
    }
    int sans2 = 0, counter = 0, first = 0, sec = 0;
    while (fgets(line, sizeof(line), stream2))
    {
        counter++;
        
        char* tmp2 = strtok(line, ",");
        while(tmp2 != NULL) {
            
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
                }
                
            }
            tmp2 = strtok(NULL, ",");
        }
        // NOTE strtok clobbers tmp
        sans2 = 0;
        free(tmp2);
    }
    displaymatrix(G);
}
int main()
{
    printf("Hello world\n");
    printf("I am the bone of my sword");
    
    FILE* stream = fopen("12_2.csv", "r");
    int G[50][50], i, j;
    for (i = 0; i < 50; i++) {
        for (j = 0; j < 50; j++) {
            G[i][j] = NULL;
        }
    }
    innitgraph(G, stream);
   
    return 0;
}
