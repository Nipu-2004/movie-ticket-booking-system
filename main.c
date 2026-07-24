#include <stdio.h>

#define ROWS 5
#define COLS 10

int seats_show1[ROWS][COLS];
char names_show1[ROWS][COLS][50];
double price_show1[ROWS][COLS];

int seats_show2[ROWS][COLS];
char names_show2[ROWS][COLS][50];
double price_show2[ROWS][COLS];

int seats_show3[ROWS][COLS];
char names_show3[ROWS][COLS][50];
double price_show3[ROWS][COLS];

int seats_show4[ROWS][COLS];
char names_show4[ROWS][COLS][50];
double price_show4[ROWS][COLS];

int seats_show5[ROWS][COLS];
char names_show5[ROWS][COLS][50];
double price_show5[ROWS][COLS];

int seats_show6[ROWS][COLS];
char names_show6[ROWS][COLS][50];
double price_show6[ROWS][COLS];

void initializeData();

int main() {
    initializeData();
    int choice = 0;

    while (choice != 7) {
        printf("\n=====================================\n");
        printf("    MOVIE TICKET BOOKING SYSTEM      \n");
        printf("=====================================\n");
        printf("1. View Showtimes\n");
        printf("2. View Seat Map\n");
        printf("3. Book Seats\n");
        printf("4. Cancel Booking\n");
        printf("5. Search Booking\n");
        printf("6. View Revenue Report\n");
        printf("7. Exit\n");
        printf("-------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: break;
            case 2: break;
            case 3: break;
            case 4: break;
            case 5: break;
            case 6: break;
            case 7:
                printf("\nThank you for using the system!\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    }
    return 0;
}

void initializeData() {
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            seats_show1[r][c] = 0; seats_show2[r][c] = 0; seats_show3[r][c] = 0;
            seats_show4[r][c] = 0; seats_show5[r][c] = 0; seats_show6[r][c] = 0;
            names_show1[r][c][0] = '\0'; names_show2[r][c][0] = '\0'; names_show3[r][c][0] = '\0';
            names_show4[r][c][0] = '\0'; names_show5[r][c][0] = '\0'; names_show6[r][c][0] = '\0';
            price_show1[r][c] = 0.0; price_show2[r][c] = 0.0; price_show3[r][c] = 0.0;
            price_show4[r][c] = 0.0; price_show5[r][c] = 0.0; price_show6[r][c] = 0.0;
        }
    }
}ss
