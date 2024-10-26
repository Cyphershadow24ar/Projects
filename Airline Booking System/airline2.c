#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

#define MAX_AIRPORTS 10
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

void book_flight(AirlineSystem *system) {
    if (system->num_bookings >= MAX_BOOKINGS) {
        printf("Booking limit reached.\n");
        return;
    }

    Booking *new_booking = &system->bookings[system->num_bookings++];
    printf("Enter first name, last name: ");
    scanf("%s %s", new_booking->firstname, new_booking->lastname);
    printf("Enter passport number: ");
    scanf("%lld", &new_booking->passportnumber);
    printf("Enter source: ");
    scanf("%s", new_booking->source);
    printf("Enter destination: ");
    scanf("%s", new_booking->destination);
    printf("Enter travel date (DD MM YYYY): ");
    scanf("%d %d %d", &new_booking->date, &new_booking->month, &new_booking->year);

    printf("Enter seat class (Business/Economy/2nd): ");
    scanf("%s", new_booking->seat_class);
    if (strcmp(new_booking->seat_class, "Business") == 0) new_booking->price = 200.0;
    else if (strcmp(new_booking->seat_class, "Economy") == 0) new_booking->price = 100.0;
    else new_booking->price = 50.0;

    printf("Enter seat row and number: ");
    scanf("%d %d", &new_booking->seat_row, &new_booking->seat_num);

    new_booking->booking_status = true;
    printf("Booking confirmed for %s %s. Seat: %s%d%d at %.2f\n", new_booking->firstname, new_booking->lastname,
           new_booking->seat_class, new_booking->seat_row, new_booking->seat_num, new_booking->price);
}

void cancel_flight(AirlineSystem *system, long long passportnumber) {
    for (int i = 0; i < system->num_bookings; i++) {
        if (system->bookings[i].passportnumber == passportnumber && system->bookings[i].booking_status) {
            system->bookings[i].booking_status = false;
            printf("Booking for passport number %lld canceled successfully.\n", passportnumber);
            return;
        }
    }
    printf("Booking not found for passport number %lld.\n", passportnumber);
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

void make_payment(float amount) {
    int method;
    printf("Select Payment Method:\n1. Credit/Debit Card\n2. UPI\nChoose (1-2): ");
    scanf("%d", &method);

    if (method == 1) {
        char first[20], last[20];
        int card_number[20];
        printf("Enter card details - First name, Last name, Card number: ");
        scanf("%s %s %d", first, last, &card_number);
        printf("Payment of %.2f made via card.\n", amount);
    } else if (method == 2) {
        int upi_id[20];
        printf("Enter UPI ID: ");
        scanf("%d", &upi_id);
        printf("Payment of %.2f made via UPI.\n", amount);
    } else {
        printf("Invalid payment method.\n");
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

    int choice;
    do {
        printf("\nOptions:\n1. Search Flights\n2. Book Flight\n3. Cancel Flight\n4. List Available Flights\n5. Make Payment\n6. Exit\nChoose an option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            char origin[4], destination[4];
            printf("Enter origin and destination airport codes: ");
            scanf("%s %s", origin, destination);

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
            long long passportnumber;
            printf("Enter passport number for cancellation: ");
            scanf("%lld", &passportnumber);
            cancel_flight(&system, passportnumber);
        } else if (choice == 4) {
            list_routes(&system);
        } else if (choice == 5) {
            float amount;
            printf("Enter amount to pay: ");
            scanf("%f", &amount);
            make_payment(amount);
        } else if (choice == 6) {
            printf("Exiting the system.\n");
            break;
        } else {
            printf("Invalid option. Try again.\n");
        }
    } while (choice != 6);

    return 0;
}
