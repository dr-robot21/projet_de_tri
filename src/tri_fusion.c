#include <tri_fusion.h>
#include <stdlib.h>
#include <string.h>


void fusion(int *arr, int gauche, int mid, int droit) {

    // determiner la taille de deux tableau temporaire
    int n1 = mid - gauche + 1;
    int n2 = droit - mid;

    // cree deux tableau temporaire
    int *L = (int *)malloc( n1 * sizeof(int) );
    int *R = (int *)malloc( n2 * sizeof(int) );

    // copy les valeur de arr dans les tableau temporaire L et R
    memcpy(L, arr + gauche, n1 * sizeof(int));
    memcpy(R, arr + mid + 1, n2 * sizeof(int));

    // initialiser les indices
    int i,j,k;
    i = j = 0;
    k = gauche;

    // Comparer l’élément à l’indice i avec l’élément à l’indice j, puis placer le plus petit dans le tableau principal à l’indice k
    while (i < n1 && j < n2)
    {
        if(L[i] < R[j]) 
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

void tri_fusion(int *arr, int gauche, int droit) { 
    if(gauche < droit) {

        // calculer le millieu de tableau
        int mid = (gauche + droit)/2;

        // decomposer le tableau
        tri_fusion(arr,gauche,mid);
        tri_fusion(arr,mid+1,droit);

        // fusionner le tableau
        fusion(arr,gauche,mid,droit);
    }
}