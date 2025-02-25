// https://leetcode.com/problems/network-delay-time/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; i++)
            dist[i][i] = 0;

        for (auto it : times)
        {
            int u = it[0], v = it[1], w = it[2];
            u--, v--;
            dist[u][v] = w;
        }

        for (int h = 0; h < n; h++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (dist[i][h] != INT_MAX && dist[h][j] != INT_MAX)
                        dist[i][j] = min(dist[i][h] + dist[h][j], dist[i][j]);

        k--;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (dist[k][i] == INT_MAX)
                return -1;
            res = max(dist[k][i], res);
        }

        return res;
    }
};