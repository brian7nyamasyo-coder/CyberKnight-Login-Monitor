
#include <stdio.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_LENGTH 50
#define MAX_ATTEMPTS 3

char usernames[MAX_USERS][MAX_LENGTH];
char passwords[MAX_USERS][MAX_LENGTH];

int failedAttempts[MAX_USERS] = {0};
int locked[MAX_USERS] = {0};

int userCount = 0;
int totalLogins = 0;
int successfulLogins = 0;
int failedLogins = 0;

// Function declarations
void displayBanner();
void displayMenu();
void registerUser();
void loginUser();
void securityReport();
void aboutSystem();

int main() {

    int choice;
    int running = 1;

    displayBanner();

    while (running) {

        displayMenu();

        printf("\nSelect option: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {

            case 1:
                registerUser();
                break;

            case 2:
                loginUser();
                break;

            case 3:
                securityReport();
                break;

            case 4:
                aboutSystem();
                break;

            case 5:
                running = 0;
                printf("\nShutting down CyberKnight...\n");
                break;

            default:
                printf("\nInvalid option!\n");
        }
    }

    return 0;
}

// Display banner
void displayBanner() {

    printf("\n====================================\n");
    printf("       CYBERKNIGHT SECURITY\n");
    printf("          LOGIN MONITOR\n");
    printf("====================================\n");

}

// Display menu
void displayMenu() {

    printf("\n============ MAIN MENU ============\n");
    printf("1. Register User\n");
    printf("2. Login\n");
    printf("3. Security Report\n");
    printf("4. About System\n");
    printf("5. Exit\n");
    printf("===================================\n");

}

// Register user
void registerUser() {

    char username[MAX_LENGTH];
    char password[MAX_LENGTH];

    if (userCount >= MAX_USERS) {
        printf("\nMaximum users reached!\n");
        return;
    }

    printf("\n--- USER REGISTRATION ---\n");

    printf("Enter username: ");
    scanf("%49s", username);

    for (int i = 0; i < userCount; i++) {

        if (strcmp(usernames[i], username) == 0) {
            printf("\nUsername already exists!\n");
            return;
        }
    }

    printf("Enter password: ");
    scanf("%49s", password);

    strcpy(usernames[userCount], username);
    strcpy(passwords[userCount], password);

    failedAttempts[userCount] = 0;
    locked[userCount] = 0;

    userCount++;

    printf("\nRegistration successful!\n");

}

// Login system
void loginUser() {

    char username[MAX_LENGTH];
    char password[MAX_LENGTH];

    int found = -1;

    printf("\n--- USER LOGIN ---\n");

    printf("Username: ");
    scanf("%49s", username);

    for (int i = 0; i < userCount; i++) {

        if (strcmp(usernames[i], username) == 0) {
            found = i;
            break;
        }
    }

    if (found == -1) {

        printf("\nUnknown username!\n");
        failedLogins++;
        totalLogins++;
        return;
    }

    if (locked[found]) {

        printf("\nACCOUNT LOCKED!\n");
        printf("Contact the system administrator.\n");
        return;
    }

    printf("Password: ");
    scanf("%49s", password);

    totalLogins++;

    if (strcmp(passwords[found], password) == 0) {

        printf("\nLOGIN SUCCESSFUL!\n");
        printf("Welcome, %s!\n", usernames[found]);

        failedAttempts[found] = 0;
        successfulLogins++;

    } else {

        printf("\nINCORRECT PASSWORD!\n");

        failedAttempts[found]++;
        failedLogins++;

        printf("Failed attempts: %d/%d\n",
               failedAttempts[found], MAX_ATTEMPTS);

        if (failedAttempts[found] >= MAX_ATTEMPTS) {

            locked[found] = 1;

            printf("\nSECURITY ALERT!\n");
            printf("Account locked due to repeated failures.\n");

        }
    }
}

// Security report
void securityReport() {

    printf("\n======= SECURITY REPORT =======\n");

    printf("Registered users: %d\n", userCount);
    printf("Total login attempts: %d\n", totalLogins);
    printf("Successful logins: %d\n", successfulLogins);
    printf("Failed logins: %d\n", failedLogins);

    printf("\n--- ACCOUNT STATUS ---\n");

    for (int i = 0; i < userCount; i++) {

        printf("\nUsername: %s\n", usernames[i]);

        if (locked[i]) {
            printf("Status: LOCKED\n");
        } else {
            printf("Status: ACTIVE\n");
        }

        printf("Failed attempts: %d\n", failedAttempts[i]);

    }

    printf("\n===============================\n");

}

// About system
void aboutSystem() {

    printf("\n--- ABOUT CYBERKNIGHT ---\n");
    printf("Application: CyberKnight Security\n");
    printf("Version: 1.0\n");
    printf("Developer: CyberKnight Team\n");
    printf("Language: C\n");
    printf("Purpose: Simulated Login Monitoring\n");

}
