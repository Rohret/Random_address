#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "ran.h"

int main()
{
    struct Node *head = NULL;
    int k = 0;
    int curr_k = 0;
    srand(time(NULL)); // Initialization, should only be called once.
    int arr_address[] = {10, 20, 30, 40, 50, 60};
    int ran_arr_address[6]; //Måsta ha kvar den annars hänger det sig när jag kör programmet
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

    //print_arr(deny_arr);
    printlist(head);
    return 0;
}