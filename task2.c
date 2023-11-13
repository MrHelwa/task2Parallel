#include <stdio.h>
#include <string.h>

// Define user struct
struct User
{
    char name[20];
    char password[20];
};

// Define union with a struct containing a flag
union UserFlag
{
    struct
    {
        int flag;
    };
};

int main()
{
    // Define an array of user structs
    struct User users[5] = {
        {"user1", "pass1"},
        {"user2", "pass2"},
        {"user3", "pass3"},
        {"user4", "pass4"},
        {"user5", "pass5"}};

    // Define a union variable
    union UserFlag userFlag;

    // Prompt user for credentials
    char enteredName[20];
    char enteredPassword[20];

    printf("Enter your name: ");
    scanf("%s", enteredName);

    printf("Enter your password: ");
    scanf("%s", enteredPassword);

    // Check if entered credentials match any user
    int i;
    int found = 0;
    for (i = 0; i < 5; i++)
    {
        if (strcmp(enteredName, users[i].name) == 0 && strcmp(enteredPassword, users[i].password) == 0)
        {
            printf("Welcome back to the system, %s!\n", enteredName);
            found = 1;

            // Check the flag value in the union
            if (userFlag.flag == 0)
            {
                printf("User is not active.\n");
            }
            else if (userFlag.flag == 1)
            {
                printf("User is active.\n");
            }

            break;
        }
    }

    if (!found)
    {
        printf("Wrong username or password.\n");
    }
    printf("Press Enter to exit...");
    getchar();
    return 0;
}
