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
int main()
{
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
