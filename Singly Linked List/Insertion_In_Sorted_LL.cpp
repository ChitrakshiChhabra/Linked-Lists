#include <iostream>
using namespace std;

// Code for insertion in a Sorted Linked List.
// Here the Linked List will be sorted in ascending order.
// First function sorted_insertion() will be using 3 pointers.
// Second function sorted() will be using only 2 pointers.

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
// Insertion in a Sorted Linked List using 3 pointers.
void sorted_insertion(int key)
{
    Node *p, *q, *t;
    p = first;
    q = NULL;
    t = new Node;
    t -> data = key;
    // if key is smaller than the first node then insertion will be done in the beginning.
    if (key < first -> data)
    {
        t -> next = first;
        first = t;
    }
    else
    {
        // Insertion at a right position, including at the end.
        while(p!= NULL && p-> data < key)
        {
            q = p;
            p = p -> next;
        }

        
        t -> next = q -> next;
        q -> next = t;
    }

    }

// Insertion in Sorted Linked List using 2 pointers.
void sorted(int key)
{
    Node *p, *t;
    p = first;
    t = new Node;
    t -> data = key;
    // Insertion in beginning.
    if (key < first -> data)
    {
        t -> next = first;
        first = t;
    }

    else
    {
        while(p != NULL && p -> data < key)
        {  
            // Insertion at end for key greater than last node.
            if (p -> next == NULL && key > p -> data)
            {
                p -> next = t;
                break; 
            }
            // Insertion at the right position.
            if (p -> next -> data < key)
                p = p -> next;
            else
            {
                t -> next = p -> next;
                p -> next = t;
                break;
            } 
        }
    }
}
int main()
{
    int values[] = {3,7,13,19,22,34,57};
    int number = 7;
    
    creation(values, number);
    traversal();
    sorted_insertion(2);
    traversal();
    sorted(1);
    traversal();
    sorted(48);
    traversal();
    sorted(100);
    traversal();
    return 0;
}