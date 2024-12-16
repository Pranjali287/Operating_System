#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 50

typedef struct {
    char files[MAX_FILES][MAX_FILENAME_LENGTH];
    int fileCount;
} SingleLevelDirectory;

typedef struct {
    char directoryName[MAX_FILENAME_LENGTH];
    char files[MAX_FILES][MAX_FILENAME_LENGTH];
    int fileCount;
} TwoLevelDirectory;

// Function to simulate a single-level directory
void singleLevelDirectory() {
    SingleLevelDirectory dir;
    dir.fileCount = 0;
    int choice;
    char filename[MAX_FILENAME_LENGTH];

    while (1) {
        printf("\nSingle Level Directory:\n");
        printf("1. Create File\n");
        printf("2. List Files\n");
        printf("3. Delete File\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (dir.fileCount < MAX_FILES) {
                    printf("Enter filename to create: ");
                    scanf("%s", filename);
                    strcpy(dir.files[dir.fileCount], filename);
                    dir.fileCount++;
                    printf("File '%s' created.\n", filename);
                } else {
                    printf("Directory is full!\n");
                }
                break;
            case 2:
                printf("Files in the directory:\n");
                for (int i = 0; i < dir.fileCount; i++) {
                    printf("%s\n", dir.files[i]);
                }
                break;
            case 3:
                printf("Enter filename to delete: ");
                scanf("%s", filename);
                for (int i = 0; i < dir.fileCount; i++) {
                    if (strcmp(dir.files[i], filename) == 0) {
                        // Shift files to delete the specified file
                        for (int j = i; j < dir.fileCount - 1; j++) {
                            strcpy(dir.files[j], dir.files[j + 1]);
                        }
                        dir.fileCount--;
                        printf("File '%s' deleted.\n", filename);
                        break;
                    }
                }
                break;
            case 4:
                return;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

// Function to simulate a two-level directory
void twoLevelDirectory() {
    TwoLevelDirectory dir;
    dir.fileCount = 0;
    int choice;
    char filename[MAX_FILENAME_LENGTH];

    printf("Enter directory name: ");
    scanf("%s", dir.directoryName);

    while (1) {
        printf("\nTwo Level Directory (%s):\n", dir.directoryName);
        printf("1. Create File\n");
        printf("2. List Files\n");
        printf("3. Delete File\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (dir.fileCount < MAX_FILES) {
                    printf("Enter filename to create: ");
                    scanf("%s", filename);
                    strcpy(dir.files[dir.fileCount], filename);
                    dir.fileCount++;
                    printf("File '%s' created in directory '%s'.\n", filename, dir.directoryName);
                } else {
                    printf("Directory is full!\n");
                }
                break;
            case 2:
                printf("Files in the directory '%s':\n", dir.directoryName);
                for (int i = 0; i < dir.fileCount; i++) {
                    printf("%s\n", dir.files[i]);
                }
                break;
            case 3:
                printf("Enter filename to delete: ");
                scanf("%s", filename);
                for (int i = 0; i < dir.fileCount; i++) {
                    if (strcmp(dir.files[i], filename) == 0) {
                        // Shift files to delete the specified file
                        for (int j = i; j < dir.fileCount - 1; j++) {
                            strcpy(dir.files[j], dir.files[j + 1]);
                        }
                        dir.fileCount--;
                        printf("File '%s' deleted from directory '%s'.\n", filename, dir.directoryName);
                        break;
                    }
                }
                break;
            case 4:
                return;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nFile Organization Techniques:\n");
        printf ("1. Single Level Directory\n");
        printf("2. Two Level Directory\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                singleLevelDirectory();
                break;
            case 2:
                twoLevelDirectory();
                break;
            case 3:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
