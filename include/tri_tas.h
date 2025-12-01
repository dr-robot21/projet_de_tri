// include/tri_tas.h

#ifndef TRI_TAS_H
#define TRI_TAS_H


int left_child(int pos);

int right_child(int pos);

int max_child(int *arr, int n, int pos);

void heapify_down(int *arr, int n,int pos);

void heapify(int *arr,int n);

void tri_tas(int *arr, int n);

#endif // TRI_TAS_H