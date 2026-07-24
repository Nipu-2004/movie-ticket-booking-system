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
void viewShowtimes();
void viewSeatMap();
void bookSeats();
void cancelBooking();

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
            case 1: viewShowtimes(); break;
            case 2: viewSeatMap(); break;
            case 3: bookSeats(); break;
            case 4: cancelBooking(); break;
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
}

void viewShowtimes() {
    printf("\n--- AVAILABLE SHOWTIMES ---\n");
    printf("1. Avatar 3 (10:00 AM)\n");
    printf("2. Avatar 3 (01:00 PM)\n");
    printf("3. Inception (02:30 PM)\n");
    printf("4. Inception (05:30 PM)\n");
    printf("5. Interstellar (06:30 PM)\n");
    printf("6. Interstellar (09:30 PM)\n");
}

void viewSeatMap() {
    int showChoice;
    viewShowtimes();
    printf("\nSelect Showtime (1-6): ");
    scanf("%d", &showChoice);

    if (showChoice < 1 || showChoice > 6) {
        printf("Invalid Showtime!\n");
        return;
    }

    printf("\n--- SEAT MAP ---\n");
    printf("     ");
    for (int c = 1; c <= COLS; c++) {
        printf("%2d ", c);
    }
    printf("\n");

    for (int r = 0; r < ROWS; r++) {
        printf("Row %c: ", 'A' + r);
        for (int c = 0; c < COLS; c++) {
            int booked = 0;
            if (showChoice == 1) booked = seats_show1[r][c];
            else if (showChoice == 2) booked = seats_show2[r][c];
            else if (showChoice == 3) booked = seats_show3[r][c];
            else if (showChoice == 4) booked = seats_show4[r][c];
            else if (showChoice == 5) booked = seats_show5[r][c];
            else if (showChoice == 6) booked = seats_show6[r][c];

            if (booked == 1) {
                printf(" X ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
    printf("(. = Available, X = Booked)\n");
}

void bookSeats() {
    int showChoice;
    viewShowtimes();
    printf("\nSelect Showtime to book (1-6): ");
    scanf("%d", &showChoice);

    if (showChoice < 1 || showChoice > 6) {
        printf("Invalid Showtime!\n");
        return;
    }

    char rowChar;
    int col;
    printf("Enter Row (A-E): ");
    scanf(" %c", &rowChar);
    int r = rowChar - 'A';
    printf("Enter Column (1-10): ");
    scanf("%d", &col);
    int c = col - 1;

    if (r >= 0 && r < ROWS && c >= 0 && c < COLS) {
        int *seatPtr = NULL;
        char *namePtr = NULL;
        double *pricePtr = NULL;

        if (showChoice == 1) { seatPtr = &seats_show1[r][c]; namePtr = &names_show1[r][c][0]; pricePtr = &price_show1[r][c]; }
        else if (showChoice == 2) { seatPtr = &seats_show2[r][c]; namePtr = &names_show2[r][c][0]; pricePtr = &price_show2[r][c]; }
        else if (showChoice == 3) { seatPtr = &seats_show3[r][c]; namePtr = &names_show3[r][c][0]; pricePtr = &price_show3[r][c]; }
        else if (showChoice == 4) { seatPtr = &seats_show4[r][c]; namePtr = &names_show4[r][c][0]; pricePtr = &price_show4[r][c]; }
        else if (showChoice == 5) { seatPtr = &seats_show5[r][c]; namePtr = &names_show5[r][c][0]; pricePtr = &price_show5[r][c]; }
        else if (showChoice == 6) { seatPtr = &seats_show6[r][c]; namePtr = &names_show6[r][c][0]; pricePtr = &price_show6[r][c]; }

        if (*seatPtr == 0) {
            *seatPtr = 1;
            printf("Enter Name: ");
            scanf("%s", namePtr);
            printf("Enter Price: ");
            scanf("%lf", pricePtr);
            printf("Seat booked successfully!\n");
        } else {
            printf("Seat already booked!\n");
        }
    } else {
        printf("Invalid seat position!\n");
    }
}

void cancelBooking() {
    int showChoice;
    viewShowtimes();
    printf("\nSelect Showtime to cancel (1-6): ");
    scanf("%d", &showChoice);

    if (showChoice < 1 || showChoice > 6) {
        printf("Invalid Showtime!\n");
        return;
    }

    char rowChar;
    int col;
    printf("Enter Row (A-E): ");
    scanf(" %c", &rowChar);
    int r = rowChar - 'A';
    printf("Enter Column (1-10): ");
    scanf("%d", &col);
    int c = col - 1;

    if (r >= 0 && r < ROWS && c >= 0 && c < COLS) {
        int *seatPtr = NULL;
        char *namePtr = NULL;
        double *pricePtr = NULL;

        if (showChoice == 1) { seatPtr = &seats_show1[r][c]; namePtr = &names_show1[r][c][0]; pricePtr = &price_show1[r][c]; }
        else if (showChoice == 2) { seatPtr = &seats_show2[r][c]; namePtr = &names_show2[r][c][0]; pricePtr = &price_show2[r][c]; }
        else if (showChoice == 3) { seatPtr = &seats_show3[r][c]; namePtr = &names_show3[r][c][0]; pricePtr = &price_show3[r][c]; }
        else if (showChoice == 4) { seatPtr = &seats_show4[r][c]; namePtr = &names_show4[r][c][0]; pricePtr = &price_show4[r][c]; }
        else if (showChoice == 5) { seatPtr = &seats_show5[r][c]; namePtr = &names_show5[r][c][0]; pricePtr = &price_show5[r][c]; }
        else if (showChoice == 6) { seatPtr = &seats_show6[r][c]; namePtr = &names_show6[r][c][0]; pricePtr = &price_show6[r][c]; }

        if (*seatPtr == 1) {
            *seatPtr = 0;
            namePtr[0] = '\0';
            *pricePtr = 0.0;
            printf("Booking cancelled successfully!\n");
        } else {
            printf("Seat is already vacant/not booked!\n");
        }
    } else {
        printf("Invalid seat position!\n");
    }
}
