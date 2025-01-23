#include <bits/stdc++.h>
using namespace std;

void insert_heap(vector<int> &v, int value)
{
    v.push_back(value);

    int currentIndex = v.size() - 1;
    while (currentIndex != 0)
    {
        int parenIndex = (currentIndex - 1) / 2;

        if (v[parenIndex] < v[currentIndex])
            swap(v[parenIndex], v[currentIndex]);
        else
            break;

        currentIndex = parenIndex;
    }
}

void delete_heap(vector<int> &v)
{
    v[0] = v.back();
    v.pop_back();

    int currentIndex = 0;

    while (true)
    {
        int leftIndex = (currentIndex * 2) + 1;
        int rightIndex = (currentIndex * 2) + 2;

        int leftValue = INT_MIN, rightValue = INT_MIN;
        if (leftIndex < v.size())
            leftValue = v[leftIndex];
        if (rightIndex < v.size())
            rightValue = v[rightIndex];

        if (leftValue >= rightValue && leftValue > v[currentIndex])
        {
            swap(v[leftIndex], v[currentIndex]);
            currentIndex = leftIndex;
        }
        else if (rightValue > leftValue && rightValue > v[currentIndex])
        {
            swap(v[rightIndex], v[currentIndex]);
            currentIndex = rightIndex;
        }
        else
            break;
    }
}

void print_heap(vector<int> v)
{
    for (auto x : v)
        cout << x << " ";

    cout << endl;
}

int main()
{
    vector<int> v;

    int value;
    while (cin >> value)
        insert_heap(v, value);

    print_heap(v);
    delete_heap(v);
    print_heap(v);

    return 0;
}