#include <iostream>
using namespace std;
// This code is for performing the concatenation of 2 Linked Lists.
// eg --> 
// List 1   10 -> 30 -> 50 -> 70 -> NULL
// List 2   20 -> 40 -> 60 -> 80 -> NULL
// Concatenated result will be  10 -> 30 -> 50 -> 70 -> 20 -> 40 -> 60 -> 80 -> NULL
struct Node
{
    int data;
    Node *next = NULL;
}*first = NULL, *second = NULL, *third = NULL;

void creation1(int values[], int number)
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

    cout << "First Linked List Successfully Created." << endl;
}
void creation2(int values[], int number)
{
    Node *current_node, *previous_node;
    second = new Node;
    second -> data = values[0];
    previous_node = second;

    for (int i = 1; i < number; i++)
    {
        current_node = new Node;
        current_node -> data = values[i];
        previous_node -> next = current_node;
        previous_node = current_node;
    }

    cout << "Second Linked List Successfully Created." << endl;
}
void traversal(Node *n)
{
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

Node *concatenate(Node *p, Node *q)
{
    third = p;
    while(p -> next != NULL)
    {
        p = p -> next;
    }

    p -> next = q;
    q = NULL;
    return third;
}

int main()
{
    int values1[] = {2,8,10,15};
    int values2[] = {4,7,12,14};
    creation1(values1, 4);
    creation2(values2, 4);
    traversal(first);
    traversal(second);
    cout << "Concatenating the two Linked Lists into one -- ";
    traversal(concatenate(second, first));
    

    return 0;
}