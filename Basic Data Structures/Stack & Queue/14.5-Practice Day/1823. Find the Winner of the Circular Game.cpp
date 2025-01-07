// https://leetcode.com/problems/find-the-winner-of-the-circular-game/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        queue<int> q;

        for (int i = 1; i <= n; i++)
            q.push(i);

        int count = 0;
        while (q.size() > 1)
        {
            count++;

            if (count == k)
            {
                count = 0;
                q.pop();
            }
            else
            {
                q.push(q.front());
                q.pop();
            }
        }

        return q.front();
    }
};