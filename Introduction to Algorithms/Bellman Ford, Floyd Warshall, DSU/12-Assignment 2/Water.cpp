#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        cin >> n;

        int array[n];
        for (int i = 0; i < n; i++)
            cin >> array[i];

        int maxWater = 0, left = 0, right = n - 1;
        pair<int, int> ans;

        while (left < right)
        {
            int currentWater = array[left] + array[right];
            if (currentWater > maxWater)
            {
                maxWater = currentWater;
                ans = {left, right};
            }

            if (array[left] < array[right])
                left++;
            else
                right--;
        }

        cout << ans.first << " " << ans.second << endl;
    }

    return 0;
}