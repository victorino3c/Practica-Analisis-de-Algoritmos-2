/**
 *
 * Descripcion: Implementation of sorting functions
 *
 * Fichero: sorting.c
 * Autor: Carlos Aguirre
 * Version: 1.0
 * Fecha: 16-09-2019
 *
 */


#include "sorting.h"

/***************************************************/
/* Function: SelectSort    Date: 23-09-2022        */
/* Your comment                                    */
/***************************************************/
int SelectSort(int* array, int ip, int iu) 
{
  int i = ip, minimo= 0, swap = 0, flag = 0;

  if (!array || iu < ip)
  {
    return ERR;
  }

  for (i = ip; i <= iu-1; i++)
  {
    minimo = min(array, i, iu, &flag);
    swap = array[i];
    array[i] = array[minimo];
    array[minimo] = swap;
  }
  
    return flag;
}

int SelectSortInv(int* array, int ip, int iu)
{
    int i = ip, minimo= 0, swap = 0, flag = 0;

  if (!array || iu < ip)
  {
    return ERR;
  }

  for (i = iu; i >= ip-1; i--)
  {
    minimo = min(array, ip, i, &flag);
    swap = array[i];
    array[i] = array[minimo];
    array[minimo] = swap;
  }
  
    return flag;
}

int min(int* array, int ip, int iu, int *flag)
{
  int minimo=ip, j;

  if (!array || iu < ip)
  {
    return ERR;
  }

  for (j = ip+1; j <= iu; j++)
  {
    if (array[j] < array[minimo])
    {
      minimo= j;
      (*flag)++;
    }
  }
  return minimo;

}
