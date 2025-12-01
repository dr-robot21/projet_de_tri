#include <tri_tas.h>
#include <utils.h>

// retourner l'indice d'enfant a gauche
int left_child(int pos) {
    return 2*pos + 1;
}

// retourner l'indice d'enfant a droit
int right_child(int pos) {
    return 2*pos + 2;
}

int max_child(int *arr, int n, int pos) {
    int l = left_child(pos);
    int r = right_child(pos);

    // Aucun enfant droit trouvé, retourner l’enfant gauche
    if(l < n && r >= n) return l;
    // Aucun enfant gauche trouvé, retourner l’enfant droit
    if(l >= n && r < n) return r;
    // S'il y a un enfant droit et un enfant gauche, retourner le maximum
    if(l < n && r < n) return arr[l] > arr[r] ? l : r;

    // S'il n'y a ni enfant droit ni enfant gauche
    return -1;
}


void heapify_down(int *arr, int n, int pos) {
    // sélectionner l'élément actuel
    int current = pos;

    while (1)
    {
        // Trouver l'enfant maximal
        int child = max_child(arr,n,current);

        // s'il n'existe pas, sortir de la boucle.
        if (child == -1)
            break;

        // comparer l'élément courant avec son plus grand enfant
        // s'il est plus petit, sortir de la boucle
        // sinon, échanger leurs valeurs dans le tableau principal.
        if(arr[current] < arr[child]) {
            swap(arr,current,child);
            current = child;
        }else
            break;
    }
}


// Transformer le tableau en un tas max.
void heapify(int *arr, int n) {
    // ignorer les feuilles ou la dernière partie de l'arbre
    int start = (n / 2) - 1;

    // Pour chaque élément, vérifier que le parent est supérieur à son enfants
    for (int i = start; i >= 0; i--)
        heapify_down(arr,n,i);
}

void tri_tas(int *arr, int n) {
    // Transformer le tableau en un tas max.
    heapify(arr,n);

    for (int end = n - 1; end >= 0; end--)
    {
        // Placer le maximum à la fin du tableau.
        swap( arr, 0, end);
        // Obtenir le nouveau maximum.
        heapify_down(arr,end,0);
    }
}