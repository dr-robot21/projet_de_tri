
#include <time.h>
#include "C:\Users\dell\Desktop\tri and sort algo\projet_de_tri\include\tri_rapide.h"
#include "C:\Users\dell\Desktop\tri and sort algo\projet_de_tri\include\tri_fusion.h"
#include "C:\Users\dell\Desktop\tri and sort algo\projet_de_tri\include\tri_tas.h"
#include "C:\Users\dell\Desktop\tri and sort algo\projet_de_tri\include\tri_Bulle.h"
#include "C:\Users\dell\Desktop\tri and sort algo\projet_de_tri\include\tri_Shell.h"
#include "C:\Users\dell\Desktop\tri and sort algo\projet_de_tri\include\utils.h"
#include <stdio.h>
#include <stdlib.h>



// échanger deux éléments d'un tableau
void swap(int *arr, int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

// afficher tout les elements d'une tableau
void printTab( int *arr , int n) {
    for (int i = 0; i < n; i++)
        printf("%10d",arr[i]);
    
    printf("\n");
}

// remplir un tableau avec des entiers aléatoires compris entre −MAX_SIZE/2 et +MAX_SIZE/2.
void genererValeurs( int *arr ,int MAX_SIZE){

    srand(time(NULL));

    for (int i = 0; i < MAX_SIZE; i++)
        arr[i] = (rand() % MAX_SIZE) - (MAX_SIZE/2);
    
}

// Crée un fichier binaire et remplit avec les valeurs de arr (int)
void cree_fichierInt( const char *file,int *arr ,const int n){

    FILE *f = fopen(file,"wb");

    if(!f) {
        perror("fopen");
        exit(1);
    }

    for (int i = 0; i < n; i++)
        fwrite(arr + i,sizeof(int),1,f);
    
    fclose(f);

    printf("%d entiers enregistrés dans %s \n",n,file);
}


// Crée un fichier binaire et remplit avec les valeurs de arr (double)
void cree_fichierDouble( const char *file,double *arr ,const int n){

    FILE *f = fopen(file,"wb");

    if(!f) {
        perror("fopen");
        exit(1);
    }

    for (int i = 0; i < n; i++)
        fwrite(arr + i,sizeof(double),1,f);
    
    fclose(f);

    printf("%d nombres reels enregistrés dans %s \n",n,file);
}


int* lire_fichierInt(const char *file,const int n) {

    FILE *f = fopen(file,"rb");

    if(!f) {
        perror("fopen");
        exit(1);
    }

    int *arr = (int*)malloc(n * sizeof(int));

    if(!arr) {
        perror("malloc");
        fclose(f);
        exit(1);
    }

    size_t lire = fread(arr,sizeof(int),n,f);

    if(lire != n) {
        perror("Le fichier ne contient pas suffisamment d'entiers.");
        exit(1);
    }

    printf("%d entiers chargés depuis %s \n",n,file);

    return arr;

}


double* lire_fichierDouble(const char *file,const int n) {

    FILE *f = fopen(file,"rb");

    if(!f) {
        perror("fopen");
        exit(1);
    }

    double *arr = (double*)malloc(n * sizeof(double));

    if(!arr) {
        perror("malloc");
        fclose(f);
        exit(1);
    }

    size_t lire = fread(arr,sizeof(double),n,f);

    if(lire != n) {
        perror("Le fichier ne contient pas suffisamment d'entiers.");
        exit(1);
    }

    printf("%d nombres reels chargés depuis %s \n",n,file);

    return arr;

} 