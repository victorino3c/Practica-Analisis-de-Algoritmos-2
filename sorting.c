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

int mergesort(int* tabla, int ip, int iu)
{
  int m;

  if (ip > iu)
  {
    return ERR;
  } 
  if (ip == iu)
  {
    return ob; /*Devolver variable de ob*/
  } else 
  {
    m = (ip+iu)/2;
    mergesort(tabla, ip, m);
    mergesort(tabla, m+1, iu);

    return merge(tabla, ip, iu, m);
  }
}

int merge(int* tabla, int ip, int iu, int imedio)
{
  int *t_aux = NULL;
  int i = ip, j = imedio+1, k = ip;

  printf("%d-%d\n\n", iu, ip);
  if (!(t_aux = (int*)malloc(((iu-ip)+1)*sizeof(int))))
  {
    return ERR;
  }
  printf("2\n\n");

  while (i <= imedio && j <= iu)
  {
    ob++;
    if (tabla[i] < tabla[j])
    {
      t_aux[k] = tabla[i];
      i++;
    } else 
    {
      t_aux[k] = tabla[j];
      j++;
    }

    k++;
  }

  if (i > imedio)
  {
    while (j <= iu)
    {
      t_aux[k] = tabla[j];
      j++;
      k++;
    }
  } else if (j > iu)
  {
    while (i <= imedio)
    {
      t_aux[k] = tabla[i];
      i++;
      k++;
    }
  }

  for (i = ip; i <= iu; i++)
  {
    tabla[i] = t_aux[i]; /*Sumarle imedio cuando mitad derecha? mas opciones*/
  }

  free(t_aux);
  return ob;
  /*Cuando copiamos variables la posicion de tabla no se corresponde con la de la tabla auxiliar, ip puede ser 5 y en la auxiliar es 0*/
}

int quicksort(int* tabla, int ip, int iu)
{
  int m= 0, count=0, ret=0;
  /*Control Error*/
  if((ip > iu) || !tabla)
  {
    return ERR;
  }

  if(ip==iu)
  {
    return count;
  }

    else
    {
      ret=partition(tabla, ip, iu, &m);
      if(ret!= (-1))
      {
        count+=ret;
      }
      else{
        return ERR;
      }
      
      if(ip < m-1)
      {
        quicksort(tabla,ip, m-1);
      }
      if(m+1 < iu)
      {
        quicksort(tabla, m+1, iu);
      }
    }
  return count;

}

int partition(int* tabla, int ip, int iu,int *pos)
{
  int k=0, aux=0, i, aux2=0, aux3=0, count=0;

  if(median(tabla, ip, iu, pos)!=0){
    return ERR;
  }

  if((ip > iu) || !tabla)
  {
    return ERR;
  }

  k=tabla[(*pos)];

  aux = tabla[ip];
  tabla[ip]=tabla[iu];
  tabla[iu]= aux;

  (*pos)=ip;

  for(i=0; i<= (ip+1); i++){
    if(tabla[i]<k)
    {
      (*pos)++;
      aux2 = tabla[i];
      tabla[i]=tabla[(*pos)];
      tabla[(*pos)]= aux2;
    }
    aux3 = tabla[ip];
    tabla[ip]=tabla[(*pos)];
    tabla[(*pos)]= aux3;
    count++;
  }
  return count;
}

int median(int *tabla, int ip, int iu,int *pos)
{
  (*pos)=0;
  if(!tabla){
    return ERR;
  }

   if(ip > iu)
  {
    return ERR;
  }

  (*pos)=tabla[(ip+iu)/2];

  if(!pos)
  {
    return ERR;
  }

  return 0;
  
}

