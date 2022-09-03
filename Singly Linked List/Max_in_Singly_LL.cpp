#include <iostream>
using namespace std;
// Code for finding the maximum element in a Singly Linked List.
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
// Function to find the maximum number in a Linked List (Iterative Sol)
// O(n) -> Time Complexity
int max_iterative()
{
    Node *n = first;
    int max = n -> data;

    while(n -> next != NULL)
    {
        if(n -> data > max)
            max = n -> data;
        
        n = n -> next;
    }

    return max;
}

// Fucntion to find the maximum number in a Linked List (Tail Recursive Sol)
// Time Complexity -> O(n)
// Space Complexity -> O(n)
int max_recursive(Node *n = first, int max = first -> data)
{
    if (n -> next == NULL)
        return max;
    
    else
    {
        if (max < n -> data)
            max = n -> data;
        
        max_recursive(n -> next, max);
    }
}

// Function to find the maximum number in Linked List (Head Recursive Sol)

int max_head_recursive(Node *n = first)
{
    int x = 0;

    if (n == 0)
        return INT32_MIN;
    
    x = max_head_recursive(n -> next);

    if(x > n -> data)
        return x;
    else
        return n -> data;
}



int main()
{
    int values[] = {-1,20,34,22,67,19,29,78,45};
    int number = 9;
    creation(values, number);
    cout << "Maximum number using Iterative Solution is " << max_iterative() << "." << endl;
    cout << "Maximum number using Tail Recursive Solution is " << max_recursive() << "." << endl;
    cout << "Maximum number using Head Recursive Solution is " << max_head_recursive() <<"." << endl;
    return 0;
}