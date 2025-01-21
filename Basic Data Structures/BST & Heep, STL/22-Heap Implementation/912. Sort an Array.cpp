// https://leetcode.com/problems/sort-an-array/
#include <bits/stdc++.h>
using namespace std;
class minHeap
{
    vector<int> nodes;
    void downHeapify(int idx)
    {
        while (1)
        {
            int smallestIndex = idx;

            int l = idx * 2 + 1;
            int r = idx * 2 + 2;

            if (l < nodes.size() && nodes[smallestIndex] > nodes[l])
                smallestIndex = l;
            if (r < nodes.size() && nodes[smallestIndex] > nodes[r])
                smallestIndex = r;

            if (smallestIndex == idx)
                break;

            swap(nodes[smallestIndex], nodes[idx]);
            idx = smallestIndex;
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

    int extractMin()
    {
        int min = nodes.front();
        pop(1);
        return min;
    }

    void buildHeapFromArray(vector<int> array)
    {
        nodes = array;
        int lastLeafNode = nodes.size() / 2 - 1;

        for (int i = lastLeafNode; i >= 0; i--)
            downHeapify(i);
    }
};

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        minHeap heap;
        heap.buildHeapFromArray(nums);

        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
            ans.push_back(heap.extractMin());

        return ans;
    }
};