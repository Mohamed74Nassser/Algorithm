#include <iostream>
#include <chrono>
#include <iomanip>  // for setfill and setw
#include <ctime>

using namespace std;
using namespace chrono;

void generateRandomArray(int arr[], int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1001;  // Random numbers between 0 and 1000
    }
}

void printArray(int arr[], int size, int limit = 20) {
    for (int i = 0; i < min(size, limit); i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

// Recursive Bubble Sort
void bubbleSortRecursive(int arr[], int n) {
    if (n == 1)
        return;

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }

    bubbleSortRecursive(arr, n - 1);
}

// Iterative Bubble Sort
void bubbleSortIterative(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    const int SIZE = 3000;
    int arr[SIZE];

    generateRandomArray(arr, SIZE);
    cout << "First 20 element in Original Array" << endl;
    printArray(arr, SIZE);
    cout << endl;

    // Measure time for Recursive Bubble Sort
    int arrRecursive[SIZE];
    copy(arr, arr + SIZE, arrRecursive);
    auto startRecursive = high_resolution_clock::now();  // Start measuring time for the sort function
    bubbleSortRecursive(arrRecursive, SIZE);             // Sorting function call
    auto endRecursive = high_resolution_clock::now();    // End measuring time for the sort function
    auto durationRecursive = duration_cast<milliseconds>(endRecursive - startRecursive);  // Calculate time
    cout << "Time taken for Recursive Bubble Sort: " << durationRecursive.count() << " milliseconds\n";

    cout << endl;

    // Measure time for Iterative Bubble Sort
    int arrIterative[SIZE];
    copy(arr, arr + SIZE, arrIterative);
    auto startIterative = high_resolution_clock::now();  // Start measuring time for the sort function
    bubbleSortIterative(arrIterative, SIZE);             // Sorting function call
    auto endIterative = high_resolution_clock::now();    // End measuring time for the sort function
    auto durationIterative = duration_cast<milliseconds>(endIterative - startIterative);  // Calculate time
    cout << "Time taken for Iterative Bubble Sort: " << durationIterative.count() << " milliseconds\n";

    return 0;
}