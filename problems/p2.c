#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_ROWS 5
#define NUM_COLS 4
#define NUM_SEATS (NUM_ROWS * NUM_COLS)

// Define a structure for a seat
struct seat {
    int row;
    char col;
    bool occupied;
};

// Function prototypes
void init_seats(struct seat seats[]);
void print_seats(struct seat seats[]);
bool assign_seat(struct seat seats[], int row, char col);

int main(void) {
    struct seat seats[NUM_SEATS];
    int row;
    char col;
    bool done = false;

    init_seats(seats);
    print_seats(seats);

    while (!done) {
        printf("Enter seat (row col): ");
        scanf("%d %c", &row, &col);

        if (row < 1 || row > NUM_ROWS || col < 'A' || col > 'D') {
            printf("Invalid seat; try again.\n");
        } else if (assign_seat(seats, row, col)) {
            printf("Seat %d%c assigned.\n", row, col);
            print_seats(seats);
        } else {
            printf("Seat %d%c is already occupied; try again.\n", row, col);
        }

        if (seats[NUM_SEATS - 1].occupied) {
            printf("All seats are occupied.\n");
            done = true;
        } else {
            printf("Do you want to quit? (y/n) ");
            char answer;
            scanf(" %c", &answer);
            if (answer == 'y' || answer == 'Y') {
                done = true;
            }
        }
    }

    return 0;
}

// Initialize the seats as unoccupied
void init_seats(struct seat seats[]) {
    for (int i = 0; i < NUM_SEATS; i++) {
        seats[i].row = i / NUM_COLS + 1;
        seats[i].col = 'A' + i % NUM_COLS;
        seats[i].occupied = false;
    }
}

// Print the seat pattern, marking with an 'X' the seats already assigned
void print_seats(struct seat seats[]) {
    printf("  A B C D\n");
    for (int row = 1; row <= NUM_ROWS; row++) {
        printf("%d ", row);
        for (char col = 'A'; col <= 'D'; col++) {
            bool occupied = false;
            for (int i = 0; i < NUM_SEATS; i++) {
                if (seats[i].row == row && seats[i].col == col && seats[i].occupied) {
                    occupied = true;
                    break;
                }
            }
            printf("%c ", occupied ? 'X' : col);
        }
        printf("\n");
    }
}

// Assign a seat if it's unoccupied; return true if successful, false otherwise
bool assign_seat(struct seat seats[], int row, char col) {
    for (int i = 0; i < NUM_SEATS; i++) {
        if (seats[i].row == row && seats[i].col == col && !seats[i].occupied) {
            seats[i].occupied = true;
            return true;
        }
    }
    return false;
}
