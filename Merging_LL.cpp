#include <iostream>
using namespace std;
// This code is for merging 2 sorted Linked Lists.
// eg --
// List 1   10 -> 30 -> 50 -> 70 -> NULL
// List 2   20 -> 40 -> 60 -> 80 -> NULL
// Merged result will be  10 -> 20 -> 30 -> 40 -> 50 -> 60 -> 70 -> 80 -> NULL
// Approach to this would be --
// There are 2 pointers third and last
// third will be pointing to the first element of the merged Linked List.
// last will be pointed at the current last element.
// eg -
// first
//   |
//   V
//   2 -> 8 -> 10 -> 15
//   4 -> 7 -> 12 -> 14
//   ^
//   |
// second
// Comparing both first and second data, we see first is lesser than second.
// So, first will become the first node of the merged list, hence third will be moved to first.
// The current last node of the merged list is first only, so last pointer will also move to first.
// Hence the scenario is like this -->
// first, last, third (all are on first)
//                  |
//                  V
//                  2 -> 8 -> 10 -> 15
//                  4 -> 7 -> 12 -> 14
//                  ^
//                  |
//                second
// We will now move first to first -> next and set last -> next = NULL
// first now points to 8.
// Comparing first and second again i.e. comaparing 4 and 8, we find that this time second(4) is smaller.
// Then making last -> next = second, last = second, second = second -> next, last -> next = NULL
// So the scenario will look like --
//               third  first
//                  |    |
//                  V    V
//                  2    8 -> 10 -> 15
//                  |
//                  V
//          NULL <- 4    7 -> 12 -> 14
//                  ^    ^
//                  |    |            
//                 last second
// Performung these steps we loop until either first or second becomes null.
// Later we just concatenate the remaning elements of the bigger list with the merged list.
struct Node
{
    int data;
    Node *next = NULL;
}*first = NULL, *second = NULL, *third = NULL, *last = NULL;

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

Node *merge(Node *p, Node *q)
{
    if (p -> data < q -> data)
    {
        third = last = p;
        p = p -> next;
    }
    else
    {
        third = last = q;
        q = q -> next;
    }

    last -> next = NULL;

    while(p != NULL && q != NULL)
    {
        if (p -> data < q -> data)
        {
            last -> next = p;
            last = p;
            p = p -> next;  
        }
        else
        {
            last -> next = q;
            last = q;
            q = q -> next;
        }

        last -> next = NULL;
    }

    if (p != NULL)
        last -> next = p;

    if (q != NULL)
        last -> next = q;
    
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
    cout << "After Merging the two Linked Lists into one --  ";
    Node*p = merge(first, second);
    traversal(p);

    return 0;
}