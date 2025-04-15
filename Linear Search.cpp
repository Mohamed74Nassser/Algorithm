#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace chrono;

// Function to perform linear search (Iterative)
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;  // Not found
}

// Function to perform linear search (Recursive)
int linearSearchRecursive(int arr[], int size, int target, int index = 0) {
    // If index reaches size, return -1, meaning element not found
    if (index >= size) {
        return -1;
    }

    // If current element matches the target, return index
    if (arr[index] == target) {
        return index;
    }

    // Recursively search the next element
    return linearSearchRecursive(arr, size, target, index + 1);
}

int main() {
    const int SIZE = 1000;
    int arr[SIZE], originalArray[SIZE];

    // Fill array with random numbers between 0 and 1000
    srand(time(0));
    for (int i = 0; i < SIZE; i++) {
        originalArray[i] = rand() % 1001;
    }

    int target = 200;  // Example target for linear search

    // Measure time for Iterative Linear Search
    for (int i = 0; i < SIZE; i++) arr[i] = originalArray[i];
    auto start = high_resolution_clock::now();
    int resultIterative = linearSearch(arr, SIZE, target);
    auto end = high_resolution_clock::now();
    cout << "Iterative Linear Search Time: " << duration_cast<nanoseconds>(end - start).count() << " ns" << endl;
    if (resultIterative != -1)
        cout << "Target " << target << " found at index " << resultIterative << endl;
    else
        cout << "Target " << target << " not found in the array." << endl;
    
    cout << endl;

    // Measure time for Recursive Linear Search
    for (int i = 0; i < SIZE; i++) arr[i] = originalArray[i];
    start = high_resolution_clock::now();
    int resultRecursive = linearSearchRecursive(arr, SIZE, target);
    auto end2 = high_resolution_clock::now();
    cout << "Recursive Linear Search Time: " << duration_cast<nanoseconds>(end2 - start).count() << " ns" << endl;
    if (resultRecursive == -1)
        cout << "Target " << target << " not found in the array." << endl;

    else
        cout << "Target " << target << " found at index " << resultRecursive << endl;

    return 0;
}