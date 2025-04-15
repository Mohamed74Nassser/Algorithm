#pragma warning(disable : 4996)
#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace chrono;

int binarySearchIterative(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int binarySearchRecursive(int arr[], int low, int high, int target) {
    if (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) return binarySearchRecursive(arr, mid + 1, high, target);
        else return binarySearchRecursive(arr, low, mid - 1, target);
    }
    return -1;
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
        }
    }
}

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge(arr, left, mid);
        merge(arr, mid + 1, right);

        int n1 = mid - left + 1, n2 = right - mid;
        int* L = new int[n1];
        int* R = new int[n2];

        for (int i = 0; i < n1; i++) L[i] = arr[left + i];
        for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];

        delete[] L;
        delete[] R;
    }
}

void mergeSort(int arr[], int size) {
    merge(arr, 0, size - 1);
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortHelper(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

void quickSort(int arr[], int size) {
    quickSortHelper(arr, 0, size - 1);
}

void testSortAndSearch(void (*sortFunc)(int[], int), const string& name, int original[], int size, int target) {
    int* arr = new int[size];
    for (int i = 0; i < size; i++) arr[i] = original[i];

    auto startSort = high_resolution_clock::now();
    sortFunc(arr, size);
    auto endSort = high_resolution_clock::now();

    cout << name << " Time: " << duration_cast<milliseconds>(endSort - startSort).count() << " ms" << endl;

    auto startIter = high_resolution_clock::now();
    int indexIter = binarySearchIterative(arr, size, target);
    auto endIter = high_resolution_clock::now();
    cout << "Binary Search Time (after " << name << "): " << duration_cast<nanoseconds>(endIter - startIter).count() << " ns" << endl;

    auto startRec = high_resolution_clock::now();
    int indexRec = binarySearchRecursive(arr, 0, size - 1, target);
    auto endRec = high_resolution_clock::now();
    cout << "Recursive Binary Search Time (after " << name << "): " << duration_cast<nanoseconds>(endRec - startRec).count() << " ns" << endl;

    if (indexIter != -1)
        cout << "Target " << target << " found at index " << indexIter << endl;
    else
        cout << "Target " << target << " not found in the array." << endl;

    cout << "--------------------------------------------------" << endl;

    delete[] arr;
}

int main() {
    const int SIZE = 5000;
    int originalArray[SIZE];
    srand(time(0));
    for (int i = 0; i < SIZE; i++) originalArray[i] = rand() % 1001;

    int target = 500;

    testSortAndSearch(selectionSort, "Selection Sort", originalArray, SIZE, target);
    testSortAndSearch(bubbleSort, "Bubble Sort", originalArray, SIZE, target);
    testSortAndSearch(insertionSort, "Insertion Sort", originalArray, SIZE, target);
    testSortAndSearch(mergeSort, "Merge Sort", originalArray, SIZE, target);
    testSortAndSearch(quickSort, "Quick Sort", originalArray, SIZE, target);

    return 0;
}