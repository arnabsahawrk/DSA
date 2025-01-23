// https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
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

            swap(nodes[idx], nodes[largestIndex]);
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

    void buildHeapFromArray(vector<int> array)
    {
        nodes = array;
        int lastLeafNode = array.size() / 2 - 1;
        for (int i = lastLeafNode; i >= 0; i--)
            downHeapify(i);
    }
};

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        maxHeap heap;
        heap.buildHeapFromArray(nums);

        int i = heap.extractMax();
        int j = heap.extractMax();

        cout << i << " " << j << endl;

        return (i - 1) * (j - 1);
    }
};