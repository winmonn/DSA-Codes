#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void heapify(char *arr[], int n, int i) {
    int greatest = i;

    while (1) {
        int LC = (i * 2) + 1;
        int RC = (i * 2) + 2;
        greatest = i;

        if (LC < n && strcmp(arr[LC], arr[greatest]) > 0) {
            greatest = LC;
        }
        if (RC < n && strcmp(arr[RC], arr[greatest]) > 0) {
            greatest = RC;
        }

        if (greatest != i) {
            char* temp = arr[i];
            arr[i] = arr[greatest];
            arr[greatest] = temp;

            i = greatest;
        } else {
            break;
        }
    }
}

void heapSort(char *arr[], int n) {
    int i;

    for (i = (n / 2) - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    while (n > 1) {
        char* temp = arr[0];
        arr[0] = arr[n - 1];
        arr[n - 1] = temp;

        n--;
        heapify(arr, n, 0);
    }
}
