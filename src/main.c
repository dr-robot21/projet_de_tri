#include <stdio.h>
#include <stdlib.h>
#include <windows.h> // pour QueryPerformanceCounter
#include "C:\Users\dell\Desktop\tri and sort algo\projet_de_tri\include\tri_rapide.h"
#include "C:\Users\dell\Desktop\tri and sort algo\projet_de_tri\include\tri_fusion.h"
#include "C:\Users\dell\Desktop\tri and sort algo\projet_de_tri\include\tri_tas.h"
#include "C:\Users\dell\Desktop\tri and sort algo\projet_de_tri\include\tri_Bulle.h"
#include "C:\Users\dell\Desktop\tri and sort algo\projet_de_tri\include\tri_Shell.h"
#include "C:\Users\dell\Desktop\tri and sort algo\projet_de_tri\include\utcils.h"


#define MAX_SIZE 100000   // taille max
#define FILE_NAME "C:/Users/dell/Desktop/tri and sort algo/projet_de_tri/data"

// fonction pour mesurer le temps d'exécution d'une fonction de tri
double mesure_temps(void (*tri)(int*, int), int* array, int taille) {
    LARGE_INTEGER frequency, start, end;
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);

    tri(array, taille);

    QueryPerformanceCounter(&end);
    return (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
}

// version spéciale pour les tris récursifs avec (array, debut, fin)
double mesure_temps_rec(void (*tri)(int*, int, int), int* array, int debut, int fin) {
    LARGE_INTEGER frequency, start, end;
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);

    tri(array, debut, fin);

    QueryPerformanceCounter(&end);
    return (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
}

// fonction pour écrire les résultats dans un fichier
void cree_fichierTxtMulti(const char *file, const int taille, 
                          double t_bulle, double t_shell, double t_fusion, 
                          double t_rapide, double t_tas) {
    FILE *f = fopen(file, "a");
    if (!f) { perror("fopen"); exit(1); }
    fprintf(f, "%d %lf %lf %lf %lf %lf\n", taille, t_bulle, t_shell, t_fusion, t_rapide, t_tas);
    fclose(f);
}

int main() {
    FILE *f = fopen(FILE_NAME, "w"); // vider le fichier au début
    if (!f) { perror("fopen"); exit(1); }
    fclose(f);

    int taille = 500;
    while (taille <= MAX_SIZE) {
        // allocation du tableau
        int *array = malloc(taille * sizeof(int));
        if (!array) { printf("Erreur d'allocation\n"); exit(1); }

        // remplir avec valeurs aléatoires
        genererValeurs(array, taille);

        // créer une copie pour chaque tri (pour ne pas trier un tableau déjà trié)
        int *arr_bulle   = malloc(taille * sizeof(int));
        int *arr_shell   = malloc(taille * sizeof(int));
        int *arr_fusion  = malloc(taille * sizeof(int));
        int *arr_rapide  = malloc(taille * sizeof(int));
        int *arr_tas     = malloc(taille * sizeof(int));

        for (int i = 0; i < taille; i++) {
            arr_bulle[i] = arr_shell[i] = arr_fusion[i] = arr_rapide[i] = arr_tas[i] = array[i];
        }

        // mesurer les temps
        double t_bulle  = mesure_temps(tri_bulle, arr_bulle, taille);
        double t_shell  = mesure_temps(shell_sort, arr_shell, taille);
        double t_fusion = mesure_temps_rec(tri_fusion, arr_fusion, 0, taille-1);
        double t_rapide = mesure_temps_rec(tri_rapide, arr_rapide, 0, taille-1);
        double t_tas    = mesure_temps(tri_tas, arr_tas, taille);

        // écrire dans le fichier
        cree_fichierTxtMulti(FILE_NAME, taille, t_bulle, t_shell, t_fusion, t_rapide, t_tas);

        // libérer mémoire
        free(array);
        free(arr_bulle);
        free(arr_shell);
        free(arr_fusion);
        free(arr_rapide);
        free(arr_tas);

        // augmenter taille
        if (taille < 5000) taille += 500;
        else if (taille < 50000) taille += 5000;
        else taille += 50000;
    }

    printf("Mesure des temps terminée. Données stockées dans %s\n", FILE_NAME);
    return 0;
}
