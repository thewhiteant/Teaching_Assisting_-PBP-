#include <stdio.h>
#include <string.h>

void Add_friend(char allwords[100][100], char name[], int ind) {
    strcpy(allwords[ind], name);
}

void remove_friend(char allwords[100][100], char name[], int *number_of_friends) {
    int i, found = 0;
    for (i = 0; i < *number_of_friends; i++) {
        if (strcmp(allwords[i], name) == 0) {
            found = 1;
            // Shift elements to the left to remove the friend
            for (int j = i; j < *number_of_friends - 1; j++) {
                strcpy(allwords[j], allwords[j + 1]);
            }
            (*number_of_friends)--;
            break;
        }
    }
    if (!found) {
        printf("%s is not in your friend list.\n", name);
    }
}

int is_he_friend(char allwords[100][100], char name[], int number_of_friends) {
    for (int i = 0; i < number_of_friends; i++) {
        if (strcmp(allwords[i], name) == 0) {
            return 1;
        }
    }
    return 0;
}

void display_friends(char allwords[100][100], int number_of_friends) {
    printf("Your Friends:\n");
    for (int i = 0; i < number_of_friends; i++) {
        printf("%d. %s\n", i + 1, allwords[i]);
    }
}

int main() {
    char allwords[100][100];
    int number_of_friends = 0;

    while (1) {
        printf("___Ganjni Project___\n");
        printf("1. Add Friend \n2. Search \n3. Tum Meri duman ho \n4. Display All Friends\nChoose: ");
        int n;
        scanf("%d", &n);

        char word[100];
        switch (n) {
            case 1:
                printf("Name: ");
                scanf("%s", word);
                Add_friend(allwords, word, number_of_friends);
                number_of_friends++;
                break;
            case 2:
                printf("Who: ");
                scanf("%s", word);
                if (is_he_friend(allwords, word, number_of_friends)) {
                    printf("Yes, %s is your friend.\n", word);
                } else {
                    printf("No, %s is not your friend.\n", word);
                }
                break;
            case 3:
                printf("Remove: ");
                scanf("%s", word);
                remove_friend(allwords, word, &number_of_friends);
                break;
            case 4:
                display_friends(allwords, number_of_friends);
                break;
            default:
                printf("Choose a valid option.\n");
                return 0;
        }
    }
    return 0;
}
