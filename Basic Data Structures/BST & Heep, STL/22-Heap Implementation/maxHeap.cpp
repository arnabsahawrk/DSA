#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{
    vector<int> nodes;

    void up_heapify(int idx)
    {
        while (idx > 0 && nodes[idx] > nodes[(idx - 1) / 2])
        {
            swap(nodes[idx], nodes[(idx - 1) / 2]);
            idx = (idx - 1) / 2;
        }
    }

    void down_heapify(int idx)
    {
        while (1)
        {
            int largestIndex = idx;

            int l = idx * 2 + 1;
            int r = idx * 2 + 2;

            if (l < nodes.size() && nodes[largestIndex] < nodes[l])
                largestIndex = l;
            if (r < nodes.size() && nodes[largestIndex] < nodes[r])
                largestIndex = r;

            if (largestIndex == idx)
                break;

            swap(nodes[idx], nodes[largestIndex]);
            idx = largestIndex;
        }
    }

public:
    void push(int value)
    {
        nodes.push_back(value);
        up_heapify(nodes.size() - 1);
    }

    void pop(int idx)
    {
        if (idx < 1 || idx > nodes.size())
            return;

        swap(nodes[idx - 1], nodes[nodes.size() - 1]);
        nodes.pop_back();
        down_heapify(idx - 1);
    }

    void print()
    {
        for (int value : nodes)
            cout << value << " ";

        cout << endl;
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

        int lastLeafNode = nodes.size() / 2 - 1;
        for (int i = lastLeafNode; i >= 0; i--)
            down_heapify(i);
    }
};

int main()
{

    MaxHeap heap;

    /* heap.push(5);
     heap.push(10);
     heap.push(20);
     heap.push(30);
     heap.push(40);

     heap.print();

     heap.pop(2);
     cout << heap.extractMax() << endl;

     heap.print(); */

    vector<int> v = {1, 2, 3, 4, 5};
    heap.buildHeapFromArray(v);

    heap.print();

    vector<int> sortedArray;
    for (int i = 0; i < v.size(); i++)
        sortedArray.push_back(heap.extractMax());

    reverse(sortedArray.begin(), sortedArray.end());

    for (int val : sortedArray)
        cout << val << " ";

    return 0;
}