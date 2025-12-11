#include <tri_selection.h>
#include <utils.h>

void tri_selection(int *arr ,int n) {
    int i, j, min;

    for (i = 0; i < n - 1; i++) {
        min = i;

        // chercher l’indice du minimum
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min])
                min = j;
        }

        // échanger
        swap(arr,i,min);
    }
}