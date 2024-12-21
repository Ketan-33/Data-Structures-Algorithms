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

void BFS(struct Graph *graph, int startVertex)
{
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = -1, rear = -1;

    printf("BFS Traversal starting from vertex %d: ", startVertex);

    // Enqueue the start vertex
    queue[++rear] = startVertex;
    visited[startVertex] = 1;

    while (front != rear)
    {
        // Dequeue a vertex and print it
        int currentVertex = queue[++front];
        printf("%d ", currentVertex);

        // Enqueue adjacent vertices
        for (int i = 0; i < graph->vertices; i++)
        {
            if (graph->adjacencyMatrix[currentVertex][i] == 1 && !visited[i])
            {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }

    printf("\n");
}

int main()
{
    struct Graph graph;
    int vertices;

    // Input the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    // Initialize the graph
    initGraph(&graph, vertices);

    // Input the adjacency matrix
    printf("Enter the adjacency matrix (1 for connected, 0 for not connected):\n");
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            printf("Is vertex %d connected to vertex %d? (1/0): ", i, j);
            scanf("%d", &graph.adjacencyMatrix[i][j]);
        }
    }

    // Input the starting vertex for BFS and DFS
    int startVertex;
    printf("Enter the starting vertex for BFS and DFS: ");
    scanf("%d", &startVertex);

    // Perform DFS traversal starting from the specified vertex
    printf("DFS Traversal starting from vertex %d: ", startVertex);
    int visitedDFS[MAX_VERTICES] = {0};
    DFS(&graph, visitedDFS, startVertex);
    printf("\n");

    // Perform BFS traversal starting from the specified vertex
    BFS(&graph, startVertex);

    return 0;
}