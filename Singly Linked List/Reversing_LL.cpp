#include <iostream>
using namespace std;
// This code is used for reversing a Linked List.
// Majourly we can reverse a Linked List by the help of 2 methods
// Reversing just the data of the Linked List.
// Reversing the links of nodes in the Linked List. (Better Method)
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
// Reversal using auxilliary array.
// Not a good method.
void reversing_elements(int number)
{
    int A[number];
    Node *p = first;
    int i = 0;

    while(p!=NULL)
    {
        A[i] = p -> data;
        p = p -> next;
        i++;
    }
    i--;
    p = first;
    while(p!=NULL)
    {
        p -> data = A[i];
        p = p -> next;
        i--;
    }
}

/*
Sliding pointer concept
Consider the Linked List 1 -> 2 -> 3 -> 4 -> 5
Let's take 3 pointers p, q  and r where initially p = first; q, r = NULL

r = NULL, q = NULL p
                   |
                   v
                   1 -> 2 -> 3 -> 4 -> 5

Now, if r = q, q = p, p = p -> next then,
r = NULL q    p
         |    |
         V    V
         1 -> 2 -> 3 -> 4 -> 5

In this, if we implement q -> next = r (Reversing Links), then Linked List will look like -
r = NULL q     p
         |     |
         V     V
  NULL<- 1     2 -> 3 -> 4 -> 5

In the next iteration, the following would be the scenario
        r    q   p
        |    |   |
        V    V   V
NULL <- 1 <- 2   3 -> 4 -> 5

Then at the end,
                       r    q   p = NULL
                       |    |
                       V    V
NULL <- 1 <- 2 <- 3 <- 4 <- 5

Then we will make first = q;
*/

void reverse_by_sliding_pointers()
{
    Node *p, *q, *r;
    p = first;
    q, r = NULL;

    while(p != NULL)
    {
        r = q;
        q = p;
        p = p -> next;
        q -> next = r;
    }

    first = q;
}

// Reversing a Linked List by pointers

void reversal(Node *p = first, Node *q = NULL)
{
    if (p != NULL)
    {
        reversal(p -> next, p);
        p -> next = q;
    }
    else
    {
        first = q;
    }
}
int main()
{
    int values[] = {1,2,3,4,5};
    creation(values, 5);
    cout << "Before: ";
    traversal();
    // reversing_elements(5);
    reversal();
    cout << "After: ";
    traversal();
    cout << endl;
    return 0;
}