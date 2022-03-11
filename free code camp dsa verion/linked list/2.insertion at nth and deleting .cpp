#include <iostream>
using namespace std;

struct node
{
    int data;
    node *link;
};

class linked_list
{
    node *head; // points to first node
    int length;

public:
    linked_list()
    {
        head = NULL;
        length = 0;
    }
    void insert(int data, int index);
    void print();
    void reverse();
    void del(int index);
};
void linked_list::del(int index)
{
    if (index <= length && index > 0)
    {
        node *temp = head;

        if (index == 1)
        {
            head = temp->link;
            delete temp;
            temp = NULL;
        }
        else
        {
            node *temp1 = NULL;

            for (int i = 2; i < index; i++)
            {
                temp = temp->link;
            }
            // temp1 is pointing to the node to be deleted
            temp1 = temp->link;

            temp->link = temp1->link; // node to be deleted is disconnected from the list

            delete temp1;
        }

        length--;
    }
    else
    {
        cout << "index does not exist";
    }
}

void linked_list::reverse()
{
    node *prev = NULL, *cur = head, *nxt = cur->link;

    while (nxt != NULL)
    {
        cur->link = prev;
        prev = cur;
        cur = nxt;
        nxt = cur->link;
    }
    cur->link = prev;
    head = cur;
    cout << "\n\nlist is reversed";
}

void linked_list::insert(int data, int index = 1)
{
    if (index <= length + 1 && index > 0)
    {
        node *temp = new node{data, NULL};

        if (index == 1)
        {                      // inserting in beginning
            temp->link = head; // linking new node to old first node
            head = temp;       // head linked to new first node
        }
        else
        {
            node *temp_mov = head;

            for (int i = 2; i < index; i++) // it will move the temp_mov to the index -1 position
            {
                temp_mov = temp_mov->link;
            }

            temp->link = temp_mov->link;
            temp_mov->link = temp;
        }

        // one new node is added to the list so
        length++;

        temp = NULL;
    }
    else
    {
        cout << "\nthis index doesnot exist";
    }
}

void linked_list::print()
{

    cout << "\n\n\nthe list is as follows:\n\n";
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "    ";
        temp = temp->link;
    }
}

int main()
{
    linked_list A; // A obj of linked list type that has members head and length

    int data = 0, index = 0;
    char choice = '\0';
    do
    {
        cout << "\n";

        cout << "1. for inserting node\n";
        cout << "2. for deleting node\n";
        cout << "3. for reversing an list\n";
        cout << "4. for printing the list\n";
        cout << "e. for exit\n";
        cin >> choice;

        switch (choice)
        {
        case '1':

            cout << "enter data :\n";
            cin >> data;
            cout << "enter index:\n";
            cin >> index;
            A.insert(data, index);
            break;

        case '2':
            cout << "enter index to be deleted\n";
            cin >> index;
            A.del(index);
            break;

        case '3':
            cout << "reversing the linked list";
            A.reverse();
            break;

        case '4':
            A.print();
            break;

        case 'e':
            choice = '\0'; // to exit from the loop
            break;

        default:
            cout << "\nenter carefully\n";
            break;
        }
    } while (choice);

    cout << "\n\n program ends";
    return 0;
}

/*
    //reversing linked list using recursion
    * here we assuming head is a member of   LINKED_LIST class

    reverse(node* temp)
    {
        if(temp->link==NULL)
            {
                head=temp;
                return;
            }
        reverse(temp->link);
        node * nxt= temp->link;
        nxt->link=temp;
        return;
    }

    //printing element using recursion

    forward_print(node *temp)
    {
        if(temp->link==NULL)
        {
            cout<<temp->data;
            return;
        }
        cout<<temp->data;
        forward_print(temp->link);
        return;
    }

    //printing in reverse way

       backward_print(node *temp)
    {
        if(temp->link==NULL)
        {
            cout<<temp->data;
            return;
        }
        backward_print(temp->link);
        cout<<temp->data;

        return;
    }
*/