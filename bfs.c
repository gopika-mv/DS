#include <stdio.h>

#define MAX 20

void bfs(int graph[MAX][MAX], int visited[MAX], int n, int start) {
    int queue[MAX], front = 0, rear = 0;
    int i;

    // Mark the starting node as visited and enqueue it
    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal: ");

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        // Check all adjacent vertices
        for (i = 0; i < n; i++) {
            if (graph[current][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int graph[MAX][MAX];
    int visited[MAX] = {0};
    int n, i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix of the graph:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    bfs(graph, visited, n, start);

    return 0;
}
