
#include <iostream>
#include <vector>
using namespace std;

void maxHeapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void minHeapify(vector<int>& arr, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void heapSortAscending(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

void heapSortDescending(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        minHeapify(arr, i, 0);
    }
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of elements." << endl;
        return 0;
    }

    vector<int> numbers(n);

    cout << "Enter numbers to sort: ";
    for (int i = 0; i < n; i++)
        cin >> numbers[i];

    vector<int> ascList = numbers;
    heapSortAscending(ascList);

    cout << "Ascending Order (Max Heap): ";
    for (int x : ascList)
        cout << x << " ";

    vector<int> descList = numbers;
    heapSortDescending(descList);

    cout << "\nDescending Order (Min Heap): ";
    for (int x : descList)
        cout << x << " ";

    cout << endl;
    return 0;
}
