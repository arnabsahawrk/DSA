#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 3, 3, 3, 3, 3, 4, 5};
    vector<int> v2;

    v2 = v;
    v2.pop_back();
    v2.push_back(10);

    vector<int> v3 = {100, 200};
    v2.insert(v2.begin() + 2, 102);
    v2.insert(v2.begin() + 2, v3.begin(), v3.end());

    v2.erase(v2.begin() + 4);
    v2.erase(v2.end() - 1);
    v2.erase(v2.begin() + 2, v2.begin() + 4);

    replace(v2.begin(), v2.end() - 2, 3, 100);

    vector<int>::iterator it = find(v2.begin(), v2.end(), 4);

    int index = it - v2.begin();

    if (it != v2.end())
        cout << "Found In Index: " << index << endl;
    else
        cout << "Not Found" << endl;

    for (auto numb : v2)
        cout << numb << " ";

    return 0;
}