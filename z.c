#include <stdio.h>

#define ERR -1
#define max 10

int quicksort(int* tabla, int ip, int iu);
int partition(int* tabla, int ip, int iu, int *m);
int median(int *tabla, int ip, int iu, int *pos);

int count = 0;

int main(void)
{
    int tabla[max] = {2,4,7,9,1,3,6,8,5};

    int i,j = 0, ret;

    /*
    for (i = max - 1; i >= 0; i--)
    {
        tabla[i] = j;
        j++;
    }

    for (i = 0; i < max; i++)
    {
        printf("%d ", tabla[i]);
    }
    */

    ret = quicksort(&tabla[0], 0, max-1);

    printf("\n\n%d\n\n", ret);

        for (i = 0; i < max; i++)
    {
        printf("%d ", tabla[i]);
    }
    printf("\n\n");

    return 0;
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
