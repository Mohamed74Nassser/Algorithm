#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <stack>
using namespace std;

void generateRandomArray(vector<int>& arr, int size)
{
    arr.clear();
    for (int i = 0; i < size; ++i)
    {
        int num = rand() % 1000000 + 100;
        arr.push_back(num);
    }
}

int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortIterative(vector<int>& arr, int low, int high)
{
    stack<int> s;
    s.push(low);
    s.push(high);

    while (!s.empty())
    {
        high = s.top(); s.pop();
        low = s.top(); s.pop();

        int pi = partition(arr, low, high);

        if (pi - 1 > low)
        {
            s.push(low);
            s.push(pi - 1);
        }

        if (pi + 1 < high)
        {
            s.push(pi + 1);
            s.push(high);
        }
    }
}

void quickSortRecursive(vector<int>& arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSortRecursive(arr, low, pi - 1);
        quickSortRecursive(arr, pi + 1, high);
    }
}

void printFirstNElements(const vector<int>& arr, int n)
{
    for (int i = 0; i < n && i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << "... (Total elements: " << arr.size() << ")" << endl << endl;
}

int main()
{
    srand(time(0)); // توليد أرقام عشوائية مرة واحدة

    vector<int> unsortedArr;
    generateRandomArray(unsortedArr, 10000);

    // نسخ للفرز التكراري
    vector<int> iterativeSortedArr = unsortedArr;
    auto start = chrono::high_resolution_clock::now();
    quickSortIterative(iterativeSortedArr, 0, iterativeSortedArr.size() - 1);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Execution time (Iterative Quick Sort): " << duration.count() << " ms" << endl << endl;

    cout << "First 20 sorted elements (Iterative): ";
    printFirstNElements(iterativeSortedArr, 20);

    // نسخ للفرز العودي
    vector<int> recursiveSortedArr = unsortedArr;
    start = chrono::high_resolution_clock::now();
    quickSortRecursive(recursiveSortedArr, 0, recursiveSortedArr.size() - 1);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Execution time (Recursive Quick Sort): " << duration.count() << " ms" << endl << endl;

    cout << "First 20 sorted elements (Recursive): ";
    printFirstNElements(recursiveSortedArr, 20);

    return 0;
}