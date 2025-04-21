#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

// ========== Common Utilities ==========
void printFirstNElements(const vector<double>& arr, int n)
{
    for (int i = 0; i < n && i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << "\n... (Total elements: " << arr.size() << ")" << endl << endl;
}

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

// ========== Merge Sort ==========
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

// ========== Insertion Sort ==========
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

// ========== Bubble Sort ==========
void bubbleSortRecursive(double arr[], int n)
{
    if (n == 1)
        return;

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }

    bubbleSortRecursive(arr, n - 1);
}

void bubbleSortIterative(double arr[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
// ========== Selection Sort ==========
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

// ========== linear Search ==========

// (Iterative)
int linearSearch(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

// (Recursive)
int linearSearchRecursive(int arr[], int size, int target, int index = 0)
{
    if (index >= size)
    {
        return -1;
    }
    if (arr[index] == target)
    {
        return index;
    }
    return linearSearchRecursive(arr, size, target, index + 1);
}


// ========== Binary Search  ==========

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

// ========== Main Function ==========
int main()
{
    srand(time(0));
    const int SIZE = 10000;
    int arr[SIZE] , originalArray[SIZE];
    vector<double> unsortedArr;
    generateDescendingOrderArray(unsortedArr, 10000);

    vector<pair<string, function<void(vector<double>&)>>> sorters = {
        {"Iterative Merge Sort", [](vector<double>& arr){ mergeSortIterative(arr); }},
        {"Recursive Merge Sort", [](vector<double>& arr){ mergeSortRecursive(arr, 0, arr.size() - 1); }},
        {"Iterative Insertion Sort", [](vector<double>& arr){ insertionSortIterative(arr); }},
        {"Recursive Insertion Sort", [](vector<double>& arr){ insertionSortRecursive(arr, arr.size()); }},
        {"Iterative Selection Sort", [](vector<double>& arr){ selectionSortIterative(arr); }},
        {"Recursive Selection Sort", [](vector<double>& arr){ selectionSortRecursive(arr); }},
        {"Iterative Bubble Sort", [](vector<double>& arr){ bubbleSortIterative(arr.data(), arr.size()); }},
        {"Recursive Bubble Sort", [](vector<double>& arr){ bubbleSortRecursive(arr.data(), arr.size()); }}
    };

    for (const auto& sorter : sorters)
    {
        vector<double> toSort = unsortedArr;
        auto start = chrono::high_resolution_clock::now();
        sorter.second(toSort);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        cout << "Execution time (" << sorter.first << "): " << duration.count() << " ms" << endl;
        cout << "First 20 sorted elements: ";
        printFirstNElements(toSort, 20);
        cout << "--------------------------------------------------\n";
    };
    // Binary Search with Merge

    for (int i = 0; i < SIZE; i++) originalArray[i] = rand() % 1001;
    int target = 500;
    testSortAndSearch(mergeSort, "Merge Sort", originalArray, SIZE, target);

    // Linear Search

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
