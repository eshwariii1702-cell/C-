
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

const string DATA_FILE = "records.txt";
const string INDEX_FILE = "index.txt";

long long searchIndex(int targetID) {
    ifstream idxFile(INDEX_FILE);

    if (!idxFile)
        return -1;

    string line;

    while (getline(idxFile, line)) {
        stringstream ss(line);
        int id;
        long long offset;
        char comma;

        if (ss >> id >> comma >> offset) {
            if (id == targetID)
                return offset;
        }
    }

    return -1;
}

void addRecord(int recordID, string name, string department) {
    if (searchIndex(recordID) != -1) {
        cout << "Record with ID " << recordID
             << " already exists." << endl;
        return;
    }

    ofstream dataFile(DATA_FILE, ios::app | ios::binary);

    if (!dataFile) {
        cout << "Unable to open data file." << endl;
        return;
    }

    long long offset = dataFile.tellp();

    dataFile << recordID << "," << name << ","
             << department << "\n";

    dataFile.close();

    ofstream indexFile(INDEX_FILE, ios::app);

    indexFile << recordID << "," << offset << "\n";
    indexFile.close();

    cout << "Record " << recordID
         << " added at byte offset " << offset << "." << endl;
}

void searchRecord(int targetID) {
    long long offset = searchIndex(targetID);

    if (offset == -1) {
        cout << "Record ID " << targetID
             << " not found in index." << endl;
        return;
    }

    ifstream dataFile(DATA_FILE, ios::binary);

    if (!dataFile) {
        cout << "Unable to open data file." << endl;
        return;
    }

    dataFile.seekg(offset);

    string record;
    getline(dataFile, record);

    stringstream ss(record);
    string id, name, department;

    getline(ss, id, ',');
    getline(ss, name, ',');
    getline(ss, department);

    cout << "\n--- Record Found (Offset: "
         << offset << ") ---" << endl;

    cout << "ID: " << id
         << " | Name: " << name
         << " | Department: " << department << endl;

    dataFile.close();
}

void displayAll() {
    ifstream dataFile(DATA_FILE, ios::binary);
    ifstream indexFile(INDEX_FILE);

    if (!dataFile || !indexFile) {
        cout << "No records found yet." << endl;
        return;
    }

    cout << "\n--- Index File Contents (ID -> Byte Offset) ---"
         << endl;

    string line;

    while (getline(indexFile, line)) {
        stringstream ss(line);
        int id;
        long long offset;
        char comma;

        if (ss >> id >> comma >> offset)
            cout << "ID: " << id
                 << " -> Offset: " << offset << endl;
    }

    cout << "\n--- Data File Contents ---" << endl;

    while (getline(dataFile, line))
        cout << line << endl;

    dataFile.close();
    indexFile.close();
}

int main() {
    int choice, recordID;
    string name, department;

    while (true) {
        cout << "\n1. Add Record";
        cout << "\n2. Search Record by ID";
        cout << "\n3. Display Index & Data Files";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Record ID: ";
                cin >> recordID;

                cin.ignore();

                cout << "Enter Name: ";
                getline(cin, name);

                cout << "Enter Department: ";
                getline(cin, department);

                addRecord(recordID, name, department);
                break;

            case 2:
                cout << "Enter Record ID to search: ";
                cin >> recordID;
                searchRecord(recordID);
                break;

            case 3:
                displayAll();
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
