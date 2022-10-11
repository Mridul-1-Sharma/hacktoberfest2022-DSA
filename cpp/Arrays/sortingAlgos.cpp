// 5 Sorting Algorithms:
// Example:
// Input :
// 5
// 20 12 5 8 10
// Output :
// Unsorted Array :
// 20 12 5 8 10
// Sorted Array :
// 5 8 10 12 20
#include <bits/stdc++.h>
using namespace std;

// Bubble Sort
// Best Case Time Complexity : O(N)
// Average, Worst Case Time Complexities : O(N^2)
// Space Complexity : O(1)
void bubbleSort(int n, int arr[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return;
}

// Selection Sort
// Best, Average, Worst Case Time Complexities : O(N^2)
// Space Complexity : O(1)
void selectionSort(int n, int arr[])
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = arr[i];
        int pos = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                pos = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = temp;
    }

    return;
}

// Insertion Sort
// Best Case Time Complexity : O(N)
// Average, Worst Case Time Complexities : O(N^2)
// Space Complexity : O(1)
void insertionSort(int n, int arr[])
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;

        while (temp < arr[j] and j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;
    }

    return;
}

// Merge function to merge the array elements to form the
// final sorted array
void merge(int s, int e, int arr[])
{
    int mid = (s + e) / 2;
    int i = s, j = mid + 1;
    vector<int> temp;
    while (i <= mid and j <= e)
    {
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            temp.push_back(arr[j++]);
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i++]);
    }

    while (j <= e)
    {
        temp.push_back(arr[j++]);
    }

    int k = 0;
    for (int ptr = s; ptr <= e; ptr++)
    {
        arr[ptr] = temp[k++];
    }
    return;
}

// Merge Sort
// Best, Average, Worst Case Time Complexities : O(NlogN)
// Space Complexity : O(N)
void mergeSort(int s, int e, int arr[])
{
    if (s >= e)
    {
        return;
    }

    int mid = (s + e) / 2;
    mergeSort(s, mid, arr);
    mergeSort(mid + 1, e, arr);
    merge(s, e, arr);
}

// Partition function to split array and place partition element
// at correct position to perform Quick Sort
int partition(int s, int e, int arr[])
{
    int i = s - 1;
    int pivot = arr[e];

    for (int j = s; j < e; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[e];
    arr[e] = temp;

    return i + 1;
}

// Quick Sort
// Best, Average Case Time Complexity : O(NlogN)
// Worst Case Time Complexities : O(N^2)
// Space Complexity : O(1)
void quickSort(int s, int e, int arr[])
{
    if (s >= e)
        return;

    int p = partition(s, e, arr);

    quickSort(s, p - 1, arr);
    quickSort(p + 1, e, arr);
}

// Main Function
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Unsorted Array : " << endl;
    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << endl;

    // bubbleSort(n, arr);
    // selectionSort(n, arr);
    // insertionSort(n, arr);
    // quickSort(0, n - 1, arr);
    mergeSort(0, n - 1, arr);

    cout << "Sorted Array : " << endl;
    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}