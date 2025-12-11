// include/utils.h

#ifndef UTILS_H
#define UTILS_H

void swap( int *arr, int i, int j);

void printTab( int *arr , int n);

void cree_fichierInt( const char *file,int *arr ,const int n);

void cree_fichierDouble( const char *file,double *arr ,const int n);

int* lire_fichierInt(const char *file,const int n);
void cree_ficherTxt(const char * file  , const int taille , const double temp  )  ;

double* lire_fichierDouble(const char *file,const int n);

void genererValeurs( int *arr, int MAX_SIZE);



#endif // UTILS_H