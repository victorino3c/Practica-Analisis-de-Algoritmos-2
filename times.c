/**
 *
 * Descripcion: Implementation of time measurement functions
 *
 * Fichero: times.c
 * Autor: Carlos Aguirre Maeso
 * Version: 1.0
 * Fecha: 16-09-2019
 *
 */

#include "times.h"
#include "sorting.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <limits.h>


/***************************************************/
/* Function: average_sorting_time Date: 23-09-2022 */
/*                                                 */
/* Your documentation                              */
/*metodo-->metodo de ordenacion que vas a probar; n_perms -->numero de elementos array; N--> numero de arrays; ptimes-->puntero donde guardas informacion*/
/***************************************************/
short average_sorting_time(pfunc_sort metodo, int n_perms,int N, PTIME_AA ptime)
{
  int **array = NULL; 
  double control = 0, accum_ob = 0, time = 0;
  int i;
  clock_t start, stop;

  if (n_perms < 0 || N < 0 || !metodo || !ptime)
  {
    return ERR;
  }

  if (!(array = generate_permutations(n_perms, N)))
  {
    return ERR;
  }

  ptime->N = N;
  ptime->n_elems = n_perms;
  ptime->time = 0;
  ptime->average_ob = 0;
  ptime->min_ob = INT_MAX;
  ptime->max_ob = 0;


  for (i = 0; i < n_perms; i++)
  {

    start = clock();
    control = (double)metodo(array[i], 0, N-1);
    stop = clock();

    time +=((double)(stop-start))/CLOCKS_PER_SEC;
    accum_ob += control;
  
    if (control < ptime->min_ob)
    {
      ptime->min_ob = control;
    }

    if (control > ptime->max_ob)
    {
      ptime->max_ob = control;
    }
  }

  ptime->time = (double)(time / n_perms);
  ptime->average_ob = (double)(accum_ob / n_perms); 


  for (i = 0; i < n_perms; i++)
  {
    free(array[i]);
  }
  free(array);


  return OK;

}

/***************************************************/
/* Function:generate_sorting_times Date: 23-09-2022*/
/*                                                 */
/* Your documentation                              */
/***************************************************/
short generate_sorting_times(pfunc_sort method, char* file, int num_min, int num_max, int incr, int n_perms)
{
  int i, j;
  PTIME_AA tiempos;
  short state = OK;
  
  if (!method || !file || num_max < num_min || num_min < 0 || incr <= 0 || n_perms < 0)
  {
    return ERR;
  }

  if ((tiempos = (PTIME_AA)malloc(((int)((num_max-num_min)/incr) + 1)*sizeof(TIME_AA))) == NULL)
  {
    return ERR;
  }

  for (j = num_min, i = 0; j <= num_max; j = j + incr, i++)
  {
    average_sorting_time(method, n_perms, j, &tiempos[i]);
  }

  state = save_time_table(file, tiempos, i);

  free(tiempos);

  return state;
  
}

/***************************************************/
/* Function: save_time_table Date: 23-09-2022      */
/*                                                 */
/* Your documentation                              */
/***************************************************/
short save_time_table(char* file, PTIME_AA ptime, int n_times)
{
  FILE *fil = NULL;
  int i = 0;

  if (!file || !ptime || n_times <= 0)
  {
    return ERR;
  }

  if ((fil = fopen(file, "w")) == NULL)
  {
    return ERR;
  }

  fprintf(fil, "Tamaño | Tiempo de ejecución | PromedioOB | Min_OB | Max_OB\n");

  for (i = 0; i < n_times; i++)
  {
    fprintf(fil, "  %.3d         %E          %1.3f       %d        %d\n", ptime[i].N, ptime[i].time, ptime[i].average_ob, ptime[i].min_ob, ptime[i].max_ob);
  }

  fclose(fil);

  return OK;

}
