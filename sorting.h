/**
 *
 * Descripcion: Header file for sorting functions 
 *
 * Fichero: sorting.h
 * Autor: Carlos Aguirre
 * Version: 1.0
 * Fecha: 16-09-2019
 *
 */

#ifndef SORTING_H
#define SORTING_H

/* constants */

#ifndef ERR
  #define ERR -1
  #define OK (!(ERR))
#endif

/* type definitions */
typedef int (* pfunc_sort)(int*, int, int);

/* Functions */

int SelectSort(int* array, int ip, int iu);
int SelectSortInv(int* array, int ip, int iu);
int min(int* array, int ip, int iu, int *flag);


#endif
