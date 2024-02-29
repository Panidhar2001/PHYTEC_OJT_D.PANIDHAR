#include <stdio.h>

typedef struct Transaction {
    char description[100];
    double amount;
    char type;  // 'I' for income, 'E' for expense
} Transaction;

#define MAX_TRANSACTIONS 100

Transaction transactions[MAX_TRANSACTIONS];
int numTransactions = 0;

void addTransaction() {
    if (numTransactions < MAX_TRANSACTIONS) {
        printf("Enter Description: ");
        getchar(); // Clear the newline character from the buffer
        fgets(transactions[numTransactions].description, sizeof(transactions[numTransactions].description), stdin);

        printf("Enter Amount: ");
        scanf("%lf", &transactions[numTransactions].amount);

        getchar(); // Clear the newline character from the buffer
        printf("Enter Type (I for Income, E for Expense): ");
        scanf(" %c", &transactions[numTransactions].type);

        numTransactions++;
        printf("Transaction added successfully!\n");
    } else {
        printf("Maximum capacity reached!\n");
    }
}

void displayTransactions() {
    printf("\nTransactions:\n");
    for (int i = 0; i < numTransactions; i++) {
        printf("%d. Description: %sAmount: %.2f Type: %c\n\n",
               i + 1, transactions[i].description, transactions[i].amount, transactions[i].type);
    }
}

double calculateBalance() {
    double balance = 0.0;
    for (int i = 0; i < numTransactions; i++) {
        if (transactions[i].type == 'I') {
            balance += transactions[i].amount;
        } else {
            balance -= transactions[i].amount;
        }
    }
    return balance;
}

int main() {
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Add Transaction\n");
        printf("2. Display Transactions\n");
        printf("3. Calculate Balance\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTransaction();
                break;
            case 2:
                displayTransactions();
                break;
            case 3:
                printf("Current Balance: %.2f\n", calculateBalance());
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

