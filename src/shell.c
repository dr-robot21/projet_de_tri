#include "C:\Users\dell\Desktop\tri and sort algo\projet_de_tri\include\tri_rapide.h"
#include "C:\Users\dell\Desktop\tri and sort algo\projet_de_tri\include\tri_fusion.h"
#include "C:\Users\dell\Desktop\tri and sort algo\projet_de_tri\include\tri_tas.h"
#include "C:\Users\dell\Desktop\tri and sort algo\projet_de_tri\include\tri_Bulle.h"
#include "C:\Users\dell\Desktop\tri and sort algo\projet_de_tri\include\tri_Shell.h"
#include "C:\Users\dell\Desktop\tri and sort algo\projet_de_tri\include\utils.h"

#include <stdio.h>
#include <stdlib.h>

void shell_sort(int * arr, int n) {
    
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