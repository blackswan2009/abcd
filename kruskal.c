#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Edge structure
typedef struct {
    int u, v, weight;
} Edge;

Edge edges[MAX];
int parent[MAX], rank[MAX];
int V, E;

// Function prototypes
void make_set();
int find_set(int v);
void union_sets(int a, int b);
int compare(const void *a, const void *b);

int main() {
    int i;

    // Input graph
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter edges (u v weight):\n");
    for (i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    // Kruskal’s Algorithm
    make_set();
    qsort(edges, E, sizeof(Edge), compare);

    printf("Edges in MST:\n");
    int mst_edges = 0;
    for (i = 0; i < E && mst_edges < V - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        if (find_set(u) != find_set(v)) {
            printf("(%d, %d) weight: %d\n", u, v, edges[i].weight);
            union_sets(u, v);
            mst_edges++;
        }
    }

    if (mst_edges != V - 1) {
        printf("Graph is not connected. MST not possible.\n");
    }

    return 0;
}

// MAKE_SET for each vertex
void make_set() {
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

// FIND_SET with path compression
int find_set(int v) {
    if (v != parent[v])
        parent[v] = find_set(parent[v]);
    return parent[v];
}

// UNION by rank
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank[a] < rank[b])
            parent[a] = b;
        else {
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }
}

// Comparison function for qsort
int compare(const void *a, const void *b) {
    Edge *e1 = (Edge *)a;
    Edge *e2 = (Edge *)b;
    return e1->weight - e2->weight;
}
