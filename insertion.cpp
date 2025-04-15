#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

void generateRandomArray(vector<double>& arr, int size)
{
    arr.clear();
    for (int i = 0; i < size; ++i)
    {
        double num = rand() % 1000000 + 100;
        arr.push_back(num);
    }
}

void insertionSortIterative(vector<double>& arr)
{
    int length = arr.size();
    for (int i = 1; i < length; i++)
    {
        double key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void insertionSortRecursive(vector<double>& arr, int n)
{
    if (n <= 1)
        return;

    insertionSortRecursive(arr, n - 1);

    double last = arr[n - 1];
    int j = n - 2;

    while (j >= 0 && arr[j] > last)
    {
        arr[j + 1] = arr[j];
        j--;
    }

    arr[j + 1] = last;
}

void printFirstNElements(const vector<double>& arr, int n)
{
    for (int i = 0; i < n && i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << "... (Total elements: " << arr.size() << ")" << endl << endl;
}

int main()
{
    srand(time(0));  // توليد الأرقام العشوائية مرة واحدة
    vector<double> unsortedArr;
    generateRandomArray(unsortedArr, 10000);  // توليد مصفوفة من 10000 عنصر عشوائي

    // الترتيب التكراري
    vector<double> iterativeSortedArr = unsortedArr;
    auto start = chrono::high_resolution_clock::now();
    insertionSortIterative(iterativeSortedArr);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Execution time (Iterative Insertion Sort): " << duration.count() << " ms" << endl << endl;

    cout << "First 20 sorted elements (Iterative): ";
    printFirstNElements(iterativeSortedArr, 20);

    // الترتيب العودي
    vector<double> recursiveSortedArr = unsortedArr;
    start = chrono::high_resolution_clock::now();
    insertionSortRecursive(recursiveSortedArr, recursiveSortedArr.size());
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Execution time (Recursive Insertion Sort): " << duration.count() << " ms" << endl << endl;

    cout << "First 20 sorted elements (Recursive): ";
    printFirstNElements(recursiveSortedArr, 20);

    return 0;
}