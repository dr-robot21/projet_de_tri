
#include <stdio.h>
#include <stdlib.h>
#include "C:\Users\dell\Desktop\tri and sort algo\projet_de_tri\include\tri_Bulle.h"
#include "C:\Users\dell\Desktop\tri and sort algo\projet_de_tri\include\utils.h"





void tri_bulle(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        // Chaque passe "fait remonter" le plus grand élément à la fin
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr, j, j + 1);
            }
        }
    }
}



