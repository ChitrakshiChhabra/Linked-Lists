#include <iostream>
using namespace std;
// Creation of Node in a Linked List
struct Node
{
    int data;
    Node *next = NULL;

}*first = new Node,
 *last;

// Function to create the linked list.
void creation(int values[], int number)
{
    first -> data = values[0];
    Node *current_node, *previous_node;
    previous_node = first;

    for (int i = 1; i < number; i++)
    {
        current_node = new Node;
        current_node -> data = values[i];
        previous_node -> next = current_node;
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
        cout << n -> data;
        if (n -> next == NULL)
        {
            cout << endl;
            break;
        }
        else
        {
            cout << " -> ";
            n = n -> next;
        }
    }
}

// Function to insert a node/element in the beginning of the linked list.
void insert_in_beginning(int node_data)
{
    Node *new_first = new Node;
    new_first -> data = node_data;

    Node *old_first = first;
    first = new_first;
    first -> next = old_first;

    cout << "Element successfully inserted in the beginning of the Linked List." << endl;
}

// Function to insert a node/element at the end of the linked list.
void insert_in_the_end(int node_data)
{
    Node *new_end = new Node;
    new_end -> data = node_data;

    Node *old_end = last;
    last = new_end;
    old_end -> next = last;

    cout << "Element successfully inserted at the end of the Linked List." << endl;
    
}
// Function to insert a node/element at a position in a linked list
void insert_at_position(int position, int node_data)
{
    Node *new_between = new Node;
    new_between -> data = node_data;

    Node *pos = first;
    int counter = 1;

    while (true)
    {
        if (position == counter + 1)
            break;
        else
        {
            pos = pos -> next;
            counter+=1;
        }
    }

    Node *later;
    later = pos -> next;

    pos -> next = new_between;
    new_between -> next = later;

    cout << "Element successfully inserted at position " << position <<" in the Linked List." << endl;

}

// Function to delete a node in the beginning of the linked list.

void delete_in_beginning()
{
    Node *n = first -> next;
    first = n;

    cout << "Element successfully deleted in the beginning of the Linked List." << endl;
}

void delete_at_the_end()
{
    Node *p = first;
    while(true)
    {
        Node *r = p -> next;

        if (r -> next == NULL)
            break;
        else
            p = p -> next;
    }

    p -> next = NULL;
    last = p;

    cout << "Element successfully deleted at the end of the Linked List." << endl;
}

// Function to delete a node at a certain position in the Linked List.

void delete_at_position(int position)
{
    Node *before, *after;
    int counter = 1;
    before = first;

    while(true)
    {   
        if (counter + 1 == position)
        {
            Node *n = before -> next;
            after = n -> next;
            before -> next = after;
            break;
        }
        else
        {
            before = before -> next;
            counter+=1;

        }
        
    }

    cout << "Element successfully deleted at position " << position << " of Linked List." << endl;
}

// Function to count the number of nodes in a linked list

void number_of_nodes()
{
    Node *n = first;
    int count = 0;

    while(true)
    {
        count+=1;
        if(n -> next == NULL)
            break;
        else
            n = n -> next;
    }

    cout << "Number of nodes in the Linked List are " << count << "." << endl;
}






int main()
{
    int values[] = {1,2,3,4,5};
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

    return 0;
    
}