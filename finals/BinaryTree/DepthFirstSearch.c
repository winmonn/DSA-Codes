#include <stdio.h>
#include <stdlib.h>

#define ROWS 7 
#define COLUMNS 2
#define INF 0XFFFF

typedef int vertex;

void dfs(char visited[], vertex source){
    vertex w;
    visited[source] = 'V';
    for(w = 0; w < ROWS; w++){
        if(visited[w] == 'U'){
            dfs(visited, w);
        }
    }
}

int main(){
    int graph[ROWS][COLUMNS] = {{1, 2}, {2, 3}, {INF, 0}, {0, 2}, {5, 6}, {1, INF}, {5, 3}};

    char visited[ROWS];
    int x;
    for(x = 0; x < ROWS; x++){
        visited[x] = 'U';
    }
    vertex source_vertex = 0;
    dfs(visited, 0);

    return 0;
}