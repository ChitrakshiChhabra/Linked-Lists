#include <iostream>
using namespace std;
// The following Code is for removing sorted elements from Singly Linked List.
struct Node
{
    int data;
    Node *next = NULL;
}*first;

void creation(int values[], int number)
{
    Node *current_node, *previous_node;
    first = new Node;
    first -> data = values[0];
    previous_node = first;

    for (int i = 1; i < number; i++)
    {
        current_node = new Node;
        current_node -> data = values[i];
        previous_node -> next = current_node;
        previous_node = current_node;
    }

    cout << "Linked List Successfully Created." << endl;
}
void traversal()
{
    Node *n = new Node;
    n = first;

    while (true)
    {
        cout << n->data;
        if (n->next == NULL)
        {
            cout << endl;
            break;
        }
        else
        {
            cout << " -> ";
            n = n->next;
        }
    }
}
// Function for removing sorted elements.
// Created by the use of 2 pointers.
void remove_duplicates()
{
    Node *p, *q;
    p = first;

    while(p!= NULL)
    {
        if(p -> data == q -> data)
        {
           q -> next = p -> next;
           delete(p);
           p = q -> next;
        }
        else
        {
            q = p;
            p = p -> next;
        }
    }
}

int main()
{
    int values[] = {3,5,5,7,8,9,9,12,12,12,15};
    creation(values,11);
    traversal();
    remove_duplicates();
    traversal();
    return 0;
}
