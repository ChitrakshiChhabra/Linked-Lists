#include <iostream>
using namespace std;
// This code focuses on the -
// Creation of Nodes using  C++ Structures.
// Creation of Linked Lists by taking array and array size as the input. Array contains all the elements of Linked List.
// Traversal of Linked List.(Recursive + Iterative)
// Insertion of new Nodes from Linked List (Beginning, End, Position).
// Deletion of new Node from Linked List (Beginning, End, Position).
// Counting the number of nodes in Linked List.
// Recursive sum of all elements in Linked List.

// Creation of Node in a Linked List
struct Node
{
    int data;
    Node *next = NULL;

} *first = new Node, *last;

// Function to create the linked list.
void creation(int values[], int number)
{
    first->data = values[0];
    Node *current_node, *previous_node;
    previous_node = first;

    for (int i = 1; i < number; i++)
    {
        current_node = new Node;
        current_node->data = values[i];
        previous_node->next = current_node;
        previous_node = current_node;
    }

    last = current_node;

    cout << "Linked List Succesfully Created." << endl;
}
// Function to traverse the entire linked list.
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

// Fucntion to display a Linked List using Recursion.

void recursive_display(Node *n = first)
{
    cout << n->data;

    if (n->next == NULL)
    {
        cout << endl;
        return;
    }
    else
    {
        cout << " -> ";
        recursive_display(n->next);
    }
}

// Function to insert a node/element in the beginning of the linked list.
void insert_in_beginning(int node_data)
{
    Node *new_first = new Node;
    new_first->data = node_data;
    new_first -> next = first;
    first = new_first;

    cout << "Element successfully inserted in the beginning of the Linked List." << endl;
}

// Function to insert a node/element at the end of the linked list.
void insert_in_the_end(int node_data)
{
    Node *new_end = new Node;
    new_end->data = node_data;
    last -> next = new_end;
    last = new_end;

    cout << "Element successfully inserted at the end of the Linked List." << endl;
}
// Function to insert a node/element at a position in a linked list
void insert_at_position(int position, int node_data)
{
    Node *new_between = new Node;
    new_between->data = node_data;

    Node *pos = first;
    int counter = 1;

    while (true)
    {
        if (position == counter + 1)
            break;
        else
        {
            pos = pos->next;
            counter += 1;
        }
    }
    new_between -> next = pos -> next;
    pos -> next = new_between;
    cout << "Element successfully inserted at position " << position << " in the Linked List." << endl;
}

// Function to delete a node in the beginning of the linked list.

void delete_in_beginning()
{
    Node *n = first;
    first = first -> next;
    delete n;

    cout << "Element successfully deleted in the beginning of the Linked List." << endl;
}

void delete_at_the_end()
{
    Node *p = first;
    Node *q;
    while (true)
    {
        if (p->next->next == NULL)
        {
            q = p -> next;
            break;
        }
        else
            p = p->next;
    }
    last = p;
    p -> next = NULL;
    delete(q);
    cout << "Element successfully deleted at the end of the Linked List." << endl;
}

// Function to delete a node at a certain position in the Linked List.

void delete_at_position(int position)
{
    Node *p, *q;
    int counter = 1;
    p = first;

    while (true)
    {
        if (counter + 1 == position)
        {
            q = p -> next;
            p -> next = q -> next;
            delete(q);
            break;
        }
        else
        {
            p = p ->next;
            counter += 1;
        }
    }

    cout << "Element successfully deleted at position " << position << " of Linked List." << endl;
}

// Function to count the number of nodes in a linked list

void number_of_nodes()
{
    Node *n = first;
    int count = 0;

    while (true)
    {
        count += 1;
        if (n->next == NULL)
            break;
        else
            n = n->next;
    }

    cout << "Number of nodes in the Linked List are " << count << "." << endl;
}

// Recursive sum of elements in a linked list

void recursive_sum(Node *n = first, int sum = 0)
{
    sum += n->data;

    if (n->next == NULL)
    {
        cout << "Sum of all elements is " << sum << "." << endl;
        return;
    }
    else
        recursive_sum(n->next, sum);
}

int main()
{
    int values[] = {1, 2, 3, 4, 5};
    int number = 5;

    creation(values, number);
    traversal();
    insert_in_beginning(0);
    traversal();
    insert_in_the_end(6);
    traversal();
    insert_at_position(3, -1);
    traversal();
    delete_in_beginning();
    traversal();
    delete_at_the_end();
    traversal();
    delete_at_position(3);
    traversal();
    number_of_nodes();
    recursive_display();
    recursive_sum();

    return 0;
}