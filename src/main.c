#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <tri_rapide.h>
#include <tri_fusion.h>
#include <tri_tas.h>
#include <utils.h>

#define MAX_SIZE 1000000
#define RSLT_SIZE 1000



void mesure_temps() {
    int *tab , k = 0;
    double results[RSLT_SIZE];

    
    for (int n = 1000; n <= MAX_SIZE; n += 1000)
    {
        // lire les donnes dans fichier nombres
        tab = lire_fichierInt("data/nombres.bin",n);
        // le temps avant le tri
        clock_t debut = clock();

        // votre algorithme de tri
        // n le nombre des element de tab
        tri_tas(tab,n);

        // le temps apres le tri
        clock_t fin = clock();

        // le temp de tri
        double time = (double)(fin -debut) / CLOCKS_PER_SEC;
    
        printf("n = %d , time : %fs\n",n,time);

        results[k++] = time;

        free(tab);
    }

    printf("last recorde : %f \n",results[RSLT_SIZE - 1]);

    // cree un fichier binaire contient les mesures
    cree_fichierDouble("data/tri_tas.bin",results,RSLT_SIZE);
}

void represGraph(const char *nomTri,double *donnesTri,int taille) {

    FILE *gp = popen("gnuplot -persistent", "w");

    if (gp == NULL) {
        printf("Error opening pipe to gnuplot.\n");
        exit(1);
    }

    fprintf(gp, "set terminal x11 size 1920,1080 font 'Arial-Bold,20'\n"); // full HD window
    // Le titre de graphe
    fprintf(gp, "set title 'Mesures de %s' font 'Arial-Bold,28'\n",nomTri);

    // Définir les axes
    fprintf(gp, "set xlabel 'Nombre d''elements (n)' font 'Arial-Bold,24'\n");
    fprintf(gp, "set ylabel 'Temps (secondes)' font 'Arial-Bold,24'\n");

    // Ajouter grid
    fprintf(gp, "set grid\n");
    fprintf(gp, "plot '-' using 1:2 with lines lw 2 lc rgb '#f94200ff' title '%s' 'Arial-Bold,22'\n",nomTri);




    // Send data (x y)

    for (int i = 0; i < taille; i++)
    {
        int x = (i+1)*1000;
        double y = donnesTri[i];
        fprintf(gp,"%d %f\n",x,y);
    }
    
    

    fprintf(gp, "e\n");  // fin de donnes

    fflush(gp);
    pclose(gp);
}


int main(int argc, char const *argv[])
{

    // mesure_temps();

    double *data = lire_fichierDouble("data/tri_tas.bin",RSLT_SIZE);
    printf("%f \n",data[RSLT_SIZE-1]); 

    // representaion graphique
    represGraph("Tri par tas",data,RSLT_SIZE);

    free(data);
    return 0;
}
