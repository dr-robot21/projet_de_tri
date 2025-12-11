#include <tri_bulle.h>
#include <utils.h>





void tri_bulle(int * arr , int n){
    for(int i = 0 ; i < n ; i++){
        for (int j = 0; j < n - i - 1; j++)
        {
            /* code */
            if(arr[j] > arr[j+1]){
                swap(arr , j , j+1);
            }
        }
        
    }
}


