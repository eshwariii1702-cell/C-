
#include <iostream>
#include <vector>
using namespace std;

class HashTable {
private:
    int size;
    vector<int> table;
    vector<bool> occupied;

public:
    HashTable(int s) {
        size = s;
        table.resize(size);
        occupied.resize(size, false);
    }

    int hashFunction(int key) {
        return (key % size + size) % size;
    }

    void insertWithoutReplacement(int key) {
        int index = hashFunction(key);
        int startIndex = index;

        while (occupied[index]) {
            if (table[index] == key) {
                cout << "Key " << key
                     << " already exists at index " << index << "." << endl;
                return;
            }

            index = (index + 1) % size;

            if (index == startIndex) {
                cout << "Hash Table is full! Cannot insert "
                     << key << endl;
                return;
            }
        }

        table[index] = key;
        occupied[index] = true;

        cout << "Inserted " << key
             << " at index " << index << "." << endl;
    }

    void insertWithReplacement(int key) {
        if (search(key) != -1) {
            cout << "Key " << key << " already exists." << endl;
            return;
        }

        int index = hashFunction(key);

        if (!occupied[index]) {
            table[index] = key;
            occupied[index] = true;

            cout << "Inserted " << key
                 << " at home index " << index << "." << endl;
            return;
        }

        int existingKey = table[index];

        if (hashFunction(existingKey) != index) {
            cout << "Replacing " << existingKey
                 << " at index " << index
                 << " with " << key << "." << endl;

            table[index] = key;
            insertWithoutReplacement(existingKey);
            return;
        }

        insertWithoutReplacement(key);
    }

    int search(int key) {
        int index = hashFunction(key);
        int startIndex = index;

        while (occupied[index]) {
            if (table[index] == key)
                return index;

            index = (index + 1) % size;

            if (index == startIndex)
                break;
        }

        return -1;
    }

    void display() {
        cout << "\n--- Hash Table ---" << endl;

        for (int i = 0; i < size; i++) {
            cout << "Index " << i << ": ";

            if (occupied[i])
                cout << table[i];
            else
                cout << "EMPTY";

            cout << endl;
        }
    }
};

int main() {
    int size, mode, choice, key;

    cout << "Enter size of the Hash Table: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid Hash Table size." << endl;
        return 0;
    }

    HashTable ht(size);

    cout << "\nSelect Collision Resolution Mode:" << endl;
    cout << "1. Linear Probing WITHOUT Replacement" << endl;
    cout << "2. Linear Probing WITH Replacement" << endl;
    cout << "Enter choice (1 or 2): ";
    cin >> mode;

    if (mode != 1 && mode != 2) {
        cout << "Invalid mode." << endl;
        return 0;
    }

    while (true) {
        cout << "\n1. Insert Key";
        cout << "\n2. Search Key";
        cout << "\n3. Display Table";
        cout << "\n4. Exit";
        cout << "\nEnter operation: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;

                if (mode == 1)
                    ht.insertWithoutReplacement(key);
                else
                    ht.insertWithReplacement(key);
                break;

            case 2:
                cout << "Enter key to search: ";
                cin >> key;

                if (ht.search(key) != -1)
                    cout << "Key " << key << " found at index "
                         << ht.search(key) << "." << endl;
                else
                    cout << "Key " << key << " not found." << endl;
                break;

            case 3:
                ht.display();
                break;

            case 4:
                cout << "Program terminated." << endl;
                return 0;

            default:
                cout << "Invalid choice." << endl;
        }
    }

    return 0;
}
