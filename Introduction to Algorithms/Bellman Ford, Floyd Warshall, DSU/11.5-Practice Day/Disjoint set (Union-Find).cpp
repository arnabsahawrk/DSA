// https://www.geeksforgeeks.org/problems/disjoint-set-union-find/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
#include <bits/stdc++.h>
using namespace std;
int find(int a[], int x);
void unionSet(int a[], int x, int z);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n + 1];
        for (int i = 1; i <= n; i++)
            a[i] = i;
        int k;
        cin >> k;
        for (int i = 0; i < k; i++)
        {
            string s;
            cin >> s;
            if (s == "UNION")
            {
                int z, x;
                cin >> x >> z;
                unionSet(a, x, z);
            }
            else
            {
                int x;
                cin >> x;
                int parent = find(a, x);
                cout << parent << " ";
            }
        }
        cout << endl;

        cout << "~"
             << "\n";
    }
}

int find(int par[], int x)
{
    if (par[x] == x)
        return x;

    return par[x] = find(par, par[x]);
}

void unionSet(int par[], int x, int z)
{
    int parX = find(par, x);
    int parZ = find(par, z);

    par[parX] = parZ;
}