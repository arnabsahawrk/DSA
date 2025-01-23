#include <bits/stdc++.h>
using namespace std;

int main()
{
    // it store value in sorted order and its key is unique
    map<string, int> mp;
    mp["Bangladesh"] = 88; // O(longN)
    mp["India"] = 91;
    mp["USA"] = 1;
    mp["Russia"] = 7;

    for (auto mapValue : mp)                                      // O(N)
        cout << mapValue.first << " " << mapValue.second << endl; // O(1)

    if (mp.count("Russia")) // O(longN)
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}