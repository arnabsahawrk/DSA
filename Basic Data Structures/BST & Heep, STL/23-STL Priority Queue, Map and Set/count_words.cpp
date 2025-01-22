#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    getline(cin, str);

    stringstream ss(str);
    map<string, int> mp;

    string word;
    while (ss >> word)
        mp[word]++;

    for (auto mapValue : mp)
        cout << mapValue.first << " " << mapValue.second << endl;
    return 0;
}