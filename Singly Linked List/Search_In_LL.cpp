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

// Linear Search
// Function to Search an element in Linked List (Iterative Sol)
Node *search_iterative(int key, Node *n = first)
{
    while (n -> next != NULL)
    {
        if (key == n -> data)
            return n;
        else
            n = n -> next; 
    }

    return NULL;
}

// Function to Search an element in Linked List (Recursive Sol)
Node *search_recursive(int key, Node*n = first)
{
    if (n -> data == key)
        return n;
    
    if (n -> next == NULL)
        return NULL;
    
    search_recursive(key, n -> next);
}

void make_head(int key, Node *p = first)
{
    Node *q = NULL;
    while (p != NULL)
    {
        if (p -> data == key)
        {
            q -> next = p -> next;
            p -> next = first;
            first = p;
        }
        q = p;
        p = p -> next;
    }

}
int main()
{
    int values[] = {-1,20,34,22,-10,67,19,29,78,45,-33,29,90};
    int number = 13;
    creation(values, number);

    cout << "Recursive:" << search_recursive(45) << " Iterative:" << search_iterative(45) << endl;
    cout << "Recursive:" << search_recursive(100) << " Iterative:" << search_iterative(100) << endl;
    traversal();
    make_head(45);
    traversal();


   
    

    return 0;
}