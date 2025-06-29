#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
}

int isEmpty(Queue* q) {
    return q->rear < q->front;
}

void enqueue(Queue* q, int value) {
    if (q->rear < MAX - 1)
        q->items[++q->rear] = value;
}

int dequeue(Queue* q) {
    if (!isEmpty(q))
        return q->items[q->front++];
    return -1;
}

int graph[MAX][MAX];  // Adjacency matrix
int color[MAX], distance[MAX], parent[MAX];

int main() {
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    // Initialize graph
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // For undirected graph
    }

    int s;
    printf("Enter source vertex: ");
    scanf("%d", &s);

    // Initialize all vertices
    for (int i = 0; i < V; i++) {
        if (i != s) {
            color[i] = WHITE;
            distance[i] = -1; // ∞ represented by -1
            parent[i] = -1;   // NIL
        }
    }

    // BFS Initialization
    color[s] = GRAY;
    distance[s] = 0;
    parent[s] = -1;

    Queue q;
    initQueue(&q);
    enqueue(&q, s);

    // BFS loop
    while (!isEmpty(&q)) {
        int u = dequeue(&q);
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && color[v] == WHITE) {
                color[v] = GRAY;
                distance[v] = distance[u] + 1;
                parent[v] = u;
                enqueue(&q, v);
            }
        }
        color[u] = BLACK;
    }

    // Output result
    printf("\nVertex\tDistance\tParent\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\t\t", i, distance[i]);
        if (parent[i] == -1)
            printf("NIL\n");
        else
            printf("%d\n", parent[i]);
    }

    return 0;
}
