#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
struct Graph
{
    int vertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
};

void initGraph(struct Graph *graph, int vertices)
{
    graph->vertices = vertices;

    // Initialize the adjacency matrix with zeros
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
}

// Function to add an edge to the graph
void addEdge(struct Graph *graph, int start, int end)
{
    graph->adjacencyMatrix[start][end] = 1;
    graph->adjacencyMatrix[end][start] = 1; 
}

void DFS(struct Graph *graph, int visited[MAX_VERTICES], int currentVertex)
{
    printf("%d ", currentVertex);
    visited[currentVertex] = 1;

    for (int i = 0; i < graph->vertices; i++)
    {
        if (graph->adjacencyMatrix[currentVertex][i] == 1 && !visited[i])
        {
            DFS(graph, visited, i);
        }
    }
}
