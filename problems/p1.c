#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_CARDS 5
#define NUM_RANKS 13
#define NUM_SUITS 4

// Define a structure for a card
struct card {
    int rank;
    int suit;
};

// Function prototypes
void read_hand(struct card hand[]);
void analyze_hand(struct card hand[], int *p_num_pairs, int *p_num_three_of_a_kind,
                 bool *p_straight, bool *p_flush, bool *p_four_of_a_kind, bool *p_full_house);
void print_result(int num_pairs, int num_three_of_a_kind, bool straight, bool flush,
                  bool four_of_a_kind, bool full_house);

int main(void) {
    struct card hand[NUM_CARDS];
    int num_pairs, num_three_of_a_kind;
    bool straight, flush, four_of_a_kind, full_house;

    printf("Enter five cards (e.g. 3H 4D 5C 6S 7H): ");
    read_hand(hand);

    analyze_hand(hand, &num_pairs, &num_three_of_a_kind, &straight, &flush,
                 &four_of_a_kind, &full_house);

    print_result(num_pairs, num_three_of_a_kind, straight, flush, four_of_a_kind, full_house);

    return 0;
}

// Read five cards into an array of structures
void read_hand(struct card hand[]) {
    char rank_ch, suit_ch;
    int rank, suit;
    bool bad_card;
    int cards_read = 0;

    while (cards_read < NUM_CARDS) {
        bad_card = false;

        printf("Card %d: ", cards_read + 1);
        scanf(" %c%c", &rank_ch, &suit_ch);

        // Convert rank character to a numeric value
        switch (rank_ch) {
            case '2': rank = 0; break;
            case '3': rank = 1; break;
            case '4': rank = 2; break;
            case '5': rank = 3; break;
            case '6': rank = 4; break;
            case '7': rank = 5; break;
            case '8': rank = 6; break;
            case '9': rank = 7; break;
            case 'T': rank = 8; break;
            case 'J': rank = 9; break;
            case 'Q': rank = 10; break;
            case 'K': rank = 11; break;
            case 'A': rank = 12; break;
            default: bad_card = true;
        }

        // Convert suit character to a numeric value
        switch (suit_ch) {
            case 'C': suit = 0; break;
            case 'D': suit = 1; break;
            case 'H': suit = 2; break;
            case 'S': suit = 3; break;
            default: bad_card = true;
        }

        if (bad_card) {
            printf("Bad card; ignored.\n");
        } else if (hand[cards_read].rank == rank && hand[cards_read].suit == suit) {
            printf("Duplicate card; ignored.\n");
        } else {
            hand[cards_read].rank = rank;
            hand[cards_read].suit = suit;
            cards_read++;
        }
    }
}

// Analyze a hand of five cards and determine its poker rank
void analyze_hand(struct card hand[], int *p_num_pairs, int *p_num_three_of_a_kind,
                  bool *p_straight, bool *p_flush, bool *p_four_of_a_kind, bool *p_full_house)
{
    int i, j, rank_count[NUM_RANKS] = {0};
    bool flush = true, straight = false, three_of_a_kind = false, pair = false;
    
    // Sort the cards by rank using bubble sort
    for (i = 0; i < NUM_CARDS - 1; i++) {
        for (j = 0; j < NUM_CARDS - i - 1; j++) {
            if (hand[j].rank > hand[j+1].rank) {
                struct card temp = hand[j];
                hand[j] = hand[j+1];
                hand[j+1] = temp;
            }
        }
    }
    
    // Count the number of cards with each rank
    for (i = 0; i < NUM_CARDS; i++) {
        rank_count[hand[i].rank]++;
    }
    
    // Check for flush
    for (i = 1; i < NUM_CARDS; i++) {
        if (hand[i].suit != hand[0].suit) {
            flush = false;
            break;
        }
    }
    
    // Check for straight
    if (rank_count[NUM_RANKS-1] == 1 && rank_count[0] == 1) {
        straight = true;
        for (i = 1; i < NUM_RANKS-1; i++) {
            if (rank_count[i] != 1) {
                straight = false;
                break;
            }
        }
    } else {
        for (i = 0; i < NUM_RANKS-1; i++) {
            if (rank_count[i] != 1) {
                break;
            }
        }
        if (i == NUM_RANKS-1) {
            straight = true;
        }
    }
    
    // Check for pairs, three of a kind, and four of a kind
    for (i = 0; i < NUM_RANKS; i++) {
        if (rank_count[i] == 4) {
            *p_four_of_a_kind = true;
        } else if (rank_count[i] == 3) {
            three_of_a_kind = true;
        } else if (rank_count[i] == 2) {
            if (pair) {
                *p_full_house = true;
            } else {
                pair = true;
            }
        }
    }
    
    // Set output variables
    *p_num_pairs = pair + *p_full_house;
    *p_num_three_of_a_kind = three_of_a_kind + *p_full_house;
    *p_straight = straight;
    *p_flush = flush;
}

// Print the poker rank of a hand
void print_result(int num_pairs, int num_three_of_a_kind, bool straight, bool flush,
                  bool four_of_a_kind, bool full_house)
{
    if (straight && flush) printf("Straight flush");
    else if (four_of_a_kind) printf("Four of a kind");
    else if (full_house) printf("Full house");
    else if (flush) printf("Flush");
    else if (straight) printf("Straight");
    else if (num_three_of_a_kind == 1) printf("Three of a kind");
    else if (num_pairs == 2) printf("Two pairs");
    else if (num_pairs == 1) printf("One pair");
    else printf("High card");

    printf("\n");
}
