#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 10
#define MAX_PAGES 100

// Function to simulate FIFO page replacement
void fifo(int pages[], int n, int frames) {
    int frame[MAX_FRAMES], pageFaults = 0, index = 0, i, j;
    int isPageInFrame;

    for (i = 0; i < frames; i++) {
        frame[i] = -1; // Initialize frames
    }

    for (i = 0; i < n; i++) {
        isPageInFrame = 0;

        // Check if page is already in frame
        for (j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                isPageInFrame = 1;
                break;
            }
        }

        // If page is not in frame, replace it
        if (!isPageInFrame) {
            frame[index] = pages[i];
            index = (index + 1) % frames; // Move to the next frame
            pageFaults++;
        }
    }

    printf("FIFO Page Faults: %d\n", pageFaults);
}

// Function to simulate LRU page replacement
void lru(int pages[], int n, int frames) {
    int frame[MAX_FRAMES], pageFaults = 0, i, j, k;
    int isPageInFrame;

    for (i = 0; i < frames; i++) {
        frame[i] = -1; // Initialize frames
    }

    for (i = 0; i < n; i++) {
        isPageInFrame = 0;

        // Check if page is already in frame
        for (j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                isPageInFrame = 1;
                break;
            }
        }

        // If page is not in frame, replace it
        if (!isPageInFrame) {
            int lruIndex = 0, lruPage = -1;

            // Find the least recently used page
            for (j = 0; j < frames; j++) {
                if (frame[j] == -1) {
                    lruIndex = j;
                    break;
                }
                for (k = i - 1; k >= 0; k--) {
                    if (frame[j] == pages[k]) {
                        if (k < lruPage || lruPage == -1) {
                            lruPage = k;
                            lruIndex = j;
                        }
                        break;
                    }
                }
            }

            frame[lruIndex] = pages[i];
            pageFaults++;
        }
    }

    printf("LRU Page Faults: %d\n", pageFaults);
}

int main() {
    int pages[MAX_PAGES], n, frames, i;

    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter the reference string (space-separated): ");
    for (i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }
    printf("Enter number of frames: ");
    scanf("%d", &frames);

    fifo(pages, n, frames);
    lru(pages, n, frames);

    return 0;
}
