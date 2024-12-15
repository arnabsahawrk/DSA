#include <bits/stdc++.h>
using namespace std;

int main()
{
    int array[5] = {1, 2, 3, 4, 5};
    cout << (int)&array[0] << " " << (int)&array[1] << endl;

    vector<int> v = {1, 2, 3, 4, 5};
    v.push_back(6);
    cout << (int)&v[4] << " " << (int)&v[5];

    return 0;
}

/*
Array Limitation:
* Fixed Size
* Sequential Memory Allocation
*/