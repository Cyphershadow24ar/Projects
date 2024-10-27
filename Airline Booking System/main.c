#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

#define MAX_AIRPORTS 17
#define MAX_BOOKINGS 100
#define INF INT_MAX

typedef struct {
    char firstname[25];
    char lastname[25];
    long long passportnumber;
    char source[15];
    char destination[15];
    int date, month, year;
    char seat_class[20];
    int seat_row, seat_num;
    float price;
    bool booking_status;
} Booking;

typedef struct {
    int num_airports;
    int distances[MAX_AIRPORTS][MAX_AIRPORTS];
    char *airport_names[MAX_AIRPORTS];
    Booking bookings[MAX_BOOKINGS];
    int num_bookings;
} AirlineSystem;

void initialize_system(AirlineSystem *system, int num_airports) {
    system->num_airports = num_airports;
    system->num_bookings = 0;
    for (int i = 0; i < num_airports; i++) {
        for (int j = 0; j < num_airports; j++) {
            system->distances[i][j] = (i == j) ? 0 : INF;
        }
        system->airport_names[i] = NULL;
    }
}

void add_airport(AirlineSystem *system, int index, const char *name) {
    if (index >= 0 && index < system->num_airports) {
        system->airport_names[index] = strdup(name); // Allocate memory for airport name
    }
}

void add_route(AirlineSystem *system, int origin, int destination, int distance) {
    if (origin >= 0 && origin < system->num_airports && destination >= 0 && destination < system->num_airports) {
        system->distances[origin][destination] = distance;
        system->distances[destination][origin] = distance;
    }
}

int get_airport_index(AirlineSystem *system, const char *name) {
    for (int i = 0; i < system->num_airports; i++) {
        if (system->airport_names[i] != NULL && strcmp(system->airport_names[i], name) == 0) {
            return i;
        }
    }
    return -1;
}

