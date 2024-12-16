#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_BLOCKS 5
#define BLOCK_SIZE 20

typedef struct Block {
    char data[BLOCK_SIZE];
    struct Block* next; 
} Block;

typedef struct File {
    char name[50];
    Block* head;
	} File;

File fileSystem[MAX_FILES];
int fileCount = 0;

void createFile(const char* name) {
    if (fileCount >= MAX_FILES) {
        printf("Maximum file limit reached. Cannot create more files.\n");
        return;
    }
    strcpy(fileSystem[fileCount].name, name);
    fileSystem[fileCount].head = NULL; // Initialize head to NULL
    fileCount++;
    printf("File '%s' created successfully.\n", name);
}

// Function to add a block to a file
void addBlock(const char* fileName, const char* data) {
    for (int i = 0; i < fileCount; i++) {
        if (strcmp(fileSystem[i].name, fileName) == 0) {
            Block* newBlock = (Block*)malloc(sizeof(Block));
            strcpy(newBlock->data, data);
            newBlock->next = NULL;

            // If the file is empty, set the new block as the head
            if (fileSystem[i].head == NULL) {
                fileSystem[i].head = newBlock;
            } else {
                // Traverse to the end of the linked list and add the new block
                Block* current = fileSystem[i].head;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = newBlock;
            }
            printf("Block added to file '%s'.\n", fileName);
            return;
        }
    }
    printf("File '%s' not found.\n", fileName);
}

// Function to display the contents of a file
void displayFile(const char* fileName) {
    for (int i = 0; i < fileCount; i++) {
        if (strcmp(fileSystem[i].name, fileName) == 0) {
            printf("Contents of file '%s':\n", fileName);
            Block* current = fileSystem[i].head;
            while (current != NULL) {
                printf("%s\n", current->data);
                current = current->next;
            }
            return;
        }
    }
    printf("File '%s' not found.\n", fileName);
}

// Function to delete a file
void deleteFile(const char* fileName) {
    for (int i = 0; i < fileCount; i++) {
        if (strcmp(fileSystem[i].name, fileName) == 0) {
            Block* current = fileSystem[i].head;
            while (current != NULL) {
                Block* temp = current;
                current = current->next;
                free(temp); // Free each block
            }
            // Remove the file from the file system
            for (int j = i; j < fileCount - 1; j++) {
                fileSystem[j] = fileSystem[j + 1];
            }
            fileCount--;
            printf("File '%s' deleted successfully.\n", fileName);
            return;
        }
    }
    printf("File '%s' not found.\n", fileName);
}

int main() {
    int choice;
    char fileName[50];
    char data[BLOCK_SIZE];

    while (1) {
        printf("\nLinked File Allocation Simulation:\n");
        printf("1. Create File\n");
        printf("2. Add Block to File\n");
        printf("3. Display File\n");
        printf("4. Delete File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter file name: ");
                fgets(fileName, sizeof(fileName), stdin);
                fileName[strcspn(fileName, "\n")] = 0; // Remove newline character
                createFile(fileName);
                break;
            case 2:
                printf("Enter file name: ");
                fgets(fileName, sizeof(fileName), stdin);
                fileName[strcspn(fileName, "\n")] = 0; // Remove newline character
                printf("Enter block data: ");
                fgets(data, sizeof(data), stdin);
                data[strcspn(data, "\n")] = 0; // Remove newline character
                addBlock(fileName, data);
                break;
            case 3:
                printf("Enter file name: ");
                fgets(fileName, sizeof(fileName), stdin);
                fileName[strcspn(fileName, "\n")] = 0; // Remove newline character
                displayFile(fileName);
                break;
            case 4:
                printf("Enter file name: ");
                fgets(fileName, sizeof(fileName), stdin);
                fileName[strcspn(fileName, "\n")] = 0; // Remove newline character
                deleteFile(fileName);
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
