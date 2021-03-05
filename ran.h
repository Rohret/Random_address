#ifndef RAN_H
#define RAN_H

struct Node
{
    int address;
    struct Node *next;
};
void printlist(struct Node *head);
void add_new_node(struct Node **head, int address);
int shuffle(int *deny, int k, int *adress, struct Node **head);
void print_arr(int *deny);

#endif