#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>
using namespace std;

void generateRandomArray(vector<double>& arr, int size)
{
    srand(time(0));
    arr.clear();
    for (int i = 0; i < size; ++i)
    {
        double num = (rand() % 1000000 + 100);
        arr.push_back(num);
    }
}

void generateDescendingOrderArray(vector<double>& arr, int size)
{
    generateRandomArray(arr, size);
    sort(arr.begin(), arr.end(), greater<double>());
}

void printPartialArray(const vector<double>& arr, int limit = 20)
{
    int n = arr.size();
    for (int i = 0; i < min(n, limit); ++i)
    {
        cout << arr[i] << " ";
    }
    if (n > limit)
        cout << "...";
    cout << " (Total elements: " << n << ")" << endl << endl;
}

// Iterative Selection Sort
void selectionSortIterative(vector<double>& arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Recursive Selection Sort
void selectionSortRecursive(vector<double>& arr, int start = 0)
{
    int n = arr.size();
    if (start >= n - 1)
        return;

    int minIndex = start;
    for (int i = start + 1; i < n; ++i)
    {
        if (arr[i] < arr[minIndex])
        {
            minIndex = i;
        }
    }
    swap(arr[start], arr[minIndex]);
    selectionSortRecursive(arr, start + 1);
}

int main()
{
    vector<double> unsortedArr;
    generateDescendingOrderArray(unsortedArr, 10000);

    auto start = chrono::high_resolution_clock::now();
    vector<double> iterativeSortedArr = unsortedArr;
    selectionSortIterative(iterativeSortedArr);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Execution time (Iterative Selection Sort): " << duration.count() << " ms" << endl << endl;
    cout << "First 20 sorted elements (Iterative): ";
    printPartialArray(iterativeSortedArr);

    vector<double> recursiveSortedArr = unsortedArr;
    start = chrono::high_resolution_clock::now();
    selectionSortRecursive(recursiveSortedArr);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Execution time (Recursive Selection Sort): " << duration.count() << " ms" << endl << endl;
    cout << "First 20 sorted elements (Recursive): ";
    printPartialArray(recursiveSortedArr);

    return 0;
}