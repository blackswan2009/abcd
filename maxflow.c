#include <stdio.h>
#include <string.h>
#include <limits.h>
#define MAX 100
int capacity[MAX][MAX], flow[MAX][MAX], residual[MAX][MAX], parent[MAX];
int n;
int bfs(int s, int t) {
    int visited[MAX] = {0}, queue[MAX], front = 0, rear = 0;
    queue[rear++] = s;
    visited[s] = 1;
    parent[s] = -1;
    while (front < rear) {
        int u = queue[front++];
        for (int v = 0; v < n; v++) {
            if (!visited[v] && residual[u][v] > 0) {
                parent[v] = u;
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }
    return visited[t];
}
int ford_fulkerson(int s, int t) {
    memset(flow, 0, sizeof(flow));
    memcpy(residual, capacity, sizeof(capacity));
    int max_flow = 0;
    while (bfs(s, t)) {
        int cf_p = INT_MAX;
        for (int v = t; v != s; v = parent[v])
            if (residual[parent[v]][v] < cf_p)
                cf_p = residual[parent[v]][v];
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            flow[u][v] += cf_p;
            flow[v][u] -= cf_p;
            residual[u][v] -= cf_p;
            residual[v][u] += cf_p;
        }

        max_flow += cf_p;
    }
    return max_flow;
}
int main() {
    int e, u, v, cap, s, t;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);
    memset(capacity, 0, sizeof(capacity));
    printf("Enter edges (u v capacity):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &u, &v, &cap);
        capacity[u][v] = cap;
    }
    printf("Enter source and sink: ");
    scanf("%d %d", &s, &t);
    printf("\nMax Flow: %d\n\n", ford_fulkerson(s, t));
    printf("Flow Network:\n");
    for (u = 0; u < n; u++)
        for (v = 0; v < n; v++)
            if (capacity[u][v])
                printf("f[%d][%d] = %d / %d\n", u, v, flow[u][v], capacity[u][v]);
    return 0;
}
