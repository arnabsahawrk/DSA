// https://leetcode.com/problems/network-delay-time/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (auto arr : times)
        {
            int u = arr[0] - 1;
            int v = arr[1] - 1;
            int w = arr[2];

            adj[u].push_back({v, w});
        }

        vector<int> des(n, INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        des[k - 1] = 0;
        pq.push({des[k - 1], k - 1});

        while (!pq.empty())
        {
            auto p = pq.top();
            pq.pop();

            int p_des = p.first;
            int p_node = p.second;

            for (auto child : adj[p_node])
            {
                int c_des = child.second;
                int c_node = child.first;

                if (p_des + c_des < des[c_node])
                {
                    des[c_node] = p_des + c_des;
                    pq.push({des[c_node], c_node});
                }
            }
        }

        int result = *max_element(des.begin(), des.end());

        return (result == INT_MAX) ? -1 : result;
    }
};