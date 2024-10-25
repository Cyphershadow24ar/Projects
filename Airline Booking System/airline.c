#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

#define MAX_AIRPORTS 10
#define MAX_BOOKINGS 100
#define INF INT_MAX

typedef struct {
    int num_airports;
    int distances[MAX_AIRPORTS][MAX_AIRPORTS];
    char *airport_names[MAX_AIRPORTS];
    bool bookings[MAX_BOOKINGS];
    int num_bookings;
} AirlineSystem;

void initialize_system(AirlineSystem *system, int num_airports) {
    system->num_airports = num_airports;
    system->num_bookings = 0;
    for (int i = 0; i < num_airports; i++) {
        for (int j = 0; j < num_airports; j++) {
            system->distances[i][j] = (i == j) ? 0 : INF;
        }
    }
}

void add_airport(AirlineSystem *system, int index, char *name) {
    if (index >= 0 && index < system->num_airports) {
        system->airport_names[index] = name;
    }
}

void add_route(AirlineSystem *system, int origin, int destination, int distance) {
    if (origin >= 0 && origin < system->num_airports && destination >= 0 && destination < system->num_airports) {
        system->distances[origin][destination] = distance;
        system->distances[destination][origin] = distance;
    }
}

int get_airport_index(AirlineSystem *system, char *name) {
    for (int i = 0; i < system->num_airports; i++) {
        if (system->airport_names[i] != NULL && strcmp(system->airport_names[i], name) == 0) {
            return i;
        }
    }
    return -1;
}

void dijkstra(AirlineSystem *system, int start, int end) {
    int distances[MAX_AIRPORTS];
    bool visited[MAX_AIRPORTS] = {false};
    int previous[MAX_AIRPORTS];

    for (int i = 0; i < system->num_airports; i++) {
        distances[i] = INF;
        previous[i] = -1;
    }
    distances[start] = 0;

    for (int i = 0; i < system->num_airports - 1; i++) {
        int min_distance = INF, min_index = -1;
        
        for (int j = 0; j < system->num_airports; j++) {
            if (!visited[j] && distances[j] < min_distance) {
                min_distance = distances[j];
                min_index = j;
            }
        }
        
        if (min_index == -1) break;
        visited[min_index] = true;

        for (int k = 0; k < system->num_airports; k++) {
            if (!visited[k] && system->distances[min_index][k] != INF && 
                distances[min_index] + system->distances[min_index][k] < distances[k]) {
                distances[k] = distances[min_index] + system->distances[min_index][k];
                previous[k] = min_index;
            }
        }
    }

    if (distances[end] == INF) {
        printf("No available route from %s to %s.\n", system->airport_names[start], system->airport_names[end]);
    } else {
        printf("Shortest route from %s to %s with distance %d km:\n", system->airport_names[start], system->airport_names[end], distances[end]);
        
        int path[MAX_AIRPORTS];
        int path_index = 0;
        for (int at = end; at != -1; at = previous[at]) {
            path[path_index++] = at;
        }
        
        for (int i = path_index - 1; i >= 0; i--) {
            printf("%s", system->airport_names[path[i]]);
            if (i > 0) printf(" -> ");
        }
        printf("\n");
    }
}

void book_flight(AirlineSystem *system, int start, int end) {
    printf("Booking a flight from %s to %s...\n", system->airport_names[start], system->airport_names[end]);
    system->bookings[system->num_bookings++] = true;
    printf("Flight booked successfully! Booking ID: %d\n", system->num_bookings - 1);
}

void cancel_flight(AirlineSystem *system, int booking_id) {
    if (booking_id >= 0 && booking_id < system->num_bookings && system->bookings[booking_id]) {
        system->bookings[booking_id] = false;
        printf("Flight with Booking ID %d canceled successfully.\n", booking_id);
    } else {
        printf("Invalid Booking ID or flight already canceled.\n");
    }
}

void list_routes(AirlineSystem *system) {
    printf("Available routes and distances:\n");
    for (int i = 0; i < system->num_airports; i++) {
        for (int j = i + 1; j < system->num_airports; j++) {
            if (system->distances[i][j] != INF) {
                printf("%s -> %s: %d km\n", system->airport_names[i], system->airport_names[j], system->distances[i][j]);
            }
        }
    }
}

int main() {
    AirlineSystem system;
    initialize_system(&system, 5);

    add_airport(&system, 0, "JFK");
    add_airport(&system, 1, "LAX");
    add_airport(&system, 2, "ORD");
    add_airport(&system, 3, "DFW");
    add_airport(&system, 4, "ATL");

    add_route(&system, 0, 1, 3980);
    add_route(&system, 0, 2, 1190);
    add_route(&system, 2, 1, 2800);
    add_route(&system, 2, 3, 1300);
    add_route(&system, 1, 3, 2000);

    printf("Welcome to the Airline Management Flight Booking System!\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Search Flights\n");
        printf("2. Book Flight\n");
        printf("3. Cancel Flight\n");
        printf("4. List Available Flights\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            char origin[4], destination[4];
            printf("Enter origin airport code: ");
            scanf("%s", origin);
            printf("Enter destination airport code: ");
            scanf("%s", destination);

            int origin_index = get_airport_index(&system, origin);
            int destination_index = get_airport_index(&system, destination);

            if (origin_index == -1 || destination_index == -1) {
                printf("Invalid airport code. Try again.\n");
            } else {
                dijkstra(&system, origin_index, destination_index);
            }
        } else if (choice == 2) {
            char origin[4], destination[4];
            printf("Enter origin airport code: ");
            scanf("%s", origin);
            printf("Enter destination airport code: ");
            scanf("%s", destination);

            int origin_index = get_airport_index(&system, origin);
            int destination_index = get_airport_index(&system, destination);

            if (origin_index == -1 || destination_index == -1) {
                printf("Invalid airport code. Try again.\n");
            } else {
                book_flight(&system, origin_index, destination_index);
            }
        } else if (choice == 3) {
            int booking_id;
            printf("Enter Booking ID to cancel: ");
            scanf("%d", &booking_id);
            cancel_flight(&system, booking_id);
        } else if (choice == 4) {
            list_routes(&system);
        } else if (choice == 5) {
            printf("Exiting the system.\n");
            break;
        } else {
            printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}
