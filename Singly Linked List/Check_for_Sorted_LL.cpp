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

bool sorted_or_not()
{
    int num = INT32_MIN;
    Node *p = first;
    
    while(p!=NULL)
    {
        if(p -> data > num)
        {
            num = p -> data;
            p = p ->next;
        }
        else
            return false;
    }
    return true;
}


int main()
{
    //int values1[] = {1,12,18,22,45,67};
    int values2[] = {-1,20,34,22,-10,67,19,29,78,45,-33,29,90};
    //creation(values1,6);
    creation(values2,13);
    cout << "Array is sorted -- " << sorted_or_not() << endl;
    return 0;
}