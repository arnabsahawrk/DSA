// https://www.geeksforgeeks.org/problems/merge-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=merge-sort
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void mergeSort(vector<int> &arr, int l, int r)
    {
        if (l >= r)
            return;

        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merge(arr, l, mid, r);
    }

private:
    void merge(vector<int> &arr, int l, int m, int r)
    {
        vector<int> temp;
        int left = l;
        int right = m + 1;

        while (left <= m && right <= r)
        {
            if (arr[left] <= arr[right])
                temp.push_back(arr[left++]);
            else
                temp.push_back(arr[right++]);
        }

        while (left <= m || right <= r)
        {
            if (left <= m)
                temp.push_back(arr[left++]);
            else
                temp.push_back(arr[right++]);
        }

        for (int i = l; i <= r; i++)
            arr[i] = temp[i - l];
    }
};

int main()
{
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--)
    {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        Solution obj;
        obj.mergeSort(arr, 0, arr.size() - 1);
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}