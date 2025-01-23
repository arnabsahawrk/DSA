#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore();

    while (t--)
    {
        string str;
        getline(cin, str);

        stringstream ss(str);
        map<string, int> mp;

        string word;
        string countMe = "";
        int countInt = 0;
        while (ss >> word)
        {
            mp[word]++;

            if (mp[word] > countInt)
            {
                countMe = word;
                countInt = mp[word];
            }
        }

        cout << countMe << " " << countInt << endl;
    }

    return 0;
}