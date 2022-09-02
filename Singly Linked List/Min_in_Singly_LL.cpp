#include <iostream>
using namespace std;

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

// Function to find the minimum of a Linked List (Iterative Sol)
int min_iterative(Node *n = first)
{
    int min = n -> data;
    while( n -> next != NULL)
    {
        if (min > n -> data)
            min = n -> data;
        n = n -> next;
    }
    return min;
}



// Function to find the minimum of a Linked List (Tail Recursive Sol)
int min_tail_recursion(Node *n = first, int min = first -> data)
{
    if (n -> next == NULL)
        return min;
    if (n -> data < min)
        min = n -> data;

    min_tail_recursion(n -> next, min);
}

// Function to find the minimum of a Linked List (Head Recursive Sol)
int min_head_recursion(Node *n = first)
{
    int x = 0;
    if (n == 0)
        return INT32_MAX;

    x = min_head_recursion(n -> next);
    if (x < n -> data)
        return x;
    
    else
        return n -> data;
    
    
}

int main()
{
    int values[] = {-1,20,34,22,-10,67,19,29,78,45,-33,29,90};
    int number = 13;
    creation(values, number);
    cout << "Minimum number using Iterative Solution is " << min_iterative() << "." << endl;
    cout << "Minimum number using Tail Recursive Solution is " << min_tail_recursion() <<"." << endl;
    cout << "Minimum number using Head Recursive Solution is " << min_head_recursion() <<"." << endl;

    return 0;
}