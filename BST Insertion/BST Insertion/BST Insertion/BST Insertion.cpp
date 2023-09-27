#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int value) {
        key = value;
        left = right = nullptr;
    }
};

Node* insert(Node*,int);
Node* search(Node*, int);
void inorder(Node*);
void preorder(Node*);
void postorder(Node*);
Node* deleteNode(Node*,int);
int totalNodes(Node*);
Node* findSuccessor(Node* , int);
Node* findParent(Node*, int);
int calculateSum(Node*);

int main() {
    Node* root = nullptr;
    root = insert(root, 60);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 65);
    root = insert(root, 80);

    cout << "Inorder traversal of the BST: ";
    inorder(root);
    cout << endl;
    
    
    int key = 70;
    Node* result = search(root, key);
    if (result != nullptr)
        cout << key << " found in the BST" << endl;
    else
        cout << key << " not found in the BST" << endl;

    key = 69;
    result = search(root, key);
    if (result != nullptr)
        cout << key << " found in the BST" << endl;
    else
        cout << key << " not found in the BST" << endl;

    deleteNode(root, 70);
    cout << "Inorder traversal of the BST: ";
    inorder(root);
    cout << endl;

    key = 40;
    Node* successor = findSuccessor(root, key);
    if (successor != nullptr)
        cout << "The successor of " << key << " is: " << successor->key << endl;
    else
        cout << "No successor found for " << key << endl;


    key = 19;
    successor = findSuccessor(root, key);
    if (successor != nullptr)
        cout << "The successor of " << key << " is: " << successor->key << endl;
    else
        cout << "No successor found for " << key << endl;

    key = 40;
    Node* parent = findParent(root, key);
    if (parent != nullptr)
        cout << "The parent of " << key << " is: " << parent->key << endl;
    else
        cout << "No parent found for " << key << endl;

    cout << "Preorder traversal of the BST: ";
    preorder(root);
    cout << endl;

    cout << "Postorder traversal of the BST: ";
    postorder(root);
    cout << endl;

    int totalSum = calculateSum(root);
    cout << "The sum of all nodes in the BST is: " << totalSum << endl;
}

Node* insert(Node* root, int key) {
    if (root == nullptr)
    {
        return new Node(key);
    }
    if (key < root->key)
    {
        root->left = insert(root->left, key);
    }
    if (key > root->key)
    {
        root->right = insert(root->right, key);
    }
    return root;
}
void inorder(Node* root){
    if (root == nullptr)
    {
        return ;
    }
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}
void preorder(Node* root) {
    if (root == nullptr)
    {
        return;
    }
    cout << root->key << " ";
    inorder(root->left);
    inorder(root->right);
}
void postorder(Node* root) {
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left);
    inorder(root->right);
    cout << root->key << " ";
}
Node* search(Node* root, int key) {
    if (root == nullptr || root->key == key)
    {
        return root;
    }
    if (key < root->key)
    {
        return search(root->left, key);
    }
    if (key > root->key)
    {
        return search(root->right, key);
    }
}
Node* deleteNode(Node* root, int key) {
    if (root == nullptr)
    {
        return root;
    }
    if (key < root->key)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == nullptr)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* current = root->right;
        while (current && current->left != NULL)
        {
            current = current->left;
        }
        root->key = current->key;
        root->right = deleteNode(root->right, current->key);
    }
    return root;
}
int totalNodes(Node* root){
    if (root == nullptr)
    {
        return 0;
    }
    return 1 + totalNodes(root->left) + totalNodes(root->right);
}
Node* findSuccessor(Node* root, int key) {
    Node* current = root;
    Node* successor = nullptr;
    while (current != nullptr && current->key != key) {
        if (key < current->key) {
            successor = current;
            current = current->left;
        }
        else {
            current = current->right;
        }
    }
    if (current == nullptr)
        return nullptr;

    if (current->right != nullptr) {
        successor = current->right;
        while (successor && successor->left != NULL)
        {
            successor = successor->left;
        }
    }
    return successor;
}
Node* findParent(Node* root, int key) {
    if (root == nullptr|| root->key == key)
    {
        return nullptr;
    }
    Node* parent = NULL;
    Node* current = root;
    while (current && current->left != NULL)
    {
        parent = current;
        if (key < current->key)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    if (current != NULL)
    {
        return parent;
    }
    else
    {
        return NULL;
    }
}
int calculateSum(Node* root) {
    if (root == nullptr)
        return 0;

    int sum = root->key;
    sum += calculateSum(root->left);
    sum += calculateSum(root->right);

    return sum;
}