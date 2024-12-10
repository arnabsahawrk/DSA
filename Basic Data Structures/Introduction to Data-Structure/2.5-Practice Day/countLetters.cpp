#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    vector<int> freqArray(26, 0);

    for (auto c : str) // O(length of string)
        freqArray[c - 'a']++;

    for (int i = 0; i < freqArray.size(); i++) // O(26)
    {
        if (freqArray[i] > 0)
            cout << (char)('a' + i) << " " << ":" << " " << freqArray[i] << endl;
    }
    return 0;
}
// O(length of string)