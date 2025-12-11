#include <tri_shell.h>

void tri_shell(int * arr, int n) {
    
    for (int gap = n/2; gap > 0; gap /= 2) {

        // Faire insertion sort mais avec un gap
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;

            // Décaler les éléments du groupe
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            arr[j] = temp;
        }
    }
}