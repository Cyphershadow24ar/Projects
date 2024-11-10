#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define V 13  // Define the number of vertices (clinics) in the graph
#define INF 99999  // Define a large number as infinity for unreachable nodes

// Function to save the shortest path to a .dot file for visualization with Graphviz
void saveToDotFile(int parent[], int dist[], int graph[V][V], char *vertex[], int src, int dest) {
    FILE *f = fopen("graph.dot", "w");  // Open file in write mode
    if (f == NULL) {  // Check if file opened successfully
        printf("Error opening file!\n");
        return;
    }
    fprintf(f, "graph G {\n");  // Start the Graphviz .dot file

    // Write each vertex to the file with its label
    for (int i = 0; i < V; i++) {
        fprintf(f, "    \"%s\" [label=\"%s\"];\n", vertex[i], vertex[i]);
    }

    // Write edges with weights (distances) labeled in km
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (graph[i][j] != 0 && graph[i][j] != INF) {
                fprintf(f, "    \"%s\" -- \"%s\" [label=\"%d km\"];\n", vertex[i], vertex[j], graph[i][j]);
            }
        }
    }

    // Highlight the shortest path in red with thicker lines
    int v = dest;
    while (parent[v] != -1) {  // Traverse back using the parent array to trace the shortest path
        fprintf(f, "    \"%s\" -- \"%s\" [color=red, penwidth=2.0, label=\"%d km\"];\n",
                vertex[parent[v]], vertex[v], graph[parent[v]][v]);
        v = parent[v];  // Move to the parent node
    }
    fprintf(f, "}\n");  // End the .dot file
    fclose(f);  // Close the file
    printf("Graph saved to 'graph.dot'.\n");  // Notify user of successful save
}

// Function to print the shortest path from source to vertex `v`
void printPath(int parent[], int v, char *vertex[]) {
    if (parent[v] == -1) {  // If reached the source, print it
        printf("%s", vertex[v]);
        return;
    }
    printPath(parent, parent[v], vertex);  // Recursively print parent nodes
    printf(" -> %s", vertex[v]);  // Print the current node
}

// Function to display the results of Dijkstra's algorithm
void printSolution(int dist[], int parent[], char *vertex[], int visitedSequence[], int src, int dest) {
    printf("\nSource: %s\nDestination: %s\n", vertex[src], vertex[dest]);
    printf("Shortest Distance: %d\n", dist[dest]);
    printf("Path: ");
    printPath(parent, dest, vertex);  // Print the path from source to destination
    printf("\nVisit Sequence: %d\n", visitedSequence[dest]);  // Print visit sequence
}

// Function to find the index of a vertex by name
int getIndex(char *vertex[], char *name) {
    for (int i = 0; i < V; i++) {  // Loop through vertex array
        if (strcmp(vertex[i], name) == 0) {  // If name matches, return index
            return i;
        }
    }
    return -1;  // Return -1 if name not found
}

int main() {
    // Define vertex names for the clinics
    char *vertex[V] = {
        "CVRGU", "Hello Pet Cares", "Anisha Pet Care Clinic", "Petvetcure", 
        "Govt. Veterinary Hospital", "Vet Surgery Dept. OUAT", "Bhubaneswar Pet Clinic", 
        "Aashrey Pet Clinic", "Royal Pet Clinic", "VetCare Pet Clinic", 
        "Blue Cross Vet Clinic", "Petland Veterinary Clinic", "Dr. Panda’s Pet Clinic"
    };

    // Adjacency matrix representing distances between clinics
    int graph[V][V] = {
        {0, 12, 15, 12, 14, 15, 16, 14, 15, 14, 20, 13, 15},  // CVRGU
        {12, 0, 5, INF, INF, INF, INF, INF, INF, INF, INF, 10, INF},  // Hello Pet Cares
        {15, 5, 0, INF, INF, INF, INF, INF, INF, 3, 5, INF, INF},  // Anisha Pet Care Clinic
        {12, INF, INF, 0, 6, INF, INF, INF, INF, INF, INF, INF, INF},  // Petvetcure
        {14, INF, INF, 6, 0, 5, INF, 8, INF, INF, INF, INF, INF},  // Govt. Veterinary Hospital
        {15, INF, INF, INF, 5, 0, INF, INF, INF, 7, INF, INF, INF},  // Vet Surgery Dept. OUAT
        {16, INF, INF, INF, INF, INF, 0, 2, INF, INF, INF, INF, INF},  // Bhubaneswar Pet Clinic
        {14, INF, INF, INF, 2, INF, INF, 0, 3, INF, INF, INF, INF},  // Aashrey Pet Clinic
        {15, INF, 3, INF, INF, INF, INF, 3, 0, 5, INF, INF, INF},  // Royal Pet Clinic
        {14, INF, 5, INF, INF, INF, INF, INF, 5, 0, 6, INF, INF},  // VetCare Pet Clinic
        {20, INF, INF, 4, INF, INF, INF, INF, INF, INF, INF, 6, INF},  // Blue Cross Vet Clinic
        {15, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 2},  // Petland Veterinary Clinic
        {14, INF, INF, INF, 2, INF, INF, 3, INF, INF, INF, INF, 0}   // Dr. Panda’s Pet Clinic
    };

    int dist[V], visited[V], visitedSequence[V], parent[V];  // Declare arrays for distances, visit status, sequence, and parent nodes
    int src = 0, seq = 1;  // Initialize source index and sequence counter
    char destName[50];  // String to hold destination clinic name

    // Get destination clinic name from the user
    printf("Enter the destination vertex name (e.g., 'Hello Pet Cares', 'Govt. Veterinary Hospital', etc.): ");
    scanf(" %[^\n]%*c", destName);  // Read user input
    int dest = getIndex(vertex, destName);  // Find destination index
    if (dest == -1) {  // Check for valid input
        printf("Invalid vertex name entered!\n");
        return 1;  // Exit if invalid
    }

    // Initialize distances to INF, visited to 0, sequence to -1, and parent to -1
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
        visitedSequence[i] = -1;
        parent[i] = -1;
    }
    dist[src] = 0;  // Set distance of source to itself as 0

    // Dijkstra's algorithm implementation
    for (int k = 0; k < V - 1; k++) {
        int min = INF, u = -1;
        for (int i = 0; i < V; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }
        if (u == -1) break;  // Break if no reachable vertices
        visited[u] = 1;  // Mark the selected node as visited
        visitedSequence[u] = seq++;  // Update visit sequence

        // Update distances of adjacent vertices
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;  // Update parent for path tracking
            }
        }
    }

    printSolution(dist, parent, vertex, visitedSequence, src, dest);  // Display the solution
    saveToDotFile(parent, dist, graph, vertex, src, dest);  // Save the result to a .dot file for visualization
    return 0;
}
