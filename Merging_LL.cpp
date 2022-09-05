#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next = NULL;
}*first = NULL, *second = NULL;

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

    cout << "Fisrt Linked List Successfully Created." << endl;
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

int main()
{
    int values1[] = {2,8,10,15};
    int values2[] = {4,7,12,14};
    creation1(values1, 4);
    creation2(values2, 4);
    traversal(first);
    traversal(second);

    return 0;
}