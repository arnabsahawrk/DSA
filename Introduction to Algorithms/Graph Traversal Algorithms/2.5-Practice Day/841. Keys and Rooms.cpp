// https://leetcode.com/problems/keys-and-rooms/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int len = rooms.size();
        vector<bool> visited(len, false);

        queue<int> q;
        q.push(0);
        visited[0] = true;

        while (!q.empty())
        {
            int parent = q.front();
            q.pop();

            for (int child : rooms[parent])
                if (!visited[child])
                {
                    q.push(child);
                    visited[child] = true;
                }
        }

        for (int i = 0; i < len; i++)
            if (!visited[i])
                return false;

        return true;
    }
};