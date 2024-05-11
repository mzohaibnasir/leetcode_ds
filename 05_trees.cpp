#include <iostream>

using namespace std;

struct Node
{

    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

int main()
{

    // Node *root = new Node{
    //     1,
    //     nullptr,
    //     nullptr};
    Node *root = new Node(0);
    cout << root->data << endl;

    // Node *l1 = new Node{2, nullptr, nullptr};
    Node *l1 = new Node(1);
    cout << l1->data << endl;
    cout << "L " << (*l1).data << endl;

    // root.left = l1;
    root->left = l1;
    // (*root).left = l1;

    // cout
    //     << root->left->data;
    root->left->right = new Node(11);
    cout << root->left->right->data;
    delete l1;
    delete root;
}