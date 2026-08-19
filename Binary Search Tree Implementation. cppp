#include <iostream>
#include <stack>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Binary Search Tree
class BST
{
public:
    Node *root;

    BST()
    {
        root = NULL;
    }

    // Insert a node
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

        if (value < temp->data)
            insert(temp->left, value);
        else
            insert(temp->right, value);
    }

    // Non-recursive Inorder Traversal
    void inorder()
    {
        if (root == NULL)
        {
            cout << "Tree is empty.\n";
            return;
        }

        stack<Node *> nodes;
        Node *current = root;

        while (current != NULL || !nodes.empty())
        {
            while (current != NULL)
            {
                nodes.push(current);
                current = current->left;
            }

            current = nodes.top();
            nodes.pop();

            cout << current->data << " ";
            current = current->right;
        }

        cout << endl;
    }

    // Non-recursive Preorder Traversal
    void preorder()
    {
        if (root == NULL)
        {
            cout << "Tree is empty.\n";
            return;
        }

        stack<Node *> nodes;
        nodes.push(root);

        while (!nodes.empty())
        {
            Node *current = nodes.top();
            nodes.pop();

            cout << current->data << " ";

            if (current->right != NULL)
                nodes.push(current->right);

            if (current->left != NULL)
                nodes.push(current->left);
        }

        cout << endl;
    }

    // Non-recursive Postorder Traversal
    void postorder()
    {
        if (root == NULL)
        {
            cout << "Tree is empty.\n";
            return;
        }

        stack<Node *> first, second;
        first.push(root);

        while (!first.empty())
        {
            Node *current = first.top();
            first.pop();

            second.push(current);

            if (current->left != NULL)
                first.push(current->left);

            if (current->right != NULL)
                first.push(current->right);
        }

        while (!second.empty())
        {
            Node *current = second.top();
            second.pop();

            cout << current->data << " ";
        }

        cout << endl;
    }
};

// Main function
int main()
{
    BST tree;
    int choice, value;

    do
    {
        cout << "\n========== BST MENU ==========";
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
            cout << "Enter value: ";
            cin >> value;
            tree.insert(tree.root, value);
            cout << "Node inserted successfully.\n";
            break;

        case 2:
            cout << "Inorder Traversal: ";
            tree.inorder();
            break;

        case 3:
            cout << "Preorder Traversal: ";
            tree.preorder();
            break;

        case 4:
            cout << "Postorder Traversal: ";
            tree.postorder();
            break;

        case 5:
            cout << "Program exited.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
