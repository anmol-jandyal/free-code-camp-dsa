// we are creation linked list by insertion of node at the beginning and then printing it(traversing)
#include <iostream>

using namespace std;

struct node
{
    int data;   // it is used to store data
    node *link; // it is used to link to next node
};

// creating class that has the member related to linked list operation and 'node * head'
class linked_list
{
    node *head; // stores address of first node and the only way to traverse the list

    // operations
public:
    linked_list()
    {
        head = NULL; // initializing head with NULL as not pointed to any node initially
    }
    void insert_beginning(int);
    void display_list();
};

void linked_list::insert_beginning(int data)
{
    // this function used to put data at the beginning of the list;
    /*
    *  to insert the element we have three steps
    1. creating new node and storing its address to a ptr of node type (node *temp)
    2. in the link part of the new node we store the address of previous node address
    3. now linking head to new first node.
    */
    node *temp = new node{data, NULL}; // creating new node and initializing it simultanously
    temp->link = head;                 // storing address of first old node
    head = temp;
}

void linked_list::display_list()
{
    node *temp = head; // stroing address of first node in temp.
    cout << "\n\n THE ELEMENTS OF LINKED LIST:\n";
    while (temp->link != NULL)
    {
        cout << temp->data << "    ";
        temp = temp->link; // moving to next node
    }
    cout << temp->data; // it will print the value of last node as it is not printed in loop
}

int main()
{
    linked_list A; // 'A' represent obj that is used to perform operations on linked list

    int n = 0, data = 0;
    cout << "ENTER NO. OF NODE YOU WANT TO CREATE INITIALLY:";

again_n:
    cin >> n;
    if (n < 0)
    {
        goto again_n;
    }

    // it is used create linked list and putting values in it
    for (int i = 1; i <= n; i++)
    {
        cout << "\n enter data for " << i << " node: ";
        cin >> data;
        A.insert_beginning(data);
    }

    char choice{'\0'};

    do
    {

        cout << "\n\n1) to insert element at initial position\n";
        cout << "2) to print list:\n";
        cout << "e) to exit\n";

        cin >> choice;
        switch (choice)
        {
        case '1':
            cout << "enter element";
            cin >> data;
            A.insert_beginning(data);
            break;

        case '2':
            A.display_list();
            break;

        case 'e':
            // for exit
            break;

        default:
            cout << "enter choice carefully";
            break;
        }
    } while (choice != 'e');

    cout << "\n\nprogram ended";
    return 0;
}