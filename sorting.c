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
int count = 0, ob = 0;

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
    return ob; 
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
  int i = ip, j = imedio+1, k = 0;

  if (!(t_aux = (int*)malloc(((iu-ip)+1)*sizeof(int))))
  {
    return ERR;
  }

  /*Coloca elementos*/
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

  /*Rellena elementos no colocados del array*/
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
      /*COMENTARIOS DE DEBUGEO:*/
      /*printf("\n%d - %d\n", tabla[i], k);*/
      t_aux[k] = tabla[i];
      i++;
      k++;
    }
  }

  /*COMENTARIOS DE DEBUEGEO:*/
  /*printf("\n-------------------------------------------------------------\nAntes de cambio:\n\n");
  printf("%d-%d\n\n", ip, iu);
  for (i = 0; i < max; i++)
  {
    printf("%d ", tabla[i]);
  }
  printf("\n\n");

  for (i = 0; i <= iu-ip; i++)
  {
    printf("%d ", t_aux[i]);
  }
  printf("\n\n");
  */

  for (i = ip, j = 0; i <= iu && j <= iu-ip; i++, j++)
  {
    tabla[i] = t_aux[j];
  }

  /*COMENTARIOS DE DEBUGEO:*/
  /*printf("Despues de cambio:\n\n");
  for (i = 0; i < max; i++)
  {
    printf("%d ", tabla[i]);
  }
  printf("\n\n");
  */

  free(t_aux);
  return ob;
}

int quicksort(int* tabla, int ip, int iu)
{
  int m= 0, ret = 0;

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
      ret=partition(tabla, ip, iu, &m); /*La m es el elemento medio despues de median, pero en partition cambia a la posicion inicial*/
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
  int k=0, aux=0, i, aux2=0, aux3=0, count = 0;

  /*Error control*/
  if(median(tabla, ip, iu, pos)!=0 || ip > iu || !tabla){
    return ERR;
  }

  /*K = primer elemento del trozo de tabla dado*/
  k=tabla[(*pos)];

  /*Cambia el valor del primer elemento de la tabla por el del ultimo*/
  aux = tabla[ip];
  tabla[ip]=tabla[(*pos)];
  tabla[(*pos)]= aux;

  (*pos)=ip;

  /*Empize a contar la tabla desde 0 aunque ip = 5? Siendo ip el indice del primer elemento a ordenar*/
  for(i=ip+1; i<= iu; i++){

    if(tabla[i]<k) /*Si la posicion comprobada es menor al valor de la posicion media*/
    {
      count++;
      (*pos)++;
      /*Hace un switch de la posicion comprobada pos+ 1*/
      aux2 = tabla[i];
      tabla[i]=tabla[(*pos)];
      tabla[(*pos)]= aux2;
    }
    /*Hace un switch del primer elemento por el elemento correspondiente a pos. Si se ha cumplido el if deshace lo anterior? Si no se ha cumplido el if cambia el valor de la primera posicion por el valor de la ¿primera posicion?*/
  }
    aux3 = tabla[ip];
    tabla[ip]=tabla[(*pos)];
    tabla[(*pos)]= aux3;

  return count;
}

int median(int *tabla, int ip, int iu,int *pos)
{
  /*Error control*/
  if(!tabla || ip > iu){
    return ERR;
  }

  /*Esto devueleve el valor del elemento medio de la tabla, no su indice. Está bien?*/
  (*pos)=ip;

  if(!pos)
  {
    return ERR;
  }

  return 0;
  
}
