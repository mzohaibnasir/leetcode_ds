#include <iostream>

using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int v)
    {
        val = v;
        next = NULL;
    }
};

class linkedlist
{
    Node *head = NULL;
    int length = 0;

public:
    void insertion(int v, int position)
    {
        length++;

        if (position > length)
        {
            cout << "Invalid value";
            return;
        }
        Node *newNode = new Node(v);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        // begining

        if (position == 1)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        // middle
        Node *current = head;

        for (int i = 2; i < position; i++)
        {
            // cout << current->val << ":i" << i << "\t|";
            current = current->next;
        }

        // cout << endl
        //      << "Curr: " << current->val << endl;
        newNode->next = current->next;
        current->next = newNode;

        return;
    }

    void printlist()

    {
        if (head == NULL)
        {
            cout << "Empty List" << endl;
            return;
        }

        Node *current = head;

        cout << "List:\t";
        while (current != NULL)
        {
            cout << current->val << ",";
            current = current->next;
        }

        cout << "\t|\t"
             << "Length: " << length << endl;

        return;
    }

    void deletion(int pos)
    {
        if (!head | pos > length)
        {
            cout << "Invalid Operation!" << endl;
            return;
        }

        // head
        length--;
        if (pos == 1)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // mid
        Node *current = head;

        for (int i = 2; i < pos; i++)
        {
            current = current->next;
        }
        // cout << "Current:" << current->val;
        // before node

        Node *temp = current->next;
        current->next = current->next->next;
        delete temp;
        return;
    }
};

int main(int argc, char const *argv[])
{
    linkedlist l;

    l.insertion(3, 1);
    l.insertion(2, 1);
    l.insertion(1, 1);
    l.insertion(5, 4);
    l.insertion(4, 4);
    l.printlist();

    cout << "Deletion:" << endl;
    l.deletion(12);
    l.printlist();

    // l.insertion(4, 4);
    // cout << endl;

    return 0;
}
