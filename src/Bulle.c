
#include <stdio.h>
#include <stdlib.h>
#include "C:\Users\dell\Desktop\tri and sort algo\projet_de_tri\include\tri_Bulle.h"
#include "C:\Users\dell\Desktop\tri and sort algo\projet_de_tri\include\utils.h"





void tri_bulle(int * arr , int n){
for(int i =0 ; i<n-1 ; i++){
    if(arr[i] > arr[i+1]){
        swap(arr , i , i+1) ;
    }
}
}


