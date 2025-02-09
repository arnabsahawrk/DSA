//https://leetcode.com/problems/find-if-path-exists-in-graph/
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
            vector<vector<int>> adj_list(n);
            for(auto arr : edges){
                int firstValue = arr[0];
                int secondValue = arr[1];
    
                adj_list[firstValue].push_back(secondValue);
                adj_list[secondValue].push_back(firstValue);
            }
    
            vector<bool> visited(n, false);
            queue<int> q;
            q.push(source);
            visited[source] = true;
    
            while(!q.empty()){
                int p = q.front();
                q.pop();
    
                for(int x : adj_list[p]){
                    if(!visited[x]){
                        q.push(x);
                        visited[x] = true;
                    }
                }
            }
    
            return visited[destination];
        }
    };