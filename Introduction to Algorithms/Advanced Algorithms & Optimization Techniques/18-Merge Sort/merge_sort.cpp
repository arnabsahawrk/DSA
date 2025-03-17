#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int left, int mid, int right) // O(N)
{
    vector<int> temp;   // temporary array
    int low = left;     // starting index of left half of arr
    int high = mid + 1; // starting index of right half of arr

    while (low <= mid && high <= right)
    {
        if (arr[low] <= arr[high])
            temp.push_back(arr[low++]);
        else
            temp.push_back(arr[high++]);
    }

    // the left elements of left or right side
    while (low <= mid || high <= right)
    {
        if (low <= mid)
            temp.push_back(arr[low++]);
        else
            temp.push_back(arr[high++]);
    }

    // transfering all elements from temporary to arr //
    for (int i = left; i <= right; i++)
        arr[i] = temp[i - left];
}

void mergeSort(int arr[], int l, int r) // O(NlogN)
{
    if (l >= r)
        return;

    int mid = l + (r - l) / 2;
    mergeSort(arr, l, mid);     // left half
    mergeSort(arr, mid + 1, r); // right half

    merge(arr, l, mid, r); // merging sorted halves
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}