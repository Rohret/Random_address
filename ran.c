#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int shuffle(int *ran_address, int *deny, int k, int *adress)
{

   int r = ((rand() % 6));
   for (int i = 0; i < 6; i++)
   {
      if (r == *(deny + i))
      {
         return k;
      }
   }

   if (*(adress + k) != 0)
   {
      *(ran_address + r) = *(adress + k);
      *(deny + k) = r;
   }
   k++;
   return k;
}

void print_arr(int *address, int *deny)
{

   for (int i = 0; i < 6; i++)
   {

      printf("Random Lista: %d ", *(address + i));
   }
   printf("\n");
   for (int i = 0; i < 6; i++)
   {

      printf("Deny: %d ", *(deny + i));
   }
   printf("\n");
}

int main()
{
   int k = 0;
   int curr_k = 0;
   srand(time(NULL)); // Initialization, should only be called once.
   int arr_address[] = {10, 20, 0, 0, 50, 60};
   int ran_arr_address[6];
   int deny_arr[6];
   for (int i = 0; i < 6; i++)
   {
      curr_k = k;
      k = shuffle(ran_arr_address, deny_arr, k, arr_address);
      if (curr_k == k)
      {
         i--;
      }
   }

   print_arr(ran_arr_address, deny_arr);
   return 0;
}