#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n;

    int arrN[n];
    for (int i = 0; i < n; i++)
        cin >> arrN[i]; // input must be in a sorted order

    cin >> m;
    int arrM[m];
    for (int j = 0; j < m; j++)
        cin >> arrM[j]; // input must be in a sorted order

    int conquer[n + m];
    int i = 0, j = 0, curr = 0;
    while (i < n && j < m)
    {
        if (arrN[i] < arrM[j])
            conquer[curr++] = arrN[i++];
        else
            conquer[curr++] = arrM[j++];
    }

    while (i < n || j < m)
    {
        if (i < n)
            conquer[curr++] = arrN[i++];
        else
            conquer[curr++] = arrM[j++];
    }

    for (int val : conquer)
        cout << val << " ";

    return 0;
}