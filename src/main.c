#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <tri_rapide.h>
#include <tri_fusion.h>
#include <tri_tas.h>
#include <tri_shell.h>
#include <tri_bulle.h>
#include <tri_insertion.h>
#include <tri_selection.h>
#include <utils.h>

#define MAX_SIZE 100000
#define RSLT_SIZE 100
#define NOMBRE_TRI 7



void mesure_temps() {
    int *tab , k = 0;
    double results[RSLT_SIZE];
    
    for (int n = 1000; n <= MAX_SIZE; n += 1000)
    {
        // lire les donnes dans fichier nombres.bin
        tab = lire_fichierInt("data/nombres.bin",n);
        // le temps avant le tri
        clock_t debut = clock();

        // votre algorithme de tri
        // n le nombre des element de tab
        tri_shell(tab,n);

        // le temps apres le tri
        clock_t fin = clock();

        // le temp de tri
        double time = (double)(fin - debut) / CLOCKS_PER_SEC;
    
        printf("n = %d , time : %fs\n",n,time);

        results[k++] = time;

        free(tab);
    }

    printf("last recorde : %f \n",results[RSLT_SIZE - 1]);

    // cree un fichier binaire contient les mesures
    cree_fichierDouble("data/tri_shell.bin",results,RSLT_SIZE);
}

void represGraph(const char **nomsTri, double **donnesTri, int nbCourbes, int taille) {

    FILE *gp = popen("gnuplot -persistent", "w");

    if (gp == NULL) {
        printf("Error opening pipe to gnuplot.\n");
        exit(1);
    }

    fprintf(gp, "set terminal x11 size 1920,1080 enhanced font 'Arial-Bold,20'\n"); // full HD window
    
    // Le titre de graphe avec fond et bordure
    fprintf(gp, "set title 'Comparaison des algorithmes de tri' font 'Arial-Bold,30' textcolor rgb '#000000'\n");

    // Définir les axes avec fond
    fprintf(gp, "set xlabel 'Nombre d''elements (n)' font 'Arial-Bold,28' textcolor rgb '#000000' offset 0,0.5\n");
    fprintf(gp, "set ylabel 'Temps (secondes)' font 'Arial-Bold,28' textcolor rgb '#000000' offset 2,0\n");

    // Améliorer la grille
    fprintf(gp, "set grid linewidth 2 linetype -1 linecolor rgb '#D0D0D0'\n");
    
    // Légende plus visible avec fond et bordure
    fprintf(gp, "set key top left box opaque\n");
    fprintf(gp, "set key font 'Arial-Bold,24'\n");
    fprintf(gp, "set key width 2 height 1\n");
    fprintf(gp, "set key textcolor rgb '#000000'\n");
    fprintf(gp, "set key box linewidth 3 linecolor rgb '#000000' fillcolor rgb '#FFFFFF'\n");
    fprintf(gp, "set key spacing 1.5\n");
    fprintf(gp, "set key samplen 4\n");

    // Ajouter grid
    fprintf(gp, "set grid\n");
    
    // Couleurs pour les courbes
    const char *colors[] = {"'#f99900'", "'#0066cc'", "'#00cc66'", "'#cc00cc'", "'#ffcc00'", "'#00cccc'","'#cc0000'"};
    
    // Préparer la commande plot
    fprintf(gp, "plot ");
    for (int c = 0; c < nbCourbes; c++) {
        fprintf(gp, "'-' using 1:2 with lines lw 3 lc rgb %s title '%s'", 
                colors[c % 6], nomsTri[c]);
        if (c < nbCourbes - 1) {
            fprintf(gp, ", \\\n     "); // continue on next line
        } else {
            fprintf(gp, "\n"); // end of plot command
        }
    }

    // Envoyer les données pour chaque courbe
    for (int c = 0; c < nbCourbes; c++) {
        for (int i = 0; i < taille; i++) {
            int x = (i+1)*1000;
            double y = donnesTri[c][i];
            fprintf(gp, "%d %f\n", x, y);
        }
        fprintf(gp, "e\n");  // fin de données pour cette courbe
    }

    fflush(gp);
    pclose(gp);
}

int main(int argc, char const *argv[])
{

    // charges les mesures depuis les fichiers
    double *tri_rapide_mesures = lire_fichierDouble("data/tri_rapide.bin",RSLT_SIZE);
    double *tri_tas_mesures = lire_fichierDouble("data/tri_tas.bin",RSLT_SIZE);
    double *tri_fusion_mesures = lire_fichierDouble("data/tri_fusion.bin",RSLT_SIZE);
    double *tri_bulle_mesures = lire_fichierDouble("data/tri_bulle.bin",RSLT_SIZE);
    double *tri_selection_mesures = lire_fichierDouble("data/tri_selection.bin",RSLT_SIZE);
    double *tri_insertion_mesures = lire_fichierDouble("data/tri_insertion.bin",RSLT_SIZE);
    double *tri_shell_mesures = lire_fichierDouble("data/tri_shell.bin",RSLT_SIZE);
    
    double *donnesTri[NOMBRE_TRI];
    
    donnesTri[0] = tri_rapide_mesures;
    donnesTri[1] = tri_tas_mesures;
    donnesTri[2] = tri_fusion_mesures;
    donnesTri[3] = tri_bulle_mesures;
    donnesTri[4] = tri_selection_mesures;
    donnesTri[5] = tri_insertion_mesures;
    donnesTri[6] = tri_shell_mesures;

    const char *nomsTri[NOMBRE_TRI] = {
        "rapide",
        "tas",
        "fusion",
        "bulles",
        "selection",
        "insertion",
        "shell"
    };


    // representer tout les mesures dans un seul graph
    represGraph(nomsTri,donnesTri,NOMBRE_TRI,RSLT_SIZE);

    for(int i = 0 ; i < NOMBRE_TRI ; i++)
        free(donnesTri[i]);

    return 0;
}
