#include <iostream>

using namespace std;

struct Node {
    int _value;
    Node *_left;
    Node *_right;
};

class BST {
public:
    BST() : _root(nullptr) {}

    ~BST() {
        if (_root != nullptr)
            delete _root;
    }

    void InsertLeft(Node *node, int value) {
        node->_left = new Node{value, nullptr, nullptr};
    }

    void InsertRight(Node *node, int value) {
        node->_right = new Node{value, nullptr, nullptr};
    }

    Node *Find(Node *node, int value) {
        if (node == nullptr)
            return nullptr;

        if (node->_value == value)
            return node;

        Node *left = Find(node->_left, value);
        Node *right = Find(node->_right, value);

        if (left != nullptr)
            return left;

        if (right != nullptr)
            return right;

        return nullptr;
    }

    Node *SetRoot(int value) {
        Node *root = new Node{value, nullptr, nullptr};

        return root;
    }

    void PreOrder(Node *node) {
        if (node == nullptr)
            return;

        cout << char(node->_value);
        PreOrder(node->_left);
        PreOrder(node->_right);
    }

    void InOrder(Node *node) {
        if (node == nullptr)
            return;

        InOrder(node->_left);
        cout << char(node->_value);
        InOrder(node->_right);
    }

    void PostOrder(Node *node) {
        if (node == nullptr)
            return;

        PostOrder(node->_left);
        PostOrder(node->_right);
        cout << char(node->_value);
    }

public:
    Node *_root;
};

int main() {
    int n;
    cin >> n;

    BST *bst = new BST();
    Node *root = nullptr;
    Node *node = nullptr;

    for (int i = 0; i < n; ++i) {
        char a, b, c;
        cin >> a >> b >> c;

        if (root == nullptr)
            root = bst->SetRoot((int) a);

        node = bst->Find(root, (int) a);

        if (b != '.')
            bst->InsertLeft(node, (int) b);


        if (c != '.')
            bst->InsertRight(node, (int) c);


        node = nullptr;
    }

    bst->PreOrder(root);
    cout << endl;
    bst->InOrder(root);
    cout << endl;
    bst->PostOrder(root);

    return 0;
}