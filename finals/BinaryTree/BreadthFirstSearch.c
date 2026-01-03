#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 8
#define MAX_EDGES 3
#define INF 0xFFFF

typedef int vertex;

typedef struct {
    int arr[MAX_VERTICES];
    int front;
    int rear;
}Queue;

void initQueue(Queue* Q){
    Q->front = 0;
    Q->rear = 0;
}

void enqueue(Queue* Q, int data){
    if(Q->front != (Q->rear + 1) % MAX_VERTICES){
        Q->arr[Q->rear] = data;
        Q->rear = (Q->rear + 1) % MAX_VERTICES;
    }
}

void dequeue(Queue* Q){
    if(Q->front != Q->rear){
        Q->front = (Q->front + 1) % MAX_VERTICES;
    }
}

void breadth_first_search(vertex G[][MAX_EDGES], char visited[], vertex source){
    visited[source] = 'T';
    Queue bfs;
    initQueue(&bfs);
    enqueue(&bfs, source);
    if(G[source][0] < G[source][1]){
        enqueue(&bfs, G[source][0]);
        visited[G[source][0]] = 'T';
    } else {
        enqueue(&bfs, G[source][1]);
        visited[G[source][1]] = 'T';
    }
    int x, min = -1;
    for(x = 0; x < MAX_EDGES; x++){
        if(visited[x] != 'T' && G[source][x] < min){
            min = G[source][x];
        }
    }
    if(min > 0){
        enqueue(&bfs, min);
    }
    
}

int main(){
    vertex graph[MAX_VERTICES][MAX_EDGES] = {{2, 3, INF}, {INF, 3, INF}, {0, 5, 4}, {INF, INF, 7}, {7, INF, INF}, {1, 7, 6}, {2, 5}, {6, INF, INF}};

    char visited[MAX_VERTICES];
    for(int x = 0 ; x < MAX_VERTICES; x++){
        visited[x] = 'f';
    }

    vertex source_vortex = 6;
    breadth_first_search(graph, visited, source_vortex);
}