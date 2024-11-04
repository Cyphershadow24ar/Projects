 // This File contains the explaination of the code in a comment format with the code. 

#include <stdio.h>   // Includes standard input/output functions like printf and scanf.
#include <stdlib.h>  // Includes standard utility functions like malloc, free, and exit.
#include <string.h>  // Includes functions for string manipulation (e.g., strcmp, strcpy).

#define V 11         // Defines a macro 'V' which represents the number of vertices (locations) in the graph.
#define INF 9999     // Defines a macro 'INF' to represent infinity, used for unreachable paths.

void saveToDotFile(int parent[], int dist[], int graph[V][V], char *vertex[], int src, int dest) {
    FILE *f = fopen("graph.dot", "w");   // Opens a file named "graph.dot" for writing.
    if (f == NULL) {                     // Checks if the file failed to open.
        printf("Error opening file!\n"); // Prints an error message if the file cannot be opened.
        return;                          // Exits the function if there's an error opening the file.
    }
    fprintf(f, "graph G {\n");           // Writes the start of a DOT graph definition.
    
    // Add nodes with labels
    for (int i = 0; i < V; i++) {
        fprintf(f, "    \"%s\" [label=\"%s\"];\n", vertex[i], vertex[i]);   // Writes each vertex with its label.
    }
    
    // Add edges with weights labeled as "km"
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (graph[i][j] != 0 && graph[i][j] != INF) {   // Checks if there is a valid edge between vertices.
                fprintf(f, "    \"%s\" -- \"%s\" [label=\"%d km\"];\n", vertex[i], vertex[j], graph[i][j]); // Writes edges between vertices with weights.
            }
        }
    }
    
    // Highlight the shortest path in red with thicker lines
    int v = dest;
    while (parent[v] != -1) {   // Follows the parent array to trace the shortest path.
        fprintf(f, "    \"%s\" -- \"%s\" [color=red, penwidth=2.0, label=\"%d km\"];\n",
                vertex[parent[v]], vertex[v], graph[parent[v]][v]);   // Highlights the path in red with thicker lines.
        v = parent[v];   // Moves to the parent node to continue tracing the path.
    }
    fprintf(f, "}\n");   // Ends the DOT graph definition.
    fclose(f);           // Closes the file.
    printf("Graph saved to 'graph.dot'.\n");   // Confirms that the graph has been saved.
}


void printPath(int parent[], int v, char *vertex[]) {
    if (parent[v] == -1) {              // Base case: If there's no parent (we've reached the source).
        printf("%s", vertex[v]);        // Print the source vertex.
        return;                         // Stop recursion.
    }
    printPath(parent, parent[v], vertex); // Recursively call the function to print the parent vertex.
    printf(" -> %s", vertex[v]);         // Print the current vertex after the parent (path format).
}


void printSolution(int dist[], int parent[], char *vertex[], int visitedSequence[], int src, int dest) {
    printf("\nSource: %s\nDestination: %s\n", vertex[src], vertex[dest]);  // Print source and destination names.
    printf("Shortest Distance: %d\n", dist[dest]);   // Print the shortest distance to the destination.
    printf("Path: ");
    printPath(parent, dest, vertex);                 // Print the path from source to destination using printPath().
    printf("\nVisit Sequence: %d\n", visitedSequence[dest]);  // Print the visit sequence for the destination.
}


int getIndex(char *vertex[], char *name) {
    for (int i = 0; i < V; i++) {                  // Loop through the vertices.
        if (strcmp(vertex[i], name) == 0) {        // If the vertex name matches the given name.
            return i;                              // Return the index of the vertex.
        }
    }
    return -1;  // If no match is found, return -1 to indicate an invalid vertex name.
}


int main() {
    // Array of vertex names (locations).
    char *vertex[V] = {
        "CVRGU", "Hello Pet Cares", "Pet Animal Hospital", 
        "Govt. Veterinary Hospital", "Tarzoo Pet Care", 
        "Petvetcure Clinic", "Vet Surgery Dept. OUAT", 
        "Veterinary Dispensary", "Pets Paradise Clinic", 
        "Pet Clinic Ruchika", "Reproduction Dept. OUAT"
    };

    // Graph represented as an adjacency matrix (distances between locations).
    int graph[V][V] = {
        {0, 10, 10, 15, 12, 10, 16, 18, 10, 8, 14},   
        {10, 0, 1, 6, 8, INF, INF, INF, INF, INF, INF},
        {10, 1, 0, 6, INF, 5, INF, INF, INF, INF, INF},
        {15, 6, 6, 0, 4, INF, INF, INF, INF, INF, INF},
        {12, 8, INF, 4, 0, 3, INF, INF, 5, INF, INF},
        {10, INF, 5, INF, 3, 0, 2, INF, INF, INF, INF},
        {16, INF, INF, INF, INF, 2, 0, 4, INF, INF, INF},
        {18, INF, 10, INF, INF, INF, 4, 0, INF, INF, 3},
        {10, INF, INF, INF, 5, INF, INF, INF, 0, 3, INF},
        {8, INF, INF, INF, INF, 9, INF, INF, 3, 0, INF},
        {14, INF, INF, 7, INF, INF, INF, 3, INF, INF, 0}
    };

    // Variables for Dijkstra's algorithm
    int dist[V], visited[V], visitedSequence[V], parent[V];
    int src = 0, seq = 1;
    char destName[50];

    // Get user input for the destination
    printf("Enter the destination vertex name (e.g., 'Hello Pet Cares', 'Govt. Veterinary Hospital', etc.): ");
    scanf(" %[^\n]%*c", destName);                  // Read the destination vertex name.
    int dest = getIndex(vertex, destName);           // Get the index of the destination vertex.

    if (dest == -1) {                                // If the destination is invalid.
        printf("Invalid vertex name entered!\n");
        return 1;
    }

    // Initialize distances, visited array, and parent array.
    for (int i = 0; i < V; i++) {
        dist[i] = INF; visited[i] = 0; visitedSequence[i] = -1; parent[i] = -1;
    }
    dist[src] = 0;   // Set the source distance to 0.

    // Dijkstra's algorithm: find shortest paths.
    for (int k = 0; k < V - 1; k++) {
        int min = INF, u = -1;
        for (int i = 0; i < V; i++) {
            if (!visited[i] && dist[i] < min) {    // Find the vertex with the smallest distance.
                min = dist[i];
                u = i;
            }
        }
        if (u == -1) break;  // If no vertex is reachable, break the loop.

        visited[u] = 1;             // Mark the selected vertex as visited.
        visitedSequence[u] = seq++; // Store the visit sequence for the selected vertex.

        // Update distances for the adjacent vertices.
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];  // Update distance if a shorter path is found.
                parent[v] = u;                    // Update parent to track the path.
            }
        }
    }

    // Print the solution (shortest path and distance)
