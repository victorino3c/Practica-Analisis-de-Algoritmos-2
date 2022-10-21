/**
 *
 * Descripcion: Implementation of function that generate permutations
 *
 * File: permutations.c
 * Autor: Carlos Aguirre
 * Version: 1.1
 * Fecha: 21-09-2019
 *
 */


#include "permutations.h"
#include <stddef.h>
#include <stdlib.h>


/***************************************************/
/* Function: random_num Date:                      */
/* Authors: Antonio Van-Oers & Nicolas Victorino   */
/*                                                 */
/* Rutine that generates a random number           */
/* between two given numbers                       */
/*                                                 */
/* Input:                                          */
/* int inf: lower limit                            */
/* int sup: upper limit                            */
/* Output:                                         */
/* int: random number                              */
/***************************************************/
/*Idea alternativa:
Generar numeros aleatorios del 0 al sup, y si es menor que inf repetir el proceso. En caso de success devolver el numero generado
*/

int random_num(int inf, int sup)
{
  int res = inf;

  /*Error control*/
  if (sup < inf)
  {
    return ERR;
  }
  
  /*Random number generator
   * Given a inf value, we set a variable to that value, and 
   * we  add the random number (between 0 and the superior 
   * value minus the inferior value), so that the random number 
   * is always greater than inf
   */
  res += rand() % (sup - inf + 1); 

  return res;

}

/***************************************************/
/* Function: generate_perm Date:                   */
/* Authors: Antonio Van-Oers & Nicolas Victorino   */
/*                                                 */
/* Rutine that generates a random permutation      */
/*                                                 */
/* Input:                                          */
/* int n: number of elements in the permutation    */
/* Output:                                         */
/* int *: pointer to integer array                 */
/* that contains the permitation                   */
/* or NULL in case of error                        */
/***************************************************/

int* generate_perm(int N)
{
  int i, sust = 0, ran = 0;
  int *array;

  /*Error control*/
  if (N <= 0)
  {
    return NULL;
  }

  /*Dynamic memory allocation & error control*/
  if (!(array = (int *)malloc(sizeof(int) * N)))
  {
    return NULL;
  }

/*Introducing values to the array*/
  for (i = 0; i < N; i++)
  {
    array[i] = i + 1;
  }

  /*Permutations*/
  for (i = 0; i < N; i++) 
  {
    sust = array[i];
    ran = random_num(i, N - 1);
    array[i] = array[ran];
    array[ran] = sust;
  }
  
  return array;

}


/*
para i de 1 a N:
  perm[i] = i
para i de 1 a N:
  intercambiar perm[i] con perm[random_num(i, N)]
*/
/***************************************************/
/* Function: generate_permutations Date:           */
/* Authors: Antonio Van-Oers & Nicolas Victorino   */
/*                                                 */
/* Function that generates n_perms random          */
/* permutations with N elements                    */
/*                                                 */
/* Input:                                          */
/* int n_perms: Number of permutations             */
/* int N: Number of elements in each permutation   */
/* Output:                                         */
/* int**: Array of pointers to integer that point  */
/* to each of the permutations                     */
/* NULL en case of error                           */
/***************************************************/

int** generate_permutations(int n_perms, int N)
{
  int** ret = NULL;
  int i;

  if (n_perms <= 0 || N <= 0)
  {
    return NULL;
  }
  
  
  if (!(ret = (int**)malloc(sizeof(int*)*n_perms)))
  {
    return NULL;
  }

  for (i = 0; i < n_perms; i++)
  {
    ret[i] = generate_perm(N);
  }

  return ret;

}


