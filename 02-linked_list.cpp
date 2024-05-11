#include <iostream>

using namespace std;

// class Node
// {
// public:
//     int val;
//     Node *next;

//     Node(int v)
//     {
//         val = v;
//         next = NULL;
//     }
// };

// class linkedlist
// {
//     Node *head = NULL;
//     int length = 0;

// public:
//     void insertion(int v, int position)
//     {
//         length++;

//         if (position > length)
//         {
//             cout << "Invalid value";
//             return;
//         }
//         Node *newNode = new Node(v);

//         if (head == NULL)
//         {
//             head = newNode;
//             return;
//         }

//         // begining

//         if (position == 1)
//         {
//             newNode->next = head;
//             head = newNode;
//             return;
//         }

//         // middle
//         Node *current = head;

//         for (int i = 2; i < position; i++)
//         {
//             // cout << current->val << ":i" << i << "\t|";
//             current = current->next;
//         }

//         // cout << endl
//         //      << "Curr: " << current->val << endl;
//         newNode->next = current->next;
//         current->next = newNode;

//         return;
//     }

//     void printlist()

//     {
//         if (head == NULL)
//         {
//             cout << "Empty List" << endl;
//             return;
//         }

//         Node *current = head;

//         cout << "List:\t";
//         while (current != NULL)
//         {
//             cout << current->val << ",";
//             current = current->next;
//         }

//         cout << "\t|\t"
//              << "Length: " << length << endl;

//         return;
//     }

//     void deletion(int pos)
//     {
//         if (!head | pos > length)
//         {
//             cout << "Invalid Operation!" << endl;
//             return;
//         }

//         // head
//         length--;
//         if (pos == 1)
//         {
//             Node *temp = head;
//             head = head->next;
//             delete temp;
//             return;
//         }

//         // mid
//         Node *current = head;

//         for (int i = 2; i < pos; i++)
//         {
//             current = current->next;
//         }
//         // cout << "Current:" << current->val;
//         // before node

//         Node *temp = current->next;
//         current->next = current->next->next;
//         delete temp;
//         return;
//     }
// };

// int main(int argc, char const *argv[])
// {
//     linkedlist l;

//     l.insertion(3, 1);
//     l.insertion(2, 1);
//     l.insertion(1, 1);
//     l.insertion(5, 4);
//     l.insertion(4, 4);
//     l.printlist();

//     cout << "Deletion:" << endl;
//     l.deletion(12);
//     l.printlist();

//     // l.insertion(4, 4);
//     // cout << endl;

//     return 0;
// }

//////////////////////////////////////////////////////////////////////

struct Node
{
    int data;
    Node *next;

    Node(int data) : data(data), next(nullptr) {}
    // initializer list :Initializer List is used in initializing the data members of a class. The list of members to be initialized is indicated with constructor as a comma-separated list followed by a colon
};

class linked_list
{
public:
    Node *head = nullptr;
    int length = 0;

    int getLength()
    {
        cout << "\nlength: " << length << endl;
        return length;
    }

    void insertion(int data, int index)
    {

        Node *node = new Node(data);

        // index:0

        if (index <= 0)
        {
            node->next = head;
            head = node;
            length++;

            cout << "\nnew node (" << node->data << ") added in place of head!" << endl;
            return;
        }

        // index > 1

        int currIndex = 0;
        Node *currNode = head;
        while (currIndex < index - 1 and currNode != nullptr)

        {
            // cout << "index: " << currIndex << " curr: " << currNode->data << endl;
            currNode = currNode->next;

            currIndex++;
        }
        // cout << "CURRET" << currIndex << endl;

        if (currNode == nullptr)
        {
            cout << "\nInvalid index: " << index << ", node not inserted!" << endl;
            return;
        }

        Node *temp = currNode->next;
        currNode->next = node;
        node->next = temp;
        cout << "\nentered " << node->data << " at " << index << endl;
        length++;

        return;
    }

    bool deletion(int index)
    {
        if (index == 0)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            cout << "\nhead deleted" << endl;
            length--;

            return true;
        }

        // in between
        int currIndex = 0;
        Node *currNode = head;
        while (currIndex < index - 1 and currNode != nullptr)
        {
            currIndex++;
            currNode = currNode->next;
            int d = currNode->data;
            // cout << "\nCurrindex: " << currIndex << " CurrNode: " << currNode->data << endl;
        }
        if (currNode->next == nullptr)
        {
            cout << "\nInvalid index: " << index << ", node not deleted!" << endl;
            return false;
        }
        Node *temp = currNode->next;
        // cout << "\n\ntemp:" << temp->data << endl;
        currNode->next = currNode->next->next;
        length--;

        delete temp;

        cout << "\nnode at index: " << index << ", deleted!" << endl;

        return true;
    }

    void printLinkedList()
    {
        Node *curr = head;
        cout << endl
             << "l: ";
        while (curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }

    void reverse()
    {
        printLinkedList();
        Node *prev = nullptr;
        Node *curr = head;

        while (curr != nullptr)
        {
            Node *forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        head = prev;

        printLinkedList();
    }

    void deleteMiddleNode()
    {
        if (head->next == nullptr)
        {
            return;
        }
        Node *slow = head, *fast = head->next->next;

        // cout << slow->data << "\t" << fast->data;

        // hare and totrise algorithm
        cout << "\n";
        while (fast and fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        cout << "\t" << slow->data;

        slow->next = slow->next->next;
        printLinkedList();

        return;
    }

    void oddEven()
    {
        if (!head || !head->next)
        {
            // The list has 0 or 1 node, no need to modify
            return;
        }

        Node *odd = head;
        Node *even = head->next;
        Node *evenHead = even;

        while (even && even->next)
        {
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;
    }
};

int main(int argc, char **argv)
{
    // ZERO INDEX BASEDl->getLength();

    //  Node *x = new Node(12);curr
    linked_list *l = new linked_list();
    l->insertion(1, 0);
    // l->printLinkedList();

    l->insertion(0, 0);
    // l->printLinkedList();

    l->insertion(2, 2);
    // l->printLinkedList();

    l->insertion(4, 3);

    // l->printLinkedList();

    // // cout << l->head->data << endl;
    l->insertion(3, 3);
    // l->printLinkedList();

    l->insertion(5, 5);
    l->insertion(6, 6);

    l->printLinkedList();
    // l->getLength();

    // cout << l->length;
    // l->deletion(4);
    // l->printLinkedList();
    // l->getLength();
    // l->reverse();
    // l->deleteMiddleNode();
    l->oddEven();

    /*The reason for using a pointer (Node* x) instead of a regular object (Node x) is that the dynamic allocation (new Node(12)) returns a pointer to the
    allocated memory, not the object itself. Therefore, x needs to be a pointer to correctly store the address of the newly allocated Node object.
    If x were declared as a regular object (Node x;), it would try to store the actual Node object in automatic storage (stack), and that would not work
    correctly, as the new operator returns a pointer to the object in the heap.
    So, in summary, x is a pointer to a dynamically allocated Node object because dynamic memory allocation is used (new Node(12)), and pointers are necessary
    to correctly handle dynamically allocated memory in C++.*/

    // std::cout << x->data << std::endl;

    // delete x; // Don't forget to free the memory allocated using new
    delete l;
    return 0;
}
