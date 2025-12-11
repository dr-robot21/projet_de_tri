#include "C:\Users\dell\Desktop\tri and sort algo\projet_de_tri\include\tri_rapide.h"
#include "C:\Users\dell\Desktop\tri and sort algo\projet_de_tri\include\tri_fusion.h"
#include "C:\Users\dell\Desktop\tri and sort algo\projet_de_tri\include\tri_tas.h"
#include "C:\Users\dell\Desktop\tri and sort algo\projet_de_tri\include\tri_Bulle.h"
#include "C:\Users\dell\Desktop\tri and sort algo\projet_de_tri\include\tri_Shell.h"
#include "C:\Users\dell\Desktop\tri and sort algo\projet_de_tri\include\utils.h"


int partition(int *arr, int gauche, int droit) {
    int i = gauche - 1,
    j = gauche,
    pivot = arr[droit];

    for (j = gauche; j < droit; j++)
    {
        // Si l'élément courant est plus petit que le pivot
        // on l'échange avec l'élément à la position i+1
        if(arr[j] < pivot) 
            swap(arr,++i,j);
    }

    // Placer le pivot à sa position correcte
    swap(arr,++i,j); // j = droit (pivot)
    
    return i;
}


void tri_rapide(int *arr, int gouch, int droit) {
    if(gouch < droit){
        // Partitionner le tableau et obtenir la position du pivot
        int pivot = partition(arr,gouch,droit);

        // Trier récursivement les sous-tableaux à gauche et à droit du pivot
        tri_rapide(arr,gouch,pivot - 1);
        tri_rapide(arr,pivot + 1,droit);
    }
}