// Dijkstra's algorithm to find the shortest path between airports
void dijkstra(AirlineSystem *system, int start, int end) {
    int distances[MAX_AIRPORTS], previous[MAX_AIRPORTS];
    bool visited[MAX_AIRPORTS] = {false};

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
        int path[MAX_AIRPORTS], path_index = 0;
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

// Function to create a booking for a passenger with distance-based price calculation
void book_flight(AirlineSystem *system) {
    if (system->num_bookings >= MAX_BOOKINGS) {
        printf("Booking limit reached.\n");
        return;
    }

    Booking *new_booking = &system->bookings[system->num_bookings++];
    printf("Enter first name, last name: ");
    scanf("%24s %24s", new_booking->firstname, new_booking->lastname);
    printf("Enter passport number: ");
    scanf("%lld", &new_booking->passportnumber);
    printf("Enter source airport code: ");
    scanf("%14s", new_booking->source);
    printf("Enter destination airport code: ");
    scanf("%14s", new_booking->destination);

    // Calculate distance between source and destination airports
    int source_index = get_airport_index(system, new_booking->source);
    int destination_index = get_airport_index(system, new_booking->destination);
    if (source_index == -1 || destination_index == -1 || system->distances[source_index][destination_index] == INF) {
        printf("Invalid or unavailable route.\n");
        system->num_bookings--;  // Undo booking increment if invalid
        return;
    }

    int distance = system->distances[source_index][destination_index];
    printf("Enter travel date (DD MM YYYY): ");
    scanf("%d %d %d", &new_booking->date, &new_booking->month, &new_booking->year);

    printf("Enter seat class (Business/Economy/2nd): ");
    scanf("%19s", new_booking->seat_class);

    // Calculate price based on class and distance
    if (strcmp(new_booking->seat_class, "Business") == 0) {
        new_booking->price = distance * 9;
    } else if (strcmp(new_booking->seat_class, "Economy") == 0) {
        new_booking->price = distance * 6;
    } else if (strcmp(new_booking->seat_class, "2nd") == 0) {
        new_booking->price = distance * 3;
    } else {
        printf("Invalid seat class.\n");
        system->num_bookings--;  // Undo booking increment if invalid
        return;
    }

    printf("Enter seat row and number: ");
    scanf("%d %d", &new_booking->seat_row, &new_booking->seat_num);

    new_booking->booking_status = true;
    printf("Booking confirmed for %s %s. Seat: %s %d %d at Rs%.2f\n", 
        new_booking->firstname, new_booking->lastname,
        new_booking->seat_class, new_booking->seat_row, new_booking->seat_num, 
        new_booking->price);
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
    initialize_system(&system, 17);

    // Add airports with actual names
    add_airport(&system, 0, "BBSR"); // Bhubaneswar
    add_airport(&system, 1, "RAH");  // Ranchi
    add_airport(&system, 2, "PAT");  // Patna
    add_airport(&system, 3, "HYD");  // Hyderabad
    add_airport(&system, 4, "DEL");  // Delhi
    add_airport(&system, 5, "MUM");  // Mumbai
    add_airport(&system, 6, "PUN");  // Pune
    add_airport(&system, 7, "BLR");  // Bengaluru
    add_airport(&system, 8, "CHE");  // Chennai
    add_airport(&system, 9, "GUH");  // Guwahati
    add_airport(&system, 10, "AHE"); // Ahmedabad
    add_airport(&system, 11, "KOL"); // Kolkata
    add_airport(&system, 12, "IND"); // Indore
    add_airport(&system, 13, "GOA"); // Goa
    add_airport(&system, 14, "KOC"); // Kochi
    add_airport(&system, 15, "LCK"); // Lucknow
    add_airport(&system, 16, "NAG"); // Nagaland

    // Initial main connections
    add_route(&system, 0, 1, 370);   // BBSR to Ranchi
    add_route(&system, 0, 2, 490);   // BBSR to Patna
    add_route(&system, 0, 3, 1400);  // BBSR to Hyderabad
    add_route(&system, 0, 4, 1700);  // BBSR to Delhi
    add_route(&system, 0, 5, 1400);  // BBSR to Mumbai

    add_route(&system, 1, 2, 280);   // Ranchi to Patna
    add_route(&system, 1, 3, 1100);  // Ranchi to Hyderabad
    add_route(&system, 1, 4, 1600);  // Ranchi to Delhi
    add_route(&system, 1, 5, 1600);  // Ranchi to Mumbai
    add_route(&system, 1, 6, 1800);  // Ranchi to Pune

    add_route(&system, 2, 3, 1500);  // Patna to Hyderabad
    add_route(&system, 2, 4, 990);   // Patna to Delhi
    add_route(&system, 2, 5, 1700);  // Patna to Mumbai
    add_route(&system, 2, 6, 1740);  // Patna to Pune
    add_route(&system, 2, 8, 1300);  // Patna to Chennai

    add_route(&system, 3, 4, 1550);  // Hyderabad to Delhi
    add_route(&system, 3, 5, 710);   // Hyderabad to Mumbai
    add_route(&system, 3, 6, 580);   // Hyderabad to Pune
    add_route(&system, 3, 7, 570);   // Hyderabad to Bengaluru
    add_route(&system, 3, 8, 630);   // Hyderabad to Chennai

    add_route(&system, 4, 5, 1400);  // Delhi to Mumbai
    add_route(&system, 4, 6, 1510);  // Delhi to Pune
    add_route(&system, 4, 7, 1730);  // Delhi to Bengaluru
    add_route(&system, 4, 9, 1620);  // Delhi to Guwahati
    add_route(&system, 4, 10, 950);  // Delhi to Ahmedabad

    add_route(&system, 5, 6, 150);   // Mumbai to Pune
    add_route(&system, 5, 7, 980);   // Mumbai to Bengaluru
    add_route(&system, 5, 8, 1030);  // Mumbai to Chennai
    add_route(&system, 5, 10, 520);  // Mumbai to Ahmedabad
    add_route(&system, 5, 13, 570);  // Mumbai to Goa

    // Additional connections to ensure each airport has at least 5 routes
    add_route(&system, 6, 7, 840);   // Pune to Bengaluru
    add_route(&system, 6, 10, 660);  // Pune to Ahmedabad
    add_route(&system, 6, 13, 500);  // Pune to Goa
    add_route(&system, 6, 8, 1200);  // Pune to Chennai
    add_route(&system, 7, 8, 350);   // Bengaluru to Chennai

    add_route(&system, 7, 10, 1230); // Bengaluru to Ahmedabad
    add_route(&system, 7, 13, 590);  // Bengaluru to Goa
    add_route(&system, 8, 10, 1600); // Chennai to Ahmedabad
    add_route(&system, 8, 13, 790);  // Chennai to Goa
    add_route(&system, 8, 14, 680);  // Chennai to Kochi

    add_route(&system, 9, 4, 1620);  // Guwahati to Delhi
    add_route(&system, 9, 11, 990);  // Guwahati to Kolkata
    add_route(&system, 9, 15, 1240); // Guwahati to Lucknow
    add_route(&system, 9, 12, 1550); // Guwahati to Indore
    add_route(&system, 9, 16, 2030); // Guwahati to Nagaland

    add_route(&system, 10, 11, 620); // Ahmedabad to Kolkata
    add_route(&system, 10, 12, 340); // Ahmedabad to Indore
    add_route(&system, 10, 14, 1060); // Ahmedabad to Kochi
    add_route(&system, 10, 15, 990);  // Ahmedabad to Lucknow

    add_route(&system, 11, 12, 1200); // Kolkata to Indore
    add_route(&system, 11, 15, 980);  // Kolkata to Lucknow
    add_route(&system, 11, 16, 1600); // Kolkata to Nagaland

    add_route(&system, 12, 13, 540);  // Indore to Goa
    add_route(&system, 12, 14, 960);  // Indore to Kochi
    add_route(&system, 12, 15, 670);  // Indore to Lucknow
    add_route(&system, 12, 16, 1280); // Indore to Nagaland

    add_route(&system, 13, 14, 630);  // Goa to Kochi
    add_route(&system, 13, 15, 1420); // Goa to Lucknow
    add_route(&system, 13, 16, 1480); // Goa to Nagaland

    add_route(&system, 14, 15, 1900); // Kochi to Lucknow
    add_route(&system, 14, 16, 2000); // Kochi to Nagaland
    add_route(&system, 15, 16, 1480); // Lucknow to Nagaland

    printf("Welcome to the Airline Management Flight Booking System!\n");

    int choice;
    do {
        printf("\nOptions:\n1. Search Flights\n2. Book Flight\n3. List Available Flights\n4. Exit\nChoose an option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            char origin[4], destination[4];
            printf("Enter origin and destination airport codes: ");
            scanf("%3s %3s", origin, destination);

            int origin_index = get_airport_index(&system, origin);
            int destination_index = get_airport_index(&system, destination);

            if (origin_index == -1 || destination_index == -1) {
                printf("Invalid airport code.\n");
            } else {
                dijkstra(&system, origin_index, destination_index);
            }
        } else if (choice == 2) {
            book_flight(&system);
        } else if (choice == 3) {
            list_routes(&system);
        } else if (choice == 4) {
            printf("Exiting the system.\n");
            break;
        } else {
            printf("Invalid option. Try again.\n");
        }
    } while (choice != 4);

    // Free allocated memory for airport names
    for (int i = 0; i < system.num_airports; i++) {
        free(system.airport_names[i]);
    }

    return 0;
}
