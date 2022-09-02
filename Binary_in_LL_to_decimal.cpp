#include <iostream>
#include <cmath>
using namespace std;

struct Node
{
    int data;
    Node *next = NULL;
}*first, *last;

void creation(int values[], int number)
{
    first = new Node;
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
}

int binary_to_decimal(int number)
{
    Node *n = first;
    int length = number - 1;
    int decimal_number = 0;

    while(true)
    {
        if (n -> data == 1)
            decimal_number+=pow(2,length);

        if(n -> next == NULL)
            break;
        else
        {
            n = n -> next;
            length--;

        }
    }

    return decimal_number;
}

int main()
{
    int values[] = {1,0,1,1};
    creation(values, 4);
    cout << binary_to_decimal(4) << endl;
    return 0;
}