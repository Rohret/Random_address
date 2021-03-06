#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "ran.h"

void printlist(struct Node *head)
{
   while (head != NULL)
   {
      printf("Random linked list: %d\n", head->address);
      head = head->next;
   }
}

void start_address(int arr_address[])
{
   struct Node *head = NULL;
   int k = 0, curr_k = 0;

   srand(time(NULL)); // Initialization, should only be called once.
   //int ran_arr_address[6]; //Måsta ha kvar den annars hänger det sig när jag kör programmet
   int deny_arr[6];
   for (int i = 0; i < 6; i++)
   {

      curr_k = k;
      k = shuffle(deny_arr, k, arr_address, &head);
      if (curr_k == k)
      {
         i--;
      }
   }
   printlist(head);
}

void add_new_node(struct Node **head, int address)
{

   struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
   struct Node *last = *head;

   new_node->address = address;
   new_node->next = NULL;

   if (*head == NULL)
   {

      *head = new_node;
      return;
   }

   while (last->next != NULL)
   {
      last = last->next;
   }

   last->next = new_node;
   return;
}

int shuffle(int *deny, int k, int *adress, struct Node **head)
{
   int r = ((rand() % 6));
   for (int i = 0; i < 6; i++)
   {
      if (r == *(deny + i))
      {
         return k;
      }
   }

   if (*(adress + r) != 0)
   {

      add_new_node(head, *(adress + r));
   }
   *(deny + k) = r;

   k++;
   return k;
}

void print_arr(int *deny)
{

   printf("\n");
   for (int i = 0; i < 6; i++)
   {

      printf("Deny: %d ", *(deny + i));
   }
   printf("\n");
}
