#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define V 11
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
        "CVRGU", "Hello Pet Cares", "Pet Animal Hospital", 
        "Govt. Veterinary Hospital", "Tarzoo Pet Care", 
        "Petvetcure Clinic", "Vet Surgery Dept. OUAT", 
        "Veterinary Dispensary", "Pets Paradise Clinic", 
        "Pet Clinic Ruchika", "Reproduction Dept. OUAT"
    };

    int graph[V][V] = {
        {0, 10, 10, 15, 12, 10, 16, 18, 10, 8, 14},   // CVRGU
        {10, 0, 1, 6, 8, INF, INF, INF, INF, INF, INF}, // Hello Pet Cares
        {10, 1, 0, 6, INF, 5, INF, INF, INF, INF, INF}, // Pet Animal Hospital
        {15, 6, 6, 0, 4, INF, INF, INF, INF, INF, INF}, // Govt. Vet Hospital
        {12, 8, INF, 4, 0, 3, INF, INF, 5, INF, INF},   // Tarzoo Pet Care
        {10, INF, 5, INF, 3, 0, 2, INF, INF, INF, INF}, // Petvetcure Clinic
        {16, INF, INF, INF, INF, 2, 0, 4, INF, INF, INF}, // Vet Surgery Dept. OUAT
        {18, INF, 10, INF, INF, INF, 4, 0, INF, INF, 3}, // Veterinary Dispensary
        {10, INF, INF, INF, 5, INF, INF, INF, 0, 3, INF}, // Pets Paradise Clinic
        {8, INF, INF, INF, INF, 9, INF, INF, 3, 0, INF}, // Pet Clinic Ruchika
        {14, INF, INF, 7, INF, INF, INF, 3, INF, INF, 0}  // Reproduction Dept. OUAT
    };

    int dist[V], visited[V], visitedSequence[V], parent[V];
    int src = 0, seq = 1;
    char destName[50];

    printf("Enter the destination vertex name (e.g., 'Hello Pet Cares', 'Govt. Veterinary Hospital', etc.): ");
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

        if (u == -1) break;  // No reachable vertices
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