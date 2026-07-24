#include <stdio.h>
#include <string.h>

int main() {
    char movieTitles[6][100] = { "Avatar 3", "Avatar 3", "Inception", "Inception", "Interstellar", "Interstellar" };
    char showTimes[6][20] = { "10:00 AM", "02:30 PM", "01:00 PM", "06:30 PM", "09:00 AM", "08:00 PM" };
    int isBooked[6][50];
    int customerIDs[6][50];
    int ticketPrice[6][50];

    for(int s = 0; s < 6; s++) {
        for(int seat = 0; seat < 50; seat++) {
            isBooked[s][seat] = 0;
            customerIDs[s][seat] = 0;
            ticketPrice[s][seat] = 0;
        }
    }

    int choice;

    while(1) {
        printf("\n===================================\n");
        printf(" MOVIE TICKET BOOKING SYSTEM\n");
        printf("===================================\n");
        printf("1. View Showtimes\n");
        printf("2. View Seat Map\n");
        printf("3. Book a Seat\n");
        printf("4. Cancel a Booking\n");
        printf("5. Search Booking\n");
        printf("6. View Revenue Report\n");
        printf("7. Exit\n");
        printf("-----------------------------------\n");
        printf("Enter your choice (1-7): ");

        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid choice! Please enter a number between 1 and 7.\n");
            while (getchar() != '\n');
            continue;
        }

        switch(choice) {
            case 1:
                printf("\n--- Available Movies & Showtimes ---\n");
                for(int i = 0; i < 6; i++) {
                    printf("%d. Movie: %s | Showtime: %s\n", i + 1, movieTitles[i], showTimes[i]);
                }
                break;

            case 2: {
                int showChoice;
                printf("\n--- View Seat Map ---\n");
                printf("Select Showtime (1-6): ");
                if (scanf("%d", &showChoice) != 1) {
                    printf("Invalid showtime choice!\n");
                    while (getchar() != '\n');
                    break;
                }
                if (showChoice < 1 || showChoice > 6) {
                    printf("Invalid showtime choice!\n");
                    break;
                }
                int sIdx = showChoice - 1;
                printf("\n============================================================\n");
                printf(" SEAT MAP: %s | Showtime: %s\n", movieTitles[sIdx], showTimes[sIdx]);
                printf("============================================================\n");
                printf(" Tiers: [A-B] Regular (Rs.500) | [C-D] Premium (Rs.750) | [E] VIP (Rs.1000)\n");
                printf(" Legend: . = Available | X = Booked\n");
                printf("------------------------------------------------------------\n\n");
                printf(" ");
                for (int col = 1; col <= 10; col++) {
                    printf("%2d ", col);
                }
                printf("\n");
                for (int row = 0; row < 5; row++) {
                    char rowLabel = 'A' + row;
                    char *tierLabel = (row < 2) ? "Reg " : (row < 4) ? "Prem" : "VIP ";
                    printf("%c (%s) ", rowLabel, tierLabel);
                    for (int col = 0; col < 10; col++) {
                        int seatIndex = (row * 10) + col;
                        if (isBooked[sIdx][seatIndex] == 1) {
                            printf(" X ");
                        } else {
                            printf(" . ");
                        }
                    }
                    printf("\n");
                }
                printf("\n [ SCREEN THIS WAY ] \n");
                break;
            }
            case 3: {
                int showChoice, custID, category, numSeats;
                printf("\n--- Book a Seat ---\n");
                printf("Select Showtime (1-6): ");
                if (scanf("%d", &showChoice) != 1) {
                    printf("Invalid showtime choice!\n");
                    while (getchar() != '\n');
                    break;
                }
                if (showChoice < 1 || showChoice > 6) {
                    printf("Invalid showtime choice!\n");
                    break;
                }
                int sIdx = showChoice - 1;
                printf("Enter Customer ID (Number): ");
                if (scanf("%d", &custID) != 1) {
                    printf("Invalid Customer ID format!\n");
                    while (getchar() != '\n');
                    break;
                }
                printf("\nSelect Category:\n1. Regular\n2. Student (10%% off)\n3. Senior Citizen (20%% off)\nChoice: ");
                if (scanf("%d", &category) != 1) {
                    printf("Invalid category selected!\n");
                    while (getchar() != '\n');
                    break;
                }
                if (category < 1 || category > 3) {
                    printf("Invalid category selected!\n");
                    break;
                }
                printf("How many seats would you like to book? ");
                if (scanf("%d", &numSeats) != 1) {
                    printf("Invalid number of seats!\n");
                    while (getchar() != '\n');
                    break;
                }
                if (numSeats <= 0) {
                    printf("Invalid number of seats!\n");
                    break;
                }
                int seatIndices[50];
                int validBooking = 1;
                for (int i = 0; i < numSeats; i++) {
                    char rowChar;
                    int colNum;
                    printf("Seat %d of %d - Enter Row (A-E) and Column (1-10) [e.g. C 4]: ", i + 1, numSeats);
                    if (scanf(" %c %d", &rowChar, &colNum) != 2) {
                        printf("Invalid seat input format!\n");
                        while (getchar() != '\n');
                        validBooking = 0;
                        break;
                    }
                    if (rowChar >= 'a' && rowChar <= 'z') {
                        rowChar = rowChar - 'a' + 'A';
                    }
                    int r = rowChar - 'A';
                    int c = colNum - 1;
                    if (r < 0 || r >= 5 || c < 0 || c >= 10) {
                        printf("Error: Seat %c%d is out of range!\n", rowChar, colNum);
                        validBooking = 0;
                        break;
                    }
                    int seatIdx = (r * 10) + c;
                    if (isBooked[sIdx][seatIdx] == 1) {
                        printf("Error: Seat %c%d is already booked!\n", rowChar, colNum);
                        validBooking = 0;
                        break;
                    }
                    for (int k = 0; k < i; k++) {
                        if (seatIndices[k] == seatIdx) {
                            printf("Error: You entered seat %c%d twice!\n", rowChar, colNum);
                            validBooking = 0;
                            break;
                        }
                    }
                    if (!validBooking) break;
                    seatIndices[i] = seatIdx;
                }
                if (validBooking) {
                    double totalCost = 0;
                    printf("\n--- Booking Confirmed ---\n");
                    for (int i = 0; i < numSeats; i++) {
                        int idx = seatIndices[i];
                        int r = idx / 10;
                        double basePrice = (r < 2) ? 500.0 : (r < 4) ? 750.0 : 1000.0;
                        double discount = 0.0;
                        if (category == 2) discount += 0.10;
                        else if (category == 3) discount += 0.20;
                        if (numSeats >= 4) discount += 0.10;
                        double finalPrice = basePrice * (1.0 - discount);
                        isBooked[sIdx][idx] = 1;
                        customerIDs[sIdx][idx] = custID;
                        ticketPrice[sIdx][idx] = (int)finalPrice;
                        totalCost += finalPrice;
                        printf("Seat %c%d -> Price: Rs. %.2f\n", 'A' + r, (idx % 10) + 1, finalPrice);
                    }
                    printf("---------------------------\n");
                    printf("Total Amount: Rs. %.2f\n", totalCost);
                }
                break;
            }

            case 4: {
                int showChoice, colNum;
                char rowChar;
                printf("\n--- Cancel a Booking ---\n");
                printf("Select Showtime (1-6): ");
                if (scanf("%d", &showChoice) != 1) {
                    printf("Invalid showtime choice!\n");
                    while (getchar() != '\n');
                    break;
                }
                if (showChoice < 1 || showChoice > 6) {
                    printf("Invalid showtime choice!\n");
                    break;
                }
                int sIdx = showChoice - 1;
                printf("Enter Seat to Cancel (e.g. C 4): ");
                if (scanf(" %c %d", &rowChar, &colNum) != 2) {
                    printf("Invalid seat cancellation input!\n");
                    while (getchar() != '\n');
                    break;
                }
                if (rowChar >= 'a' && rowChar <= 'z') {
                    rowChar = rowChar - 'a' + 'A';
                }
                int r = rowChar - 'A';
                int c = colNum - 1;
                if (r < 0 || r >= 5 || c < 0 || c >= 10) {
                    printf("Error: Invalid seat number!\n");
                    break;
                }
                int seatIdx = (r * 10) + c;
                if (isBooked[sIdx][seatIdx] == 0) {
                    printf("Error: Seat %c%d is not currently booked!\n", rowChar, colNum);
                } else {
                    int refunded = ticketPrice[sIdx][seatIdx];
                    isBooked[sIdx][seatIdx] = 0;
                    customerIDs[sIdx][seatIdx] = 0;
                    ticketPrice[sIdx][seatIdx] = 0;
                    printf("Success: Booking for Seat %c%d cancelled.\n", rowChar, colNum);
                    printf("Refunded Amount: Rs. %d\n", refunded);
                }
                break;
            }
            case 5: {
                int searchID;
                int found = 0;
                printf("\n--- Search Booking ---\n");
                printf("Enter Customer ID to Search: ");
                if (scanf("%d", &searchID) != 1) {
                    printf("Invalid Customer ID search query!\n");
                    while (getchar() != '\n');
                    break;
                }
                printf("\n============================================================\n");
                printf(" BOOKING DETAILS FOR CUSTOMER ID: %d\n", searchID);
                printf("============================================================\n");
                for (int s = 0; s < 6; s++) {
                    for (int seat = 0; seat < 50; seat++) {
                        if (isBooked[s][seat] == 1 && customerIDs[s][seat] == searchID) {
                            found = 1;
                            char rowChar = 'A' + (seat / 10);
                            int colNum = (seat % 10) + 1;
                            printf("Movie: %-12s | Time: %-8s | Seat: %c%-2d | Price: Rs. %d\n", movieTitles[s], showTimes[s], rowChar, colNum, ticketPrice[s][seat]);
                        }
                    }
                }
                if (!found) {
                    printf("No bookings found for Customer ID %d.\n", searchID);
                }
                printf("------------------------------------------------------------\n");
                break;
            }

            case 6: {
                int grandTotalRevenue = 0;
                int grandTotalTickets = 0;
                printf("\n========================================================================\n");
                printf(" CINEMA REVENUE REPORT \n");
                printf("========================================================================\n");
                printf("%-4s | %-12s | %-10s | %-14s | %-12s\n", "No.", "Movie", "Showtime", "Tickets Sold", "Revenue (Rs.)");
                printf("------------------------------------------------------------------------\n");
                for (int s = 0; s < 6; s++) {
                    int showRevenue = 0;
                    int showTickets = 0;
                    for (int seat = 0; seat < 50; seat++) {
                        if (isBooked[s][seat] == 1) {
                            showTickets++;
                            showRevenue += ticketPrice[s][seat];
                        }
                    }
                    grandTotalTickets += showTickets;
                    grandTotalRevenue += showRevenue;
                    printf("%-4d | %-12s | %-10s | %-14d | Rs. %-10d\n", s + 1, movieTitles[s], showTimes[s], showTickets, showRevenue);
                }
                printf("========================================================================\n");
                printf(" TOTAL TICKETS SOLD  : %d / 300\n", grandTotalTickets);
                printf(" TOTAL GROSS REVENUE : Rs. %d\n", grandTotalRevenue);
                printf("========================================================================\n");
                break;
            }

            case 7:
                printf("\nThank you for using the system. Goodbye!\n");
                return 0;

            default:
                printf("\nInvalid choice! Please enter a number between 1 and 7.\n");
        }
    }
    return 0;
}

