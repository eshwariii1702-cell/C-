
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BST {
public:
    Node *root;

    BST() {
        root = NULL;
    }

    Node* insert(Node *root, int data) {
        if (root == NULL)
            return new Node(data);

        if (data < root->data)
            root->left = insert(root->left, data);
        else if (data > root->data)
            root->right = insert(root->right, data);

        return root;
    }

    void levelOrder(Node *root) {
        if (root == NULL) {
            cout << "Tree is empty." << endl;
            return;
        }

        queue<Node*> q;
        q.push(root);
        int level = 0;

        while (!q.empty()) {
            int levelSize = q.size();

            cout << "Level " << level << ": ";

            for (int i = 0; i < levelSize; i++) {
                Node *current = q.front();
                q.pop();

                cout << current->data << " ";

                if (current->left != NULL)
                    q.push(current->left);

                if (current->right != NULL)
                    q.push(current->right);
            }

            cout << endl;
            level++;
        }
    }

    int height(Node *root) {
        if (root == NULL)
            return 0;

        return 1 + max(height(root->left), height(root->right));
    }

    void printLeaves(Node *root) {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL) {
            cout << root->data << " ";
            return;
        }

        printLeaves(root->left);
        printLeaves(root->right);
    }
};

int main() {
    BST bst;
    int n, value;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements for original BST: ";

    for (int i = 0; i < n; i++) {
        cin >> value;
        bst.root = bst.insert(bst.root, value);
    }

    cout << "\n--- Original BST (Level-wise) ---" << endl;
    bst.levelOrder(bst.root);

    cout << "\nEnter a new element to insert into the BST: ";
    cin >> value;

    bst.root = bst.insert(bst.root, value);

    cout << "\n--- New BST after Insertion (Level-wise) ---" << endl;
    bst.levelOrder(bst.root);

    cout << "\nHeight of the BST (in nodes): "
         << bst.height(bst.root) << endl;

    cout << "Leaf nodes: ";
    bst.printLeaves(bst.root);
    cout << endl;

    return 0;
}
