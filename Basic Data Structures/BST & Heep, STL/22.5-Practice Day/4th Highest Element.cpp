// https://www.naukri.com/code360/problems/fourth-largest-element-in-the-array_1792782
#include <bits/stdc++.h>
using namespace std;

class maxHeap
{
    vector<int> nodes;

    void downHeapify(int idx)
    {
        while (1)
        {
            int largestIndex = idx;

            int l = idx * 2 + 1;
            int r = idx * 2 + 2;

            if (l < nodes.size() && nodes[l] > nodes[largestIndex])
                largestIndex = l;
            if (r < nodes.size() && nodes[r] > nodes[largestIndex])
                largestIndex = r;

            if (largestIndex == idx)
                break;

            swap(nodes[largestIndex], nodes[idx]);
            idx = largestIndex;
        }
    }

public:
    void pop(int idx)
    {
        if (idx < 1 || idx > nodes.size())
            return;

        swap(nodes[idx - 1], nodes[nodes.size() - 1]);
        nodes.pop_back();
        downHeapify(idx - 1);
    }

    int extractMax()
    {
        int max = nodes.front();
        pop(1);
        return max;
    }

    void builHeapFromArray(vector<int> array)
    {
        nodes = array;

        int lastLeafNode = nodes.size() / 2 - 1;
        for (int i = lastLeafNode; i >= 0; i--)
            downHeapify(i);
    }
};

int getFourthLargest(int arr[], int n)
{
    if (n < 4)
        return INT_MIN;

    maxHeap heap;
    vector<int> vec(arr, arr + n);
    heap.builHeapFromArray(vec);

    int i = 3;
    while (i--)
        heap.extractMax();

    return heap.extractMax();
}