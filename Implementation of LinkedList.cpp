#include <iostream>
using namespace std;

//----------------------------
// Node Structure
//----------------------------
struct Node
{
    int value;
    Node *next;
};

//----------------------------
// Linked List Class
//----------------------------
class SinglyLinkedList
{
private:
    Node *start;

public:
    // Constructor
    SinglyLinkedList()
    {
        start = NULL;
    }

    //----------------------------
    // Create Linked List
    //----------------------------
    void create()
    {
        int totalNodes, data;

        cout << "\nEnter number of nodes: ";
        cin >> totalNodes;

        if (totalNodes <= 0)
        {
            cout << "Invalid input.\n";
            return;
        }

        for (int i = 1; i <= totalNodes; i++)
        {
            cout << "Enter value " << i << ": ";
            cin >> data;
            insertEnd(data);
        }

        cout << "\nLinked List created successfully.\n";
    }

    //----------------------------
    // Insert at Beginning
    //----------------------------
    void insertBeginning(int data)
    {
        Node *newNode = new Node;

        newNode->value = data;
        newNode->next = start;

        start = newNode;

        cout << "Node inserted at beginning successfully.\n";
    }

    //----------------------------
    // Insert at End
    //----------------------------
    void insertEnd(int data)
    {
        Node *newNode = new Node;

        newNode->value = data;
        newNode->next = NULL;

        if (start == NULL)
        {
            start = newNode;
            return;
        }

        Node *temp = start;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;

        cout << "Node inserted at end successfully.\n";
    }

    //----------------------------
    // Delete Node
    //----------------------------
    void deleteNode(int data)
    {
        if (start == NULL)
        {
            cout << "\nLinked List is empty.\n";
            return;
        }

        Node *current = start;
        Node *previous = NULL;

        if (current->value == data)
        {
            start = current->next;
            delete current;
            cout << "Node deleted successfully.\n";
            return;
        }

        while (current != NULL && current->value != data)
        {
            previous = current;
            current = current->next;
        }

        if (current == NULL)
        {
            cout << "Value not found.\n";
            return;
        }

        previous->next = current->next;
        delete current;

        cout << "Node deleted successfully.\n";
    }

    //----------------------------
    // Display Linked List
    //----------------------------
    void display()
    {
        if (start == NULL)
        {
            cout << "\nLinked List is empty.\n";
            return;
        }

        Node *temp = start;

        cout << "\nLinked List: ";

        while (temp != NULL)
        {
            cout << temp->value << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }
};

//----------------------------
// Main Function
//----------------------------
int main()
{
    SinglyLinkedList list;
    int choice, data;

    do
    {
        cout << "\n========== LINKED LIST MENU ==========";
        cout << "\n1. Create List";
        cout << "\n2. Insert at Beginning";
        cout << "\n3. Insert at End";
        cout << "\n4. Delete Node";
        cout << "\n5. Display List";
        cout << "\n6. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            list.create();
            break;

        case 2:
            cout << "Enter value to insert at beginning: ";
            cin >> data;
            list.insertBeginning(data);
            break;

        case 3:
            cout << "Enter value to insert at end: ";
            cin >> data;
            list.insertEnd(data);
            break;

        case 4:
            cout << "Enter value to delete: ";
            cin >> data;
            list.deleteNode(data);
            break;

        case 5:
            list.display();
            break;

        case 6:
            cout << "Program terminated.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}
