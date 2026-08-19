#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *root = NULL;

class Tree
{
public:

    // Insert node into Binary Tree
    void insert(Node *&temp, int value)
    {
        if (temp == NULL)
        {
            temp = new Node;
            temp->data = value;
            temp->left = NULL;
            temp->right = NULL;
            return;
        }

        if (temp->left == NULL)
        {
            insert(temp->left, value);
        }
        else if (temp->right == NULL)
        {
            insert(temp->right, value);
        }
        else
        {
            insert(temp->left, value);
        }
    }

    // Inorder Traversal
    void inorder(Node *temp)
    {
        if (temp == NULL)
            return;

        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }

    // Preorder Traversal
    void preorder(Node *temp)
    {
        if (temp == NULL)
            return;

        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }

    // Postorder Traversal
    void postorder(Node *temp)
    {
        if (temp == NULL)
            return;

        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data << " ";
    }
};

int main()
{
    Tree tree;
    int choice, value;

    do
    {
        cout << "\n========== BINARY TREE MENU ==========";
        cout << "\n1. Insert Node";
        cout << "\n2. Inorder Traversal";
        cout << "\n3. Preorder Traversal";
        cout << "\n4. Postorder Traversal";
        cout << "\n5. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            tree.insert(root, value);
            cout << "Node inserted successfully.\n";
            break;

        case 2:
            if (root == NULL)
                cout << "Tree is empty!\n";
            else
            {
                cout << "Inorder Traversal: ";
                tree.inorder(root);
                cout << endl;
            }
            break;

        case 3:
            if (root == NULL)
                cout << "Tree is empty!\n";
            else
            {
                cout << "Preorder Traversal: ";
                tree.preorder(root);
                cout << endl;
            }
            break;

        case 4:
            if (root == NULL)
                cout << "Tree is empty!\n";
            else
            {
                cout << "Postorder Traversal: ";
                tree.postorder(root);
                cout << endl;
            }
            break;

        case 5:
            cout << "Program Exited.\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}
