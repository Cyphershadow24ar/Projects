#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define V 10
#define INF 9999

void saveToDotFile(int parent[], int dist[], int graph[V][V], char *vertex[], int src, int dest) {
    FILE *f = fopen("graph.dot", "w");
    if (f == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(f, "graph G {\n");

    // Add nodes with labels
    for (int i = 0; i < V; i++) {
        fprintf(f, "    \"%s\" [label=\"%s\"];\n", vertex[i], vertex[i]);
    }

    // Add edges with weights labeled as "km"
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (graph[i][j] != 0 && graph[i][j] != INF) {
                fprintf(f, "    \"%s\" -- \"%s\" [label=\"%d km\"];\n", vertex[i], vertex[j], graph[i][j]);
            }
        }
    }

    // Highlight the shortest path in red with thicker lines
    int v = dest;
    while (parent[v] != -1) {
        fprintf(f, "    \"%s\" -- \"%s\" [color=red, penwidth=2.0, label=\"%d km\"];\n",
                vertex[parent[v]], vertex[v], graph[parent[v]][v]);
        v = parent[v];
    }

    fprintf(f, "}\n");
    fclose(f);

    printf("Graph saved to 'graph.dot'.\n");
}

void printPath(int parent[], int v, char *vertex[]) {
    if (parent[v] == -1) {
        printf("%s", vertex[v]);
        return;
    }
    printPath(parent, parent[v], vertex);
    printf(" -> %s", vertex[v]);
}

void printSolution(int dist[], int parent[], char *vertex[], int visitedSequence[], int src, int dest) {
    printf("\nSource: %s\nDestination: %s\n", vertex[src], vertex[dest]);
    printf("Shortest Distance: %d\n", dist[dest]);
    printf("Path: ");
    printPath(parent, dest, vertex);
    printf("\nVisit Sequence: %d\n", visitedSequence[dest]);
}

int getIndex(char *vertex[], char *name) {
    for (int i = 0; i < V; i++) {
        if (strcmp(vertex[i], name) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    char *vertex[V] = {
        "Fire Station", "Market Building Area", "Rasulgarh", 
        "Chandaka Industrial Area", "Saheed Nagar", 
        "Khandagiri", "Nayapalli", "Patia", 
        "Chandrasekharpur", "Old Town"
    };

    int graph[V][V] = {
        {0, 6, INF, 12, 7, 9, INF, 15, INF, INF},     // Fire Station
        {6, 0, 5, INF, 2, INF, INF, INF, INF, 8},     // Market Building Area
        {INF, 5, 0, 8, INF, 3, INF, 10, INF, INF},    // Rasulgarh
        {12, INF, 8, 0, INF, 6, 4, INF, INF, INF},    // Chandaka Industrial Area
        {7, 2, INF, INF, 0, INF, 3, INF, 5, INF},     // Saheed Nagar
        {9, INF, 3, 6, INF, 0, 2, INF, INF, INF},     // Khandagiri
        {INF, INF, INF, 4, 3, 2, 0, 7, INF, INF},     // Nayapalli
        {15, INF, 10, INF, INF, INF, 7, 0, 2, INF},   // Patia
        {INF, INF, INF, INF, 5, INF, INF, 2, 0, 6},   // Chandrasekharpur
        {INF, 8, INF, INF, INF, INF, INF, INF, 6, 0}  // Old Town
    };

    int dist[V], visited[V], visitedSequence[V], parent[V];
    int src = 0, seq = 1;
    char destName[50];

    printf("Enter the destination vertex name (e.g., 'Market Building Area', 'Rasulgarh', etc.): ");
    scanf(" %[^\n]%*c", destName);

    int dest = getIndex(vertex, destName);
    if (dest == -1) {
        printf("Invalid vertex name entered!\n");
        return 1;
    }

    for (int i = 0; i < V; i++) {
        dist[i] = INF; visited[i] = 0; visitedSequence[i] = -1; parent[i] = -1;
    }
    dist[src] = 0;

    for (int k = 0; k < V - 1; k++) {
        int min = INF, u = -1;
        for (int i = 0; i < V; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1) break;
        visited[u] = 1;
        visitedSequence[u] = seq++;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printSolution(dist, parent, vertex, visitedSequence, src, dest);
    saveToDotFile(parent, dist, graph, vertex, src, dest);

    return 0;
}
