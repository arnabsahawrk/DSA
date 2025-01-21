#include <bits/stdc++.h>
using namespace std;

class minHeap
{
    vector<int> nodes;

    void up_heapify(int idx)
    {
        while (idx > 0 && nodes[idx] < nodes[(nodes.size() - 1) / 2])
        {
            swap(nodes[idx], nodes[(nodes.size() - 1) / 2]);
            idx = (nodes.size() - 1) / 2;
        }
    }

    void down_heapify(int idx)
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
        for (int val : nodes)
            cout << val << " ";

        cout << endl;
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
            down_heapify(i);
    }
};

int main()
{
    minHeap heap;

    /* heap.push(9);
    heap.push(2);
    heap.push(7);
    heap.push(4);
    heap.push(5);

    heap.print();

    heap.pop(3);
    cout << heap.extractMin() << endl;
    heap.print(); */

    vector<int> v = {2, 10, 3, 99, 8, 1, 4, 7};
    heap.buildHeapFromArray(v);

    vector<int> sortedArray;
    for (int i = 0; i < v.size(); i++)
        sortedArray.push_back(heap.extractMin());

    for (int val : sortedArray)
        cout << val << " ";

    return 0;
}