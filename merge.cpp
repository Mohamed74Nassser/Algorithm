#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>
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

void generateDescendingOrderArray(vector<double>& arr, int size)
{
    generateRandomArray(arr, size);
    sort(arr.begin(), arr.end(), greater<double>());
}

vector<double> merge(const vector<double>& left, const vector<double>& right)
{
    vector<double> result;
    size_t i = 0, j = 0;

    while (i < left.size() && j < right.size())
    {
        if (left[i] < right[j])
        {
            result.push_back(left[i++]);
        }
        else
        {
            result.push_back(right[j++]);
        }
    }

    while (i < left.size()) result.push_back(left[i++]);
    while (j < right.size()) result.push_back(right[j++]);
    return result;
}

vector<double> mergeSortIterative(vector<double>& arr)
{
    int step = 1;
    int length = arr.size();

    while (step < length)
    {
        for (int i = 0; i < length; i += 2 * step)
        {
            vector<double> left(arr.begin() + i, arr.begin() + min(i + step, length));
            vector<double> right(arr.begin() + min(i + step, length), arr.begin() + min(i + 2 * step, length));
            vector<double> merged = merge(left, right);

            for (size_t j = 0; j < merged.size(); ++j)
            {
                if (i + j < length)
                    arr[i + j] = merged[j];
            }
        }
        step *= 2;
    }

    return arr;
}

void merge(vector<double>& arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<double> left(n1), right(n2);

    for (int i = 0; i < n1; ++i)
        left[i] = arr[l + i];
    for (int j = 0; j < n2; ++j)
        right[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
        }
    }

    while (i < n1) arr[k++] = left[i++];
    while (j < n2) arr[k++] = right[j++];
}

void mergeSortRecursive(vector<double>& arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSortRecursive(arr, l, m);
        mergeSortRecursive(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void printFirstNElements(const vector<double>& arr, int n)
{
    for (int i = 0; i < n && i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << "... (Total elements: " << arr.size() << ")" << endl << endl;
}

int main()
{
    srand(time(0)); // توليد الأرقام العشوائية مرة واحدة هنا

    vector<double> unsortedArr;
    generateDescendingOrderArray(unsortedArr, 10000);

    auto start = chrono::high_resolution_clock::now();
    vector<double> iterativeSortedArr = mergeSortIterative(unsortedArr);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Execution time (Iterative Merge Sort): " << duration.count() << " ms" << endl << endl;

    cout << "First 20 sorted elements (Iterative): ";
    printFirstNElements(iterativeSortedArr, 20);

    vector<double> recursiveSortedArr = unsortedArr;
    start = chrono::high_resolution_clock::now();
    mergeSortRecursive(recursiveSortedArr, 0, recursiveSortedArr.size() - 1);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Execution time (Recursive Merge Sort): " << duration.count() << " ms" << endl << endl;

    cout << "First 20 sorted elements (Recursive): ";
    printFirstNElements(recursiveSortedArr, 20);

    return 0;
}